#include <iostream>
#include <ctime>
#include "HTP.hpp"

int main() {
	Person human = { human.alive = true, human.deplacement = false };

	Person wumpus = { wumpus.alive = true, wumpus.deplacement = false };


	int place[3][3] = { {1,2,3}, {4,5,6}, {7,8,9} }, lenPlace = 9, positionUser[2] = {0}, positionWumpus[2] = {0};

	AfficherMenu();

	AfficherSalles(place);

	RandomPlace(place, lenPlace, positionUser, positionWumpus);

	Game(place, human, wumpus, positionUser, positionWumpus);

	return 0;
}