
#include <iostream>
using namespace std;

enum difficulty : int
{
	easy = 0,
	normal,
	hard,
	expert,
	impossible
};

// note values include reduction of 2.5k gold for a hero and 500 gold + 5 wood for marketplace
double startGold[5] = {27000.0, 17000.0, 12000.0, 7000.0, 0.0};
double startNormalResource[5] = {55.0, 35.0, 25.0, 15.0, 0.0};
double startMagicResource[5] = {60.0, 40.0, 28.0, 16.0, 0.0};

int main(int argc, char* argv[])
{
	int difficulty = -1;
	cout << "difficulty level? (number 1-4 for easy-expert)\n";
	cin >> difficulty;
	
	if (difficulty < 1 || difficulty > 4)
	{
		cout << "Error: Invalid difficulty.\n";
		return 0;
	}
	difficulty -= 1;

	int nPlayers = -1;
	cout << "How many players?\n";
	cin >> nPlayers;

	if (nPlayers < 2 || nPlayers > 8)
	{
		cout << "Error: Invalid player count.\n";
		return 0;
	}

	double advantage[8] = { -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0,};
	for (int i=0; i < nPlayers; i++)
	{
		double handicap = -1.0;
		cout << "enter handicap for player " << i+1 << " (0.0 - 1.0)\n";
		cin >> handicap;
		
		if (handicap < 0.0 || handicap > 1.0)
		{
			cout << "Error: Invalid handicap value.\n";
			return 0;
		}
		advantage[i] = 1.0 - handicap;
	}
	
	double advantageTotal = 0.0;
	for (int i=0; i < nPlayers; i++)
		advantageTotal += advantage[i];

	while(1)
	{
		int player = -1;
		cout << "Enter player# (1-" << nPlayers << ") to print handicap resource transfer amounts:\n";
		cin >> player;
		
		if (player < 1 || player > nPlayers)
		{
			cout << "Error: Invalid player index.\n";
			return 0;
		}

		cout << "\nplayer " << player << " should...\n";

		double normalisedAdvantageThisPlayer = advantage[player-1] / advantageTotal;

		for (int i=0; i < nPlayers; i++)
		{
			if (i == player-1)
				continue;

			double normalisedAdvantageOtherPlayer = advantage[i] / advantageTotal;
			double relativeAdvantageOtherPlayer = normalisedAdvantageOtherPlayer - normalisedAdvantageThisPlayer;
			if (relativeAdvantageOtherPlayer > 0.0)
			{
				cout << "\n";
				cout << "send player " << i+1 << ":\n";
				cout << "    " << (int)(startGold[difficulty] * relativeAdvantageOtherPlayer) << " gold\n";
				cout << "    " << (int)(startNormalResource[difficulty] * relativeAdvantageOtherPlayer) << " normal resource\n";
				cout << "    " << (int)(startMagicResource[difficulty] * relativeAdvantageOtherPlayer) << " magic resource\n";
			}
			else
			{
				cout << "\n";
				cout << "send player " << i+1 << " nothing.\n";
			}
		}
		cout << "\n";
	}
}