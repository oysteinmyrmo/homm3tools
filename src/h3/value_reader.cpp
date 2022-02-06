#include "value_reader.h"

namespace h3::values
{
void readVal(const std::span<const char> &data, size_t &idx, uint8_t &val)
{
    val = data[idx];
    idx += sizeof(val);
}

void readVal(const std::span<const char> &data, size_t &idx, uint16_t &val)
{
    val = (uint8_t(data[idx + 0]) << 0)
        + (uint8_t(data[idx + 1]) << 8);
    idx += sizeof(val);
}

void readVal(const std::span<const char> &data, size_t &idx, uint32_t &val)
{
    val = (data[idx] << 24) + (data[idx + 1] << 16) + (data[idx + 2] << 8) + data[idx + 3];
    idx += sizeof(val);
}
} // namespace h3::values
