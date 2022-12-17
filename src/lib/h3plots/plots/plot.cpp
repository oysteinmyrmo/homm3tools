#include "plot.h"

namespace h3plots::plot
{
void Plot::invalidate(const SaveFileSeries &series)
{
    invalidateAxes();

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

double Plot::minX() const
{
    return 1; // ASsume it all starts on day 1.
}

double Plot::maxX() const
{
    return static_cast<double>(xVals.back());
}

double Plot::minY() const
{
    return 0; // All data (so far) goes from 0 and upwards.
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
        invalidate(series);
        dataUpdated();
    }
}
void Plot::invalidateData()
{
    dataInvalidated = true;
}

void Plot::invalidateAxes()
{
    axesInvalidated = true;
}

bool Plot:: isDataInvalidated() const
{
    return dataInvalidated;
}

bool Plot:: isAxesInvalidated() const
{
    return axesInvalidated;
}

void Plot::axesUpdated()
{
    axesInvalidated = false;
}

void Plot::dataUpdated()
{
    dataInvalidated = false;
}

const SettingsVector& Plot::getSettings() const
{
    return settings;
}

SettingsVector& Plot::getSettings()
{
    return settings;
}

const AxisText &Plot::getAxisTexts() const
{
    return axisTexts;
}

const Players &Plot::getPlayers() const
{
    return players;
}

const std::vector<uint64_t> &Plot::getXValues() const
{
    return xVals;
}

const std::vector<uint64_t> &Plot::getYValues(const uint8_t idx) const
{
    return yVals[idx];
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
} // namespace h3plots::plot
