#include "json_interface.h"

#include <h3plots/plots.h>

namespace
{
h3plots::SaveFileSeries gSaveFileSeries;
h3plots::Plots gPlots;
h3plots::json_interface::JsonInterface gInterface;
} // namespace

namespace h3plots::json_interface
{
std::string execute(const std::string &json)
{
    ExecuteOutput executeOutput;

    std::string functionOutput;
    JS::DefaultCallFunctionContext context(json.c_str(), json.size(), functionOutput);
    context.s_context.serializer.setOptions(JS::SerializerOptions::Compact);

    JS::Error error = context.callFunctions(gInterface);
    if (error == JS::Error::NoError)
    {
        if (context.execution_list.size())
        {
            for (const auto &item : context.execution_list)
            {
                if (item.error != JS::Error::NoError)
                {
                    std::string errorStr("Could not execute json function: ");
                    errorStr += json;
                    executeOutput.error = ErrorData{item.error, errorStr};
                }
            }
        }

        // Everything went ok.
        if (executeOutput.error.null)
        {
            std::vector<JS::JsonObject> outputObjects;
            JS::ParseContext outputContext(functionOutput);
            outputContext.parseTo(outputObjects);
            assert(outputObjects.size() == 1);
            executeOutput.output = outputObjects[0];
        }
    }
    else
    {
        executeOutput.error = ErrorData{.error = error, .description = context.parse_context.makeErrorString()};
    }

    return JS::serializeStruct(executeOutput, JS::SerializerOptions::Compact);
}

auto JsonInterface::initialize(const InitializeInput &input) -> InitializeOutput
{
    h3::SaveFile::Input saveFileInput{ .path = input.path };
    if (input.firstTownName.assigned)
    {
        saveFileInput.firstTownName = input.firstTownName.data;
    }
    if (input.numberOfTowns.assigned)
    {
        saveFileInput.numberOfTowns = input.numberOfTowns.data;
    }
    if (input.firstHeroName.assigned)
    {
        saveFileInput.firstHeroName = input.firstHeroName.data;
    }

    gSaveFileSeries = h3plots::read_savefiles(saveFileInput, input.players);
    gPlots.invalidate(gSaveFileSeries);

    return {};
}

std::shared_ptr<h3plots::plot::Plot> JsonInterface::getPlot(const GetPlotInput &input)
{
    const h3plots::PlotType type = static_cast<h3plots::PlotType>(input.plotType);
    return gPlots.getPlot(type);
}
} // namespace h3viewer::json_interface
