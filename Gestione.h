#ifndef GESTIONE_H
#define GESTIONE_H


#include <iostream>
#include <vector>

#include "Componente.h"
#include "Componente_in_attesa.h"
#include "Ordine.h"
#include "Ordine_in_attesa.h"
#include "Elettrodomestico.h"
#include "Elettrodomestico_in_attesa.h"

using namespace std;

class Gestione			//Andrea
{
public:
	Gestione();
	~Gestione() {}

	void inizializza_comp();
	void inizializza_elet();
	void inizializza_orders();
	void inizializza_magazzino();
	void sort_orders();
	void next_order();
	int next_month();
	int getMonth() const;

	vector<Ordine> ordini_evasi();

	void ordina_componenti();
	Elettrodomestico cercaElettrodomestico(int id);
	void aggiungiComponenti(int qta, Componente component);
	void aggiungiElettrodomestici(int qta, Elettrodomestico elett);
	void stampa_elet_disponibili();
	void stampa_comp_disponibili();
	void stampa_ordini();
	void stampa_c1();
	void stampa_magazzino();

	int getComponente_disponibile(int id_comp) const;

	bool is_componente(int id);
	bool is_elettrodomestico(int id);

private:
	int month;
	double cassa;
	vector<Componente> magazzino;
	vector<Componente_in_attesa> parts;
	vector<Elettrodomestico_in_attesa> models;
	vector<Ordine_in_attesa> ordini_in_attesa;
	vector<Ordine> orders;
	vector<Elettrodomestico> elet_disponibili;
	vector<Componente> comp_disponibili;

	void eliminaComponenti(Componente compon);
	void componenti_venduti();
	void elettrodomestici_venduti();
	void aggiungiComponenti(Componente_in_attesa com);
	void componenti_arrivati();

};


#endif // !GESTIONE_H