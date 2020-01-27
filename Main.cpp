// Main

#include <iostream>
#include "Intestazione.h"

using namespace std;

int main()
{
	bool flag = true;

	//Creazione degli oggetti che servono
	Gestione g{};
	g.stampa_elet_disponibili();
	g.stampa_comp_disponibili();
	g.stampa_ordini();

	while (flag)
	{
		char input;
		cout << "--> Premere n per incrementare il mese <--\n";
		cout << "--> Premere 0 per uscire <--\n";
		cin >> input;
		system("cls");

		if (input == 'n')
		{
			cout << "\nMESE ATTUALE (" << g.getMonth() + 1 << ")\n\n";
			g.next_month();
			//chiamate delle funzioni che servono

		}
		else if (input == '0')
		{
			cout << "uscito";
			flag = false;
		}
		else
			cout << "\nCOMANDO ERRATO\n\n";
		
	}


}