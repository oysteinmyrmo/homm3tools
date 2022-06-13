#pragma once

#include <h3viewer/savefile_series.h>
#include <h3viewer/player.h>

#include <array>
#include <cstdint>
#include <string>
#include <variant>
#include <vector>

namespace h3viewer::plot
{
    struct Setting
    {
        std::string text;
        bool enabled = true;
    };

    // Simply draws an ImGui::Separator().
    struct SettingSeparator : Setting
    {
    };

    struct CheckBoxSetting : Setting
    {
        bool checked = false;
    };

    struct RadioButtonSetting : Setting
    {
        struct RadioSetting
        {
            std::string text;
            bool newline = false;
        };

        std::vector<RadioSetting> settings;
        int selected = 0;
    };

    struct AxisText
    {
        std::string header;
        std::string xText;
        std::string yText;
    };

    class Plot
    {
    public:
        Plot() = default;

        virtual void invalidate(const SaveFileSeries &series);
        virtual void drawPlotSpecifics() = 0;
        virtual bool showAsPercentageStackedAreaChart() const = 0;

        double maxX() const;
        double maxY() const;
        size_t size() const;

        void update(const SaveFileSeries &series);
        void drawSettings();
        void drawPlot();

    protected:
        void alterDataToChartType();
        void setupPercentageStackedAreaChart();

        Players players;
        std::vector<std::variant<Setting, SettingSeparator, CheckBoxSetting, RadioButtonSetting>> settings;
        AxisText axisTexts;
        std::vector<uint64_t> xVals; // Days from 1 through N.
        std::array<std::vector<uint64_t>, h3::player::maxPlayers> yVals;

        bool dataInvalidated = true;
        bool axesInvalidated = true;
    };
};
