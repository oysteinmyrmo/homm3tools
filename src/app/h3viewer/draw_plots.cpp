#include "draw_plots.h"

#include <imgui.h>
#include <implot.h>

namespace
{
ImVec4 toImGuiColor(const std::array<uint8_t, 3> &color)
{
    return ImVec4{static_cast<float>(color[0]) / 255.0f,
        static_cast<float>(color[1]) / 255.0f,
        static_cast<float>(color[2]) / 255.0f,
        1.0f};
}
} // namespace

void h3viewer::draw::settings(std::unique_ptr<h3plots::plot::Plot> &plot)
{
    for (auto &setting : plot->getSettings())
    {
        if (std::holds_alternative<h3plots::CheckBoxSetting>(setting))
        {
            auto &s = std::get<h3plots::CheckBoxSetting>(setting);
            const std::string id = s.text + "##" + plot->uniqueString();
            if (ImGui::Checkbox(id.c_str(), &s.checked))
            {
                plot->invalidateData();
            }
        }
        else if (std::holds_alternative<h3plots::RadioButtonSetting>(setting))
        {
            auto &s = std::get<h3plots::RadioButtonSetting>(setting);
            for (int i = 0; i < s.settings.size(); ++i)
            {
                const auto &r = s.settings[i];
                const std::string id = r.text + "##" + plot->uniqueString();
                if (ImGui::RadioButton(id.c_str(), &s.selected, i))
                {
                    plot->invalidateData();
                }
//                ImGui::SameLine();
            }
        }
        else
        {
            assert(false);
        }
    }
}

void h3viewer::draw::plot(std::unique_ptr<h3plots::plot::Plot> &plot)
{
    const auto &axisTexts = plot->getAxisTexts();

    const std::string id = axisTexts.header + "##" + plot->uniqueString();
    if (ImPlot::BeginPlot(id.c_str()))
    {
        ImPlot::SetupAxes(axisTexts.xText.c_str(), axisTexts.yText.c_str());
        if (plot->isAxesInvalidated())
        {
            const double minX = plot->minX();
            const double maxX = plot->maxX();
            const double minY = plot->minY();
            const double maxY = plot->maxY();

            constexpr double padding = 1.0;
            ImPlot::SetupAxesLimits(minX, maxX + padding, minY, maxY + padding, ImPlotCond_Always);
            plot->axesUpdated();
        }

        const auto players = plot->getPlayers();
        const auto &xVals = plot->getXValues();
        const auto size = xVals.size();

        if (plot->showAsPercentageStackedAreaChart())
        {
            ImPlot::PushStyleVar(ImPlotStyleVar_FillAlpha, 1.0f);
        }

        for (uint8_t i = 0; i < h3::player::maxPlayers; ++i)
        {
            const auto &player = players[i];
            if (player.active)
            {
                const auto &yVals = plot->getYValues(i);
                const auto &name = player.name;
                const ImVec4 color = toImGuiColor(player.color);

                if (plot->showAsPercentageStackedAreaChart())
                {
                    ImPlot::SetNextFillStyle(color);
                    ImPlot::PlotShaded(name.c_str(), xVals.data(), yVals.data(), int(size));
                }
                else
                {
                    ImPlot::SetNextLineStyle(color);
                    ImPlot::PlotLine(name.c_str(), xVals.data(), yVals.data(), int(size));
                }
            }
        }

        if (plot->showAsPercentageStackedAreaChart())
        {
            ImPlot::PopStyleVar();
        }

        if (plot->showVanquishLines())
        {
            for (uint8_t i = 0; i < h3::player::maxPlayers; ++i)
            {
                const auto &player = players[i];
                if (player.active)
                {
                    const auto &name = player.name;
                    const ImVec4 color = toImGuiColor(player.color);

                    ImPlot::SetNextLineStyle(color);
                    ImPlot::PlotVLines("", &player.vanquishedDay, 1);
                }
            }
        }

        ImPlot::EndPlot();
    }
}

void h3viewer::draw::plotAndSettings(std::unique_ptr<h3plots::plot::Plot> &plot)
{
    ImGui::TableNextRow();
    ImGui::TableNextColumn();
    draw::settings(plot);
    ImGui::TableNextColumn();
    draw::plot(plot);
}
