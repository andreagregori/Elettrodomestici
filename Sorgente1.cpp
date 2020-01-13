//

#include <iostream>
#include <fstream>
#include <string>
#include "Intestazione.h"

using namespace std;

Gestione::Gestione() {
	month = 1;
	//inizializza_comp();
	//inizializza_elet();
}

//Funzione che legge il file components_info.dat e carica i vari componenti in comp_disponibili
void Gestione::inizializza_comp() {
	ifstream components("components_info.dat");
	if (components.is_open())
	{
		string line;
		while (getline(components, line))		//Ciclo che legge riga per riga e salva il contenuto in line
		{
			cout << line << "\n";
		}
		components.close();
	}
}

//Funzione che legge il file models.dat (e i vari model1.dat..) e carica i vari modelli in elet_disponibili
void Gestione::inizializza_elet() {
	ifstream models("models.dat");
	vector<string> files;
	if (models.is_open())
	{
		string line;
		while (getline(models, line))		//Ciclo che legge riga per riga e salva il contenuto in line
		{
			files.push_back(line);			//Salvo i nomi dei file
		}
		models.close();
	}

	for (int i = 0; i < files.size(); i++)		//Per ogni file leggo le info del modello o le carico su elet_disponibili
	{
		ifstream modello(files[i]);
		if (modello.is_open())
		{
			int id_eletr;
			modello >> id_eletr;			//Scrive in id_eletr il primo intero (model id)
			string nome;
			modello >> nome;				//Scrive in nome la seconda stringa (model name)

			//Comincio a leggere i componenti
			while (modello.good())
			{
				int id_comp;
				modello >> id_comp;
				modello >> nome;
				int quantità;
				modello >> quantità;
				if (true /*chiamata funzione che controlla se esiste il comp.*/)
				{
					//Chiamata costruttore componente
					//Pushback su components (di Elettrodomestico con id_eletr)
				}
			}


			modello.close();
		}
	}
}