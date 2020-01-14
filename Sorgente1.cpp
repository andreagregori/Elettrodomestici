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
	//inizializza_orders();
}

//Funzione che legge il file components_info.dat e carica i vari componenti in comp_disponibili
void Gestione::inizializza_comp() {
	ifstream components("components_info.dat");
	if (components.is_open())
	{
		while (components.good())
		{
			cout << "COMPONENTE\n";
			int id;
			components >> id;
			cout << "id: " << id << "\n";
			components.clear();
			string nome;
			components >> nome;
			cout << "nome: " << nome << "\n";
			int mese;
			components >> mese;
			cout << "mese: " << mese << "\n";
			double prezzo[3];
			for (int i = 0; i < 3; i++)
			{
				components >> prezzo[i];
				cout << "prezzo " << i + 1 << " :" << prezzo[i] << "\n";
			}
			cout << "\n";
			//Chiamata costruttore componente
			//push_back su comp_disponibili
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
			cout << line << "\n";
		}
		models.close();
	}

	for (int i = 0; i < files.size(); i++)		//Per ogni file leggo le info del modello o le carico su elet_disponibili
	{
		ifstream modello(files[i]);
		if (modello.is_open())
		{
			//Leggo le info del modello
			cout << files[i] << "\n";
			int id_eletr;
			modello >> id_eletr;			//Scrive in id_eletr il primo intero (model id)
			cout << "id: " << id_eletr << "\n";
			string nome;
			modello >> nome;				//Scrive in nome la seconda stringa (model name)
			cout << "nome: " << nome << "\n";

			//Comincio a leggere i componenti
			cout << "COMPONENTI\n";
			while (modello.good())
			{
				int id_comp;
				modello >> id_comp;
				cout << "id_comp: " << id_comp << "\n";
				string nome_comp;
				modello >> nome_comp;
				cout << "nome_comp: " << nome_comp << "\n";
				int quantità;
				modello >> quantità;
				cout << "quantità: " << quantità << "\n\n";
				if (is_componente(id_comp))
				{
					//Chiamata costruttore componente
					//Pushback su components (di Elettrodomestico con id_eletr)
				}
			}


			modello.close();
		}
	}
}

//Funzione che legge gli ordini da order.dat
void Gestione::inizializza_orders() {
	ifstream ordini("orders.dat");
	if (ordini.is_open())
	{
		double cassa;
		ordini >> cassa;
		cout << "cassa: " << cassa << "\n\n";
		while (ordini.good())
		{
			int time_stamp;
			ordini >> time_stamp;
			cout << "time_stamp: " << time_stamp << "\n";
			int model_id;
			ordini >> model_id;
			cout << "model_id: " << model_id << "\n";
			int qta;
			ordini >> qta;
			cout << "qta: " << qta << "\n";
			if (is_elettrodomestico(model_id))
			{
				//Costruttore Ordine
				//push_back su orders
			}
		}
		ordini.close();
	}
}

//Funzione che cerca se il componente passato esiste
bool Gestione::is_componente(int id) {
	for (int i = 0; i < comp_disponibili.size(); i++)
	{
		if (true /*id == comp_disponibili[i].getId()*/)
			return true;
	}
	return false;
}

//Funzione che cerca se l'elettrodomestico passato esiste
bool Gestione::is_elettrodomestico(int id) {
	for (int i = 0; i < elet_disponibili.size(); i++)
	{
		if (true /*id == elet_disponibili[i].getId()*/)
			return true;
	}
	return false;
}