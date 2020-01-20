//Francesco Bortolotto
//Ho modificato anche l'intestazione
//Classe componente
#include <iostream>
#include <string>
#include "Intestazione.h"

using namespace std;

Componente::Componente() {
	id = 0;
	name = "";
	delivery_time = 0;
	quantity = 0;
}

Componente::Componente(int ident,string nome, int time, int qta) {
	id = ident;
	name = nome;
	delivery_time = time;
	quantity = quantity;
}

void Componente::setId(int ident) {
	id = ident;
}

void Componente::setName(string nome) {
	name = nome;
}

void Componente::setDeliveryTime(int time) {
	delivery_time = time;
}

void Componente::setQuantity(int qta) {
	quantity = qta;
}

int Componente::getId() {
	return id;
}

string Componente::getName() {
	return name;
}

int Componente::getDeliveryTime() {
	return delivery_time;
}

int Componente::getQuantity() {
	return quantity;
}

void Componente::incrementQuantity(int qta_elett) {
	quantity = quantity*qta_elett;
}

//classe componente_in_attesa
#include <iostream>
#include <string>
#include "Intestazione.h"

using namespace std;

Componente_in_attesa::Componente_in_attesa(Componente component,int time) 
{
	componente = component;
	time_stamp = time;
	waiting_time = time + component.getDeliveryTime();
}

void Componente_in_attesa::setTimeStamp(int time) 
{
	int plus = time_stamp - time;
	time_stamp = time;
	waiting_time += plus;
}

int Componente_in_attesa::getTimeStamp()
{
	return time_stamp;
}

int Componente_in_attesa::getWaitingTime()
{
	return waiting_time;
}


//funzioni di gestione
#include "Gestione.cpp"
vector<Ordine> Gestione::ordini_evasi()
{
	vector<Ordine> tmp;
	for (int i = 0; i < ordini_in_attesa.size(); i++)
	{
		if (ordini_in_attesa.getWaitingTime == month)
		{
			tmp.push_back(ordini_in_attesa[i]);
			//elimina l'ordine venduto dalla coda
			ordini_in_attesa.erase(ordini_in_attesa.begin() + i);
		}
	}
	return tmp;
}

vector<Elettrodomestico> Gestione:: elettrodomestici_venduti()
{
	vector<Elettrodomestico> tmp;
	for (int i = 0; i < models.size(); i++)
	{
		if(models[i].getWaitingTime == month)
		{ 
			tmp.push_back(models[i]);
			//elimina l'elettrodomestico venduto dalla coda
			models.erase(models.begin() + i);
		}
	}
	return tmp;
}

vector<Componente> Gestione::componenti_arrivati()
{
	vector<Componente> tmp;
	for (int i = 0; i < parts.size(); i++)
	{
		if ((int)parts[i].getWaitingTime == month)
		{
			tmp.push_back(parts[i]);
			//elimina componenti arrivati dalla coda
			parts.erase(parts.begin()+i);
		}
	}
	return tmp;
}

vector<Componente_in_attesa> Gestione::ordina_componenti()
{
	vector<Componente_in_attesa> tmp;
	//scandisce tutti gli ordini
	for (int i = 0; i < orders.size(); i++)
	{
		//prende gli ordini del mese 
		if (orders[i].getTimeStamp == month)    // **Condizione per ordinare i componenti
		{
			//prende l'elettrodomestico richiesto dall'ordine
			Elettrodomestico tmp1 = cercaElettrodomestico(orders[i].getId);
			//estrapola i componenti dell'elettrodomestico
			tmp = tmp1.getComponenti();

			//aggiunge i componenti alla coda parts
			for (int j = 0; j < tmp.size() < j++)
			{
				aggiungiComponenti(orders[i].getQuantity(), tmp[j]);
			}

			aggiungiElettrodomestici(orders[i].getQuantity(), tmp1);
			ordini_in_attesa.push_back(Ordine_in_attesa(orders[i],month));
			orders.erase(orders.begin() + i);
		}
	}
	return tmp;
}

Elettrodomestico Gestione::cercaElettrodomestico(int id)
{
	for (int i = 0; i < elet_disponibili.size(); i++)
	{
		if (id == elet_disponibili[i].getId())
			return elet_disponibili[i];
	}
}

void Gestione::aggiungiComponenti(int qta, Componente component)
{
	parts.push_back(Componente_in_attesa(component, month));
	parts[parts.size() - 1].incrementQuantity(qta);
}

void Gestione::aggiungiElettrodomestici(int qta, Elettrodomestico elett)
{
	for (int i = 0; i < qta; i++)
	{
		models.push_back(Elettrodomestico_in_attesa(elett, month));
	}

}
