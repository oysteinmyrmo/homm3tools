#pragma once
#include <json_struct/json_struct.h>

#include <h3plots/plots/kingdom_army_strength.h>
#include <h3plots/player.h>
#include <h3plots/plots.h>
#include <h3plots/settings.h>

#include <array>
#include <memory>
#include <string>
#include <variant>
#include <vector>

namespace JS
{
template<typename T, size_t size>
struct TypeHandler<std::array<T, size>>
{
public:
    static inline Error to(std::array<T, size> &arr, ParseContext &context)
    {
        if (context.token.value_type != JS::Type::ArrayStart)
            return Error::ExpectedArrayStart;
        Error error = context.nextToken();
        if (error != JS::Error::NoError)
            return error;
        size_t idx = 0;
        while (context.token.value_type != JS::Type::ArrayEnd)
        {
            if (idx >= size)
                return Error::ExpectedArrayEnd;
            arr[idx] = T();
            error = TypeHandler<T>::to(arr[idx], context);

            if (error != JS::Error::NoError)
                break;
            error = context.nextToken();
            if (error != JS::Error::NoError)
                break;
            ++idx;
        }

        return error;
    }

    static void from(const std::array<T, size> &arr, Token &token, Serializer &serializer)
    {
        token.value_type = Type::ArrayStart;
        token.value = DataRef("[");
        serializer.write(token);

        token.name = DataRef("");

        for (auto &item : arr)
        {
            TypeHandler<T>::from(item, token, serializer);
        }

        token.name = DataRef("");

        token.value_type = Type::ArrayEnd;
        token.value = DataRef("]");
        serializer.write(token);
    }
};

template<>
struct TypeHandler<h3plots::SettingsVariant>
{
public:
    static inline Error to(h3plots::SettingsVariant &to, ParseContext &context)
    {
        JsonObject obj;
        Error error = TypeHandler<JsonObject>::to(obj, context);

        ParseContext dummyContext(obj.data);
        h3plots::NoneSetting dummySetting;
        dummyContext.parseTo(dummySetting);

        if (error == Error::NoError)
        {
            const int settingType = dummySetting.type;
            if (settingType == h3plots::SettingTypes::CheckBox)
            {
                ParseContext settingContext(obj.data);
                h3plots::CheckBoxSetting setting;
                error = settingContext.parseTo(setting);
                if (error == Error::NoError)
                {
                    to = setting;
                }
                return error;
            }
            if (settingType == h3plots::SettingTypes::RadioButton)
            {
                ParseContext settingContext(obj.data);
                h3plots::RadioButtonSetting setting;
                error = settingContext.parseTo(setting);
                if (error == Error::NoError)
                {
                    to = setting;
                }
                return error;
            }
        }

        return Error::UserDefinedErrors;
    }

    static void from(const h3plots::SettingsVariant &from, Token &token, Serializer &serializer)
    {
        if (std::holds_alternative<h3plots::CheckBoxSetting>(from))
        {
            const auto &s = std::get<h3plots::CheckBoxSetting>(from);
            TypeHandler<h3plots::CheckBoxSetting>::from(s, token, serializer);
        }
        else if (std::holds_alternative<h3plots::RadioButtonSetting>(from))
        {
            const auto &s = std::get<h3plots::RadioButtonSetting>(from);
            TypeHandler<h3plots::RadioButtonSetting>::from(s, token, serializer);
        }
    }
};
}

JS_OBJ_EXT(h3plots::Player, name, color, vanquishedDay, active);
JS_OBJ_EXT(h3plots::plot::AxisText, header, xText, yText);
JS_OBJ_EXT(h3plots::NoneSetting, text, enabled, type);
JS_OBJ_EXT(h3plots::CheckBoxSetting, text, enabled, type, checked);
JS_OBJ_EXT(h3plots::RadioButtonSetting::RadioSetting, text);
JS_OBJ_EXT(h3plots::RadioButtonSetting, text, enabled, type, settings, selected);
JS_OBJ_EXT(h3plots::plot::Plot, players, settings, axisTexts, xVals, yVals);

namespace h3plots::json_interface
{
struct ErrorData
{
    JS::Error error = JS::Error::NoError;
    std::string description;
    JS_OBJ(error, description);
};

struct ExecuteOutput
{
    JS::NullableChecked<ErrorData> error;
    JS::NullableChecked<JS::JsonObject> output;
    JS_OBJ(error, output);
};

std::string execute(const std::string &json);

struct InitializeInput
{
    std::string path;
    JS::OptionalChecked<std::string> firstTownName;
    JS::OptionalChecked<size_t> numberOfTowns;
    JS::OptionalChecked<std::string> firstHeroName;
    Players players = h3plots::defaultPlayers();
    JS_OBJ(path, firstTownName, numberOfTowns, firstHeroName, players);
};

struct InitializeOutput
{
    JS::NullableChecked<std::string> error;
    JS_OBJ(error);
};

struct CallInitialize
{
    InitializeInput initialize;
    JS_OBJ(initialize);
};

struct GetPlotInput
{
    int plotType; // Must be one of h3plots::Plots enum types.
    JS_OBJ(plotType);
};

using GetPlotOutput = std::shared_ptr<h3plots::plot::Plot>;

struct CallGetPlot
{
    GetPlotInput getPlot;
    JS_OBJ(getPlot);
};

struct JsonInterface
{
    auto initialize(const InitializeInput &input) -> InitializeOutput;
    auto getPlot(const GetPlotInput &input) -> GetPlotOutput;

    JS_FUNC_OBJ(initialize, getPlot);
};
}
