#include <catch2/catch.hpp>
#include <test_data.h>

#include <h3plots/savefile_series.h>

#include <h3plots/plots.h>
#include <h3plots/plots/artifacts.h>
#include <h3plots/plots/best_creature.h>
#include <h3plots/plots/experience.h>
#include <h3plots/plots/gold.h>
#include <h3plots/plots/hero_count.h>
#include <h3plots/plots/kingdom_army_strength.h>
#include <h3plots/plots/resources.h>
#include <h3plots/plots/town_count.h>

#include <h3plots_json/json_interface.h>

#include <array>
#include <filesystem>
#include <memory>
#include <string>

namespace
{
struct JsonVersusCppPlotsTester
{
    JsonVersusCppPlotsTester(const std::filesystem::path &dir)
    {
        // Setup C++ interface.
        const auto savefileSeries = h3plots::read_savefiles({.path = dir});
        plots.invalidate(savefileSeries);

        // Setup JSON interface.
        h3plots::json_interface::CallInitialize callInitialize{ .initialize = { .path = dir.string() } };
        const auto initializeJson = JS::serializeStruct(callInitialize, JS::SerializerOptions::Compact);
        const auto outJson = h3plots::json_interface::execute(initializeJson);
        verifyJsonOutput(outJson);
    }

    h3plots::json_interface::ExecuteOutput verifyJsonOutput(const std::string &json)
    {
        h3plots::json_interface::ExecuteOutput output;
        JS::ParseContext context(json);
        context.parseTo(output);
        REQUIRE(output.error.null);
        REQUIRE(!output.output.null);
        return output;
    }

    template<h3plots::PlotType PlotTypeEnum, typename PlotType>
    std::shared_ptr<h3plots::plot::Plot> getJsonPlot()
    {
        const int plotTypeIntegral = static_cast<int>(PlotTypeEnum);
        h3plots::json_interface::CallGetPlot callGetPlot{ .getPlot = { .plotType = plotTypeIntegral } };
        const auto outJson = h3plots::json_interface::execute(JS::serializeStruct(callGetPlot));
        const auto output = verifyJsonOutput(outJson);

        auto jsonPlotType = std::make_shared<PlotType>();
        auto jsonPlotBase = std::static_pointer_cast<h3plots::plot::Plot>(jsonPlotType);

        JS::ParseContext context(output.output.data.data);
        context.allow_unnasigned_required_members = false;
        context.allow_missing_members = false;
        JS::Error error = context.parseTo(*jsonPlotBase);
        REQUIRE(error == JS::Error::NoError);

        return jsonPlotBase;
    }

    template<h3plots::PlotType PlotTypeEnum, typename PlotType>
    void requireJsonAndCppPlotsEqual()
    {
        const auto &plotFromCppInterface = plots.getPlot(PlotTypeEnum);
        const auto plotFromJsonInterface = getJsonPlot<PlotTypeEnum, PlotType>();

        const auto cppPlot = std::static_pointer_cast<PlotType>(plotFromCppInterface);
        const auto jsonPlot = std::static_pointer_cast<PlotType>(plotFromJsonInterface);

        REQUIRE(cppPlot->players   == jsonPlot->players);
        REQUIRE(cppPlot->settings  == jsonPlot->settings);
        REQUIRE(cppPlot->axisTexts == jsonPlot->axisTexts);
        REQUIRE(cppPlot->xVals     == jsonPlot->xVals);
        REQUIRE(cppPlot->yVals     == jsonPlot->yVals);
    }

    void requireAllPlotsEqual()
    {
        const int plotCount = static_cast<int>(h3plots::PlotType::COUNT);
        int plotType = 0;
        while (plotType < plotCount)
        {
            const auto plotTypeEnum = static_cast<h3plots::PlotType>(plotType);
            switch (plotTypeEnum) {
                case h3plots::PlotType::KingdomArmyStrength:
                    requireJsonAndCppPlotsEqual<h3plots::PlotType::KingdomArmyStrength, h3plots::plot::KingdomArmyStrengthPlot>();
                    break;
                case h3plots::PlotType::BestCreature:
                    requireJsonAndCppPlotsEqual<h3plots::PlotType::BestCreature, h3plots::plot::BestCreaturePlot>();
                    break;
                case h3plots::PlotType::Heroes:
                    requireJsonAndCppPlotsEqual<h3plots::PlotType::Heroes, h3plots::plot::HeroesPlot>();
                    break;
                case h3plots::PlotType::Artifacts:
                    requireJsonAndCppPlotsEqual<h3plots::PlotType::Artifacts, h3plots::plot::ArtifactsPlot>();
                    break;
                case h3plots::PlotType::Experience:
                    requireJsonAndCppPlotsEqual<h3plots::PlotType::Experience, h3plots::plot::ExperiencePlot>();
                    break;
                case h3plots::PlotType::Gold:
                    requireJsonAndCppPlotsEqual<h3plots::PlotType::Gold, h3plots::plot::GoldPlot>();
                    break;
                case h3plots::PlotType::Resources:
                    requireJsonAndCppPlotsEqual<h3plots::PlotType::Resources, h3plots::plot::ResourcesPlot>();
                    break;
                case h3plots::PlotType::Towns:
                    requireJsonAndCppPlotsEqual<h3plots::PlotType::Towns, h3plots::plot::TownsPlot>();
                    break;
                default:
                    CHECK(false);
            }
            ++plotType;
        }
    }

    h3plots::Plots plots;
};
} // namespace

TEST_CASE("test-all-json-and-cpp-plots-equal", "[plot][json][json-interface]")
{
    const std::array testDirs{
        std::string{"artifacts"},
        std::string{"creatures"},
        std::string{"experience"},
        std::string{"hero_player"},
        std::string{"hero_town"},
        std::string{"kingdom_army_strength"},
        std::string{"movement"},
        std::string{"movement_gigantic"},
        std::string{"primary_skills"},
        std::string{"prison"},
        std::string{"resources"},
        std::string{"savefile"},
        std::string{"secondary_skills"},
        std::string{"spells"},
        std::string{"spell_points"},
        std::string{"towns"},
        std::string{"town_names"},
    };

    for (const auto &dir : testDirs)
    {
        JsonVersusCppPlotsTester tester({h3::test::testDataDir / dir});
        tester.requireAllPlotsEqual();
    }
}
