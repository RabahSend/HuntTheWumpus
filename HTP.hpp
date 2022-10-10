#ifndef HTP_HPP
#define HTP_HPP

struct Person {
	bool alive, deplacement;
};

void AfficherMenu();

void AfficherSalles(int[][3]);

void RandomPlace(int [][3], int, int[], int[]);

bool Perdu(int[][3], Person, Person, int[], int[]);

void Deplacement(int [][3], int, int, int[]);

bool Tir(int[][3], int[], int[], int&, int&, Person, Person);

bool isWumpusProche(int [][3], int [], int []);

void Game(int[][3], Person, Person, int[], int[]);

#endif