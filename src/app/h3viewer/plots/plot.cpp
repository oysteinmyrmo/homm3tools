#include "plot.h"

#include <imgui.h>
#include <implot.h>

namespace h3viewer::plot
{
void Plot::invalidate(const SaveFileSeries &series)
{
    axesInvalidated = true;

    players = series.players;
    xVals.clear();
    for (auto &vals : yVals)
    {
        vals.clear();
    }

    const uint64_t size = series.size();
    xVals.resize(size, 0);
    for (uint64_t i = 0; i < size; ++i)
    {
        xVals[i] = i + 1; // The x-values are simply the day from 1 through N.
    }
}

void Plot::drawPlotSpecifics()
{
}

double Plot::maxX() const
{
    return static_cast<double>(xVals.back());
}

double Plot::maxY() const
{
    uint64_t max = 0;
    for (size_t i = 0; i < h3::player::maxPlayers; ++i)
    {
        const auto &vals = yVals[i];
        const auto maxElement = std::max_element(vals.begin(), vals.end());
        const auto idx = std::distance(vals.begin(), maxElement);
        max = std::max(max, vals[idx]);
    }
    return double(max);
}

size_t Plot::size() const
{
    return xVals.size(); // Same size as number of files in the set.
}

void Plot::update(const SaveFileSeries &series)
{
    if (dataInvalidated)
    {
        dataInvalidated = false;
        invalidate(series);
    }
}

void Plot::drawSettings()
{
    for (auto &setting : settings)
    {
        if (std::holds_alternative<CheckBoxSetting>(setting))
        {
            auto &s = std::get<CheckBoxSetting>(setting);
            if (ImGui::Checkbox(s.text.c_str(), &s.checked))
            {
                dataInvalidated = true;
            }
        }
    }
}

void Plot::drawPlot()
{
    if (ImPlot::BeginPlot(axisTexts.header.c_str()))
    {
        ImPlot::SetupAxes(axisTexts.xText.c_str(), axisTexts.yText.c_str());
        if (axesInvalidated)
        {
            axesInvalidated = false;
            constexpr double padding = 1.0;
            ImPlot::SetupAxesLimits(1, maxX() + padding, 0, maxY() + padding, ImPlotCond_Always);
        }

        for (uint8_t i = 0; i < h3::player::maxPlayers; ++i)
        {
            const auto &player = players[i];
            if (player.active)
            {
                const auto &name = player.name;
                const auto &color = player.color;

                ImPlot::SetNextLineStyle(color);
                ImPlot::PlotLine(name.c_str(), xVals.data(), yVals[i].data(), int(size()));
            }
        }

        drawPlotSpecifics();
        ImPlot::EndPlot();
    }
}
} // namespace h3viewer::plot
