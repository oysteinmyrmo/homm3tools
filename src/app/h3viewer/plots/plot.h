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

    struct CheckBoxSetting : Setting
    {
        bool checked = false;
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
        virtual void drawPlotSpecifics();

        void update(const SaveFileSeries &series);
        void drawSettings();
        void drawPlot();

        double maxX() const;
        double maxY() const;
        size_t size() const;

    protected:
        Players players;
        std::vector<std::variant<Setting, CheckBoxSetting>> settings;
        AxisText axisTexts;
        std::vector<uint64_t> xVals; // Days from 1 through N.
        std::array<std::vector<uint64_t>, h3::player::maxPlayers> yVals;

        bool dataInvalidated = true;
        bool axesInvalidated = true;
    };
};
