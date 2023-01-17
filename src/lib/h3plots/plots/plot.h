#pragma once
#include "../savefile_series.h"
#include "../settings.h"
#include "../player.h"

#include <array>
#include <cstdint>
#include <string>
#include <typeinfo>
#include <variant>
#include <vector>

namespace h3plots::plot
{
    struct AxisText
    {
        bool operator==(const AxisText&) const = default;

        std::string header;
        std::string xText;
        std::string yText;
    };

    struct Plot
    {
        Plot() = default;
        Plot(const Plot&) = default;
        virtual ~Plot() = default;

        // This is needed for some plot libraries, e.g. ImGui/ImPlot.
        virtual std::string uniqueString() const = 0;

        virtual void invalidate(const h3plots::SaveFileSeries &series);
        virtual bool showAsPercentageStackedAreaChart() const = 0;
        virtual bool showVanquishLines() const = 0;

        double minX() const;
        double maxX() const;
        double minY() const;
        double maxY() const;
        size_t size() const;

        void update(const SaveFileSeries &series);

        void invalidateData();
        void invalidateAxes();
        bool isDataInvalidated() const;
        bool isAxesInvalidated() const;
        void axesUpdated();
        void dataUpdated();

        const SettingsVector &getSettings() const;
        SettingsVector &getSettings();
        const AxisText &getAxisTexts() const;
        const Players &getPlayers() const;

        const std::vector<uint64_t> &getXValues() const;
        const std::vector<uint64_t> &getYValues(uint8_t idx) const;

        void alterDataToChartType();
        void setupPercentageStackedAreaChart();

        // Note: Public because the JSON interface needs them to be.
        Players players;
        SettingsVector settings;
        AxisText axisTexts;
        std::vector<uint64_t> xVals; // Days from 1 through N.
        std::array<std::vector<uint64_t>, h3::player::maxPlayers> yVals;

    protected:
        bool dataInvalidated = true;
        bool axesInvalidated = true;
    };
} // namespace h3plots::plot
