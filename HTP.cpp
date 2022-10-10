#include <iostream>
#include <ctime>
#include "HTP.hpp"

void AfficherMenu() {
	std::string list[10] = { "            Bienvenue dans le jeu du wumpus !", "    Les regles:",
	"    1. Vous demarrez dans une salle aleatoire, tout comme le wumpus",
	"    2. Vous ne pouvez que vous deplacer de salle en salle a la verticale ou a l'horizontale",
	"    3. Vous pouvez vous deplacer de l'autre cote de la place si vous etes a",
	"       l'extremite de la place (exemple : salle 6 -> salle 7)",
	"    4. Vous ne savez pas ou le wumpus se situe", "    5. Vous devez le deviner et tirer une fleche avant qu'il ne vous tue",
	"    5. Faites attention, vous n'avez qu'une chance, si vous la ratez, vous etes mort..",
	"    6. les salles sont dans l'ordre qui suit : " };
	
	for (auto &i : list) {
		std::cout << i << std::endl;
	}
}

void AfficherSalles(int place[][3]) {
	for (int i = 0; i < 3; ++i) {
		std::cout << "              ";
		for (int j = 0; j < 3; ++j) {
			std::cout << "    " << place[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void RandomPlace(int place[][3], int lenPlace, int posUser[], int posWumpus[]) {
	srand(time(NULL));

	int startUserx = 1, startUsery = 1;
	int startWumpusx = 1, startWumpusy = 1;

	while (startUserx == startWumpusx && startUsery == startWumpusy) {
		startUserx = rand() % 3;
		startUsery = rand() % 3;

		startWumpusx = rand() % 3;
		startWumpusy = rand() % 3;
	}

	posUser[0] = startUserx;
	posUser[1] = startUsery;

	posWumpus[0] = startWumpusx;
	posWumpus[1] = startWumpusy;

	std::cout << "-------------------------------------------------------------------------------------------" << std::endl;

	std::cout << "                 Vous demarrez donc dans la salle " << place[posUser[0]][posUser[1]] << "." << std::endl;
	std::cout << std::endl;
}

bool Perdu(int place[][3], Person human, Person wumpus, int posUser[], int posWumpus[]) {
	if (place[posUser[0]][posUser[1]] == place[posWumpus[0]][posWumpus[1]]) {
		human.alive = false;
		std::cout << "vous avez perdu !\n" << std::endl;
		std::cout << "\n le wumpus était dans la salle " << place[posWumpus[0]][posWumpus[1]] << std::endl;
	}

	return human.alive;
}

void Deplacement(int place[][3], int choixSalle, int choixTir, int posUser[]) {
	std::cout << "dans quelle salle voulez vous vous deplacer ? : ";
	std::cin >> choixSalle;
	if (choixSalle == place[posUser[0]][posUser[1] + 1] && posUser[1] != 2) {
		std::cout << "vous etes maintenant dans la salle " << choixSalle << "." << std::endl;
		posUser[1]++;
	}
	else if (choixSalle == place[posUser[0] + 1][posUser[1]]) {
		std::cout << "vous etes maintenant dans la salle " << choixSalle << "." << std::endl;
		posUser[0]++;
	}
	else if (choixSalle == place[posUser[0] - 1][posUser[1]]) {
		std::cout << "vous etes maintenant dans la salle " << choixSalle << "." << std::endl;
		posUser[0]--;
	}
	else if (choixSalle == place[posUser[0]][posUser[1] - 1] && posUser[1] != 0) {
		std::cout << "vous etes maintenant dans la salle " << choixSalle << "." << std::endl;
		posUser[1]--;
	}
	else if (choixSalle == place[posUser[0]][posUser[1]])
		std::cout << "vous etes deja dans cette salle, reessayez" << std::endl;
	else {
		std::cout << "vous ne pouvez pas acceder a cette salle, reessayez : " << std::endl;
	}

	std::cout << "vous etes donc dans la salle " << place[posUser[0]][posUser[1]] << std::endl;
}

bool Tir(int place[][3], int posUser[], int posWumpus[], int& choixSalle, int& choixTir, Person human, Person wumpus) {
	std::cout << "dans quelle salle voulez vous tirer ? : ";
	std::cin >> choixTir;
	if (choixTir == place[posUser[0]][posUser[1]] + 1 && choixSalle < 10) {
		std::cout << "   vous avez tirer dans la salle " << choixTir << "." << std::endl;
		if (choixTir == place[posWumpus[0]][posWumpus[1]]) {
			wumpus.alive = false;
			std::cout << "Victoire !" << std::endl;
		}
		else {
			human.alive = false;
			std::cout << "vous avez perdu !" << std::endl
			<< "le wumpus etait dans la salle " << place[posWumpus[0]][posWumpus[1]] << std::endl;
		}
	}
	else if (choixTir == place[posUser[0]][posUser[1]] - 1 && choixSalle > 0) {
		std::cout << "vous avez tirer dans la salle " << choixTir << "." << std::endl;
		if (choixTir == place[posWumpus[0]][posWumpus[1]]) {
			wumpus.alive = false;
			std::cout << "victoire !" << std::endl;
		}
		else {
			human.alive = false;
			std::cout << "vous avez perdu !" << std::endl
			<< "le wumpus etait dans la salle " << place[posWumpus[0]][posWumpus[1]] << std::endl;
		}
	}
	else if (choixTir == place[posUser[0]][posUser[1]] + 3) {
		std::cout << "vous avez tirer dans la salle " << choixTir << "." << std::endl;
		if (choixTir == place[posWumpus[0]][posWumpus[1]]) {
			wumpus.alive = false;
			std::cout << "victoire !" << std::endl;
		}
		else {
			human.alive = false;
			std::cout << "vous avez perdu !" << std::endl
			 << "le wumpus etait dans la salle " << place[posWumpus[0]][posWumpus[1]] << "." << std::endl;
		}
	}
	else if (choixTir == place[posUser[0]][posUser[1]] - 3) {
		std::cout << "vous avez tirer dans la salle " << choixTir << "." << std::endl;
		if (choixTir == place[posWumpus[0]][posWumpus[1]]) {
			wumpus.alive = false;
			std::cout << "victoire !" << std::endl;
		}
		else {
			human.alive = false;
			std::cout << "vous avez perdu !" << std::endl;
			std::cout << "le wumpus etait dans la salle " << place[posWumpus[0]][posWumpus[1]] << std::endl;
		}
	}
	else if (choixTir == place[posUser[0]][posUser[1]])
		std::cout << "vous ne pouvez pas tirer dans votre propre salle, reessayez" << std::endl;
	else {
		std::cout << "vous ne pouvez pas tirer dans cette salle, reessayez : " << std::endl;
	}

	if (human.alive == false)
		return human.alive;
	else if (wumpus.alive == false)
		return wumpus.alive;

	return 1;
}

bool isWumpusProche(int place[][3], int posUser[], int posWumpus[]) {
	return place[posUser[0]][posUser[1]] == place[posWumpus[0] + 1][posWumpus[1]] ||
		place[posUser[0]][posUser[1]] == place[posWumpus[0] - 1][posWumpus[1]] ||
		(place[posUser[0]][posUser[1]] == place[posWumpus[0]][posWumpus[1] + 1] && posWumpus[1] != 2) ||
		(place[posUser[0]][posUser[1]] == place[posWumpus[0]][posWumpus[1] - 1] && posWumpus[1] != 0);
}

void Game(int place[][3], Person human, Person wumpus, int posUser[], int posWumpus[]) {

	while (human.alive == true && wumpus.alive == true) {
		char choix;
		int choixSalle = 0;
		int choixTir = place[posUser[0]][posUser[1]];

		std::cout << "voulez vous vous deplacer ou tirer ? (m ou t) : ";
		std::cin >> choix;

		if (choix == 'm') {
			Deplacement(place, choixSalle, choixTir, posUser);
			AfficherSalles(place);
			human.alive = Perdu(place, human, wumpus, posUser, posWumpus);
		}
		else if (choix == 't') {
			wumpus.alive = Tir(place, posUser, posWumpus, choixSalle, choixTir, human, wumpus);
			if (wumpus.alive == false)
				break;
			AfficherSalles(place);
			human.alive = Tir(place, posUser, posWumpus, choixSalle, choixTir, human, wumpus);
		}
		
		if (human.alive == false)
			break;

		if (isWumpusProche(place, posUser, posWumpus))
			std::cout << "le wumpus est proche.." << std::endl;

	}
}