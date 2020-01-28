//@autor FRANCESCO BORTOLOTTO - ANDREA GREGORI - STEVEN BINOTTO

#include <iostream>
#include "Gestione.h"
#include "Componente.h"
#include "Componente_in_attesa.h"
#include "Ordine.h"
#include "Ordine_in_attesa.h"
#include "Elettrodomestico.h"
#include "Elettrodomestico_in_attesa.h"

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
		if (g.finito())
		{
			cout << "		///////////////////////\n";
			cout << "		//SIMULAZIONE FINITA.//\n";
			cout << "		///////////////////////\n";
			break;
		}
		if (input == 'n')
		{
			cout << "\nMESE ATTUALE (" << g.getMonth() + 1 << ")\n\n";
			//Funzione che incrementa di un mese il tempo.
			g.next_month();

		}
		else if (input == '0')
		{
			cout << "SIMULAZIONE ARRESTATA";
			flag = false;
		}
		else
			cout << "\nCOMANDO ERRATO\n\n";
		
	}


}