#pragma once

#include <cstdint>
#include <span>
#include <string>
#include <type_traits>

namespace h3::values
{
template<typename T>
void skipVal(size_t &idx, const T &val)
{
    idx += sizeof(val);
}

template<typename T, size_t N>
void readArr(const std::span<const char> &data, size_t &idx, T (&val)[N])
{
    memcpy(val, &data[idx], sizeof(val));
    idx += sizeof(val);
}

template<typename T>
void readVal(const std::span<const char> &data, size_t &idx, T &val)
{
    T res = 0;
    for (size_t i = 0; i < sizeof(val); ++i)
    {
        res += (uint8_t(data[idx + i]) << (8 * i));
    }
    val = res;
    idx += sizeof(val);
}

template<typename T>
void readEnum(const std::span<const char> &data, size_t &idx, T &val)
{
    using U = typename std::underlying_type<T>::type;
    U U_val;
    readVal(data, idx, U_val);
    val = static_cast<T>(U_val);
}

template<typename T, size_t N>
void readEnumArr(const std::span<const char> &data, size_t &idx, T (&val)[N])
{
    for (size_t i = 0; i < N; ++i)
    {
        readEnum(data, idx, val[i]);
    }
}

void readStr(const std::span<const char> &data, size_t &idx, std::string &str, const size_t size);

template<typename T, typename ...T_members>
void readStruct(const std::span<const char> &data, size_t &idx, T &t, T_members... members)
{
    for (auto m : {members...})
    {
        readVal(data, idx, t.*m);
    }
}

template<typename T, size_t N, typename ...T_members>
void readStructArr(const std::span<const char> &data, size_t &idx, T (&vals)[N], T_members... members)
{
    for (size_t i = 0; i < N; ++i)
    {
        readStruct(data, idx, vals[i], members...);
    }
}
} // namespace h3::values
