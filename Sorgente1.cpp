//Andrea Gregori

#include <iostream>
#include <fstream>
#include <string>
#include "Intestazione.h"

using namespace std;



//Funzione che legge il file components_info.dat e carica i vari componenti in comp_disponibili
void Gestione::inizializza_comp() {
	ifstream components("components_info.dat");
	if (components.is_open())
	{
		string line;
		while (getline(components, line))
		{
			cout << line;
		}
	}
}

//Funzione che legge il file models.dat (e i vari model1.dat..) e carica i vari modelli in elet_disponibili
void Gestione::inizializza_elet() {

}
