#include "value_reader.h"

namespace h3::values
{
void readStr(const std::span<const char> &data, size_t &idx, std::string &str, const size_t size)
{
    str = std::string(&data[idx], size);
    idx += size;
}
} // namespace h3::values
