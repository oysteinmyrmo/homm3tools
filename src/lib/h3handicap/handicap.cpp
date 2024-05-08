#include "handicap.h"

#include <algorithm>
#include <cassert>
#include <numeric>
#include <tuple>

using h3handicap::PlayerHandicaps;
using h3handicap::GameInput;

namespace
{
int numberOfPlayers(const PlayerHandicaps& handicaps)
{
    return std::accumulate(handicaps.begin(), handicaps.end(), 0,
        [](int count, const auto& player) {
            return count + (player.enabled ? 1 : 0);
        });
}

double advantage(const double handicap)
{
    return 1.0 - handicap;
}

double sumHandicaps(const PlayerHandicaps &handicaps)
{
    return std::accumulate(handicaps.begin(), handicaps.end(), 0.0,
        [](double sum, const auto& player) {
            return sum + (player.enabled ? player.handicap : 0.0);
        });
}

// Every player keeps 500 gold for marketplace and 2500 to an extra hero, so 3000 in total.
int subtractGoldToKeep(const int startGold)
{
    return startGold - 3000;
}

// Handicap pool is the total amount that should be distributed due to handicaps.
int calculateHandicapPool(const double handicapSum, const int goldToPoolPerPlayer)
{
    return int(handicapSum * goldToPoolPerPlayer);
}

int calculateStartGold(const int playerCount,
                       const int handicapPool,
                       const int goldToPoolPerPlayer,
                       const double handicap,
                       const double handicapSum)
{
    const double adv = advantage(handicap);
    const double handicapFactor = (adv + (handicapSum - handicap) / (playerCount - 1)) / playerCount;

    const int handicapGold = int(handicapPool * handicapFactor);
    const int remainder = adv * goldToPoolPerPlayer;

    return remainder + handicapGold;

}
} // namespace

void h3handicap::calculateDebt(const GameInput &input)
{
    const auto handicapSum = sumHandicaps(input.handicaps);
    const auto playerCount = numberOfPlayers(input.handicaps);

    const auto incomeForDifficulty = h3::difficulty::incomeForDifficulties.at(input.difficulty);
    const auto goldToPoolPerPlayer = subtractGoldToKeep(incomeForDifficulty.gold); // Note: Really poor variable name!

    const auto hcPool =  calculateHandicapPool(handicapSum, goldToPoolPerPlayer);


    for (const auto& player : input.handicaps)
    {
        if (player.enabled)
        {
            const int foo = calculateStartGold(playerCount, hcPool, goldToPoolPerPlayer, player.handicap, handicapSum);
            printf("foo = %d\n", foo);
        }
    }
}