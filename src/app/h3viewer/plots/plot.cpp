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
        else if (std::holds_alternative<RadioButtonSetting>(setting))
        {
            auto &s = std::get<RadioButtonSetting>(setting);
            for (int i = 0; i < s.settings.size(); ++i)
            {
                const auto &r = s.settings[i];
                if (ImGui::RadioButton(r.text.c_str(), &s.selected, i))
                {
                    dataInvalidated = true;
                }
                if (!r.newline)
                {
                    ImGui::SameLine();
                }
            }
        }
        else if (std::holds_alternative<SettingSeparator>(setting))
        {
            ImGui::Separator();
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

        if (showAsPercentageStackedAreaChart())
        {
            ImPlot::PushStyleVar(ImPlotStyleVar_FillAlpha, 1.0f);

            for (uint8_t i = 0; i < h3::player::maxPlayers; ++i)
            {
                const auto &player = players[i];
                if (player.active)
                {
                    const auto &name = player.name;
                    const auto &color = player.color;

                    ImPlot::SetNextFillStyle(color);
                    ImPlot::PlotShaded(name.c_str(), xVals.data(), yVals[i].data(), int(size()));
                }
            }

            ImPlot::PopStyleVar();
        }
        else
        {
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
        }

        drawPlotSpecifics();
        ImPlot::EndPlot();
    }
}

void Plot::alterDataToChartType()
{
    if (showAsPercentageStackedAreaChart())
    {
        setupPercentageStackedAreaChart();
    }
}

// Manipulate the data to present it as a percentage stacked area chart.
void Plot::setupPercentageStackedAreaChart()
{
    for (size_t i = 0; i < size(); ++i)
    {
        double sum = 0;
        for (size_t j = 0; j < h3::player::maxPlayers; ++j)
        {
            sum += double(yVals[j][i]);
        }

        double accumulatedPct = 0;

        // Setup values backwards to get correct draw order when plotting.
        for (int8_t j = h3::player::maxPlayers - 1; j >= 0; --j)
        {
            accumulatedPct += double(yVals[j][i]) / sum * 100.0;
            const auto val = uint64_t(std::lround(accumulatedPct));
            yVals[j][i] = val;
        }
    }
}
} // namespace h3viewer::plot
