#pragma once
#include <string>
#include <variant>
#include <vector>

namespace h3plots
{
namespace SettingTypes
{
constexpr int None = 0;
constexpr int CheckBox = 1;
constexpr int RadioButton = 2;
} // namespace SettingTypes

template <int Type>
struct Setting
{
    bool operator==(const Setting&) const = default;

    std::string text;
    bool enabled = true;
    int type = Type;
};

struct NoneSetting : Setting<SettingTypes::None>
{};

struct CheckBoxSetting : Setting<SettingTypes::CheckBox>
{
    bool operator==(const CheckBoxSetting&) const = default;
    bool checked = false;
};

struct RadioButtonSetting : Setting<SettingTypes::RadioButton>
{
    struct RadioSetting
    {
        bool operator==(const RadioSetting&) const = default;
        std::string text;
    };

    bool operator==(const RadioButtonSetting&) const = default;

    std::vector<RadioSetting> settings;
    int selected = 0;
};

using SettingsVariant = std::variant<CheckBoxSetting, RadioButtonSetting>;
using SettingsVector = std::vector<SettingsVariant>;
} // namespace h3plots
