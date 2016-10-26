// Smash_Up.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#define MAX_FACTION_NAME_LENGTH 50
#define PATH_TO_FACTIONS "..\\Data\\Factions.txt"

std::vector<std::string> initializeFactionsInPlay(std::string);
std::string selectGameFaction(std::vector<std::string>);
std::string convertToLowercase(std::string);

int main()
{
	auto FactionsInPlay = initializeFactionsInPlay(PATH_TO_FACTIONS);
	auto PlayersFaction = selectGameFaction(FactionsInPlay);

    return 0;
}

// This function reads the faction names from the input file, and stores them in a vector
std::vector<std::string> initializeFactionsInPlay(std::string factionsFileLocation)
{
	std::vector<std::string> FactionsInPlay;
	char buffOfFactions[MAX_FACTION_NAME_LENGTH];

	std::ifstream factionsInGame(factionsFileLocation);

	while (factionsInGame.getline(buffOfFactions, MAX_FACTION_NAME_LENGTH)) {
		FactionsInPlay.push_back(buffOfFactions);
	}

	factionsInGame.close();
	return FactionsInPlay;
}

// This function ask a player to choose a faction to play
std::string selectGameFaction(std::vector<std::string> FactionsInPlay)
{
	bool factionIsChosen = false;
	char playersBuffer[MAX_FACTION_NAME_LENGTH];
	std::string playersFaction;

	while (!factionIsChosen) {
		std::cout << "Choose a faction to play:" << std::endl;
		std::cin >> playersFaction;

		playersFaction = convertToLowercase(playersFaction);

		for (int i = 0; i < FactionsInPlay.size(); i++) {
			if (playersFaction == FactionsInPlay[i]) {
				std::cout << "succeed" << std::endl;
				factionIsChosen = true;
			}
		}
	}
	return playersFaction;
}

std::string convertToLowercase(std::string word) {
	std::locale loc;
	for (int i = 0; i < word.length(); ++i) {
		word[i] = std::tolower(word[i], loc);
	}
	return word;
}