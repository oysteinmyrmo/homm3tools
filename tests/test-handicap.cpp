#include <catch2/catch.hpp>

#include <h3handicap/handicap.h>

TEST_CASE("h3handicap1", "[handicap]")
{
    h3handicap::GameInput gameInput{
        {
            {
                {.handicap = 0.8, .enabled = true},
                {.handicap = 1.0, .enabled = true},
            }
        },
        h3::difficulty::Difficulty::Expert
    };

    printf("------h3handicap1!\n");
    h3handicap::calculateDebt(gameInput);
}

TEST_CASE("h3handicap2", "[handicap]")
{
    h3handicap::GameInput gameInput{
        {
            {
                {.handicap = 0.4, .enabled = true},
                {.handicap = 0.8, .enabled = true},
                {.handicap = 1.0, .enabled = true},
            }
        },
        h3::difficulty::Difficulty::Expert
    };

    printf("------h3handicap2!\n");
    h3handicap::calculateDebt(gameInput);
}

TEST_CASE("h3handicap3", "[handicap]")
{
    h3handicap::GameInput gameInput{
        {
            {
                {.handicap = 0.8, .enabled = true},
                {.handicap = 1.0, .enabled = true},
                {.handicap = 0.0, .enabled = true},
            }
        },
        h3::difficulty::Difficulty::Expert
    };

    printf("------h3handicap3!\n");
    h3handicap::calculateDebt(gameInput);
}