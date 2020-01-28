//Francesco Bortolotto

//Classe componente
#include <iostream>
#include <string>
#include "Gestione.h"
#include "Componente.h"
#include "Componente_in_attesa.h"
#include "Ordine.h"
#include "Ordine_in_attesa.h"
#include "Elettrodomestico.h"
#include "Elettrodomestico_in_attesa.h"

using namespace std;

Componente::Componente() {
	id = 0;
	name = "";
	delivery_time = 0;
	quantity = 0;
}

Componente::Componente(int ident, string nome, int time, int qta, double prezzo1, double prezzo2, double prezzo3) {
	id = ident;
	name = nome;
	delivery_time = time;
	quantity = qta;
	prezzi[0] = prezzo1;
	prezzi[1] = prezzo2;
	prezzi[2] = prezzo3;
	
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

int Componente::getId() const {
	return id;
}

string Componente::getName() const {
	return name;
}

double Componente::getPrice(int qta) const {
	if (qta < 11)
		return prezzi[0];

	if (qta < 51 || qta > 10)
		return prezzi[1];

	if (qta > 50)
		return prezzi[2];
}

double* Componente::getPrices() {

	return prezzi;
}


int Componente::getDeliveryTime() const {
	return delivery_time;
}

int Componente::getQuantity() const {
	return quantity;
}

void Componente::incrementQuantity(int qta_elett) {
	quantity = quantity * qta_elett;
}

void Componente::eliminaComponente(int qta)
{
		quantity -= qta;
		return;
}

ostream& operator<< (ostream& os, const Componente& c) {
	os <<"NOME:"<< c.getName() << " QTA:" << c.getQuantity();
	return os;
}

//classe componente_in_attesa

Componente_in_attesa::Componente_in_attesa(Componente component, int time)
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

int Componente_in_attesa::getTimeStamp() const
{
	return time_stamp;
}

int Componente_in_attesa::getId() const
{
	return componente.getId();
}

int Componente_in_attesa::getWaitingTime() const
{
	return waiting_time;
}

Componente Componente_in_attesa::getComponente() const
{
	return componente;
}

void Componente_in_attesa::setId(int ident) 
{
	componente.setId(ident);
}

void Componente_in_attesa::setName(string nome) {
	componente.setName(nome);
}

void Componente_in_attesa::setDeliveryTime(int time) {
	componente.setDeliveryTime(time);
}

void Componente_in_attesa::setQuantity(int qta) {
	componente.setQuantity(qta);
}


string Componente_in_attesa::getName() const {
	return componente.getName();
}

double Componente_in_attesa::getPrice(int qta) const {
	if (qta < 11)
		return componente.getPrice(5);

	if (qta < 51 || qta > 10)
		return componente.getPrice(15);

	if (qta > 50)
		return componente.getPrice(60);
}

double* Componente_in_attesa::getPrices() {

	return	componente.getPrices();
}


int Componente_in_attesa::getDeliveryTime() const {
	return componente.getDeliveryTime();
}

int Componente_in_attesa::getQuantity() const {
	return componente.getQuantity();
}

void Componente_in_attesa::incrementQuantity(int qta_elett) {
	componente.setQuantity(componente.getQuantity() * qta_elett);
}

void Componente_in_attesa::eliminaComponente(int qta)
{
	if(qta < componente.getQuantity())
		componente.setQuantity(componente.getQuantity() - qta);
}

ostream& operator<< (ostream& os, const Componente_in_attesa& c) {
	os << c.getComponente();
	return os;
}

//funzioni di gestione
vector<Ordine> Gestione::ordini_evasi()
{
	vector<Ordine> tmp;
	cout << "ORDINI EVASI IN QUESTO MESE: \n\n";
	for (int i = 0; i < ordini_in_attesa.size(); i++)
	{
		if (ordini_in_attesa[i].getTime() == month)
		{
			cout << ordini_in_attesa[i] << "\n";
			cassa += ordini_in_attesa[i].getTotalPrice();
			tmp.push_back(ordini_in_attesa[i]);
			//elimina l'ordine venduto dalla coda
			ordini_in_attesa.erase(ordini_in_attesa.begin() + i);
			i--;
		}
	}
	elettrodomestici_venduti();
	
	return tmp;
}

void Gestione::elettrodomestici_venduti()
{
	for (int i = 0; i < models.size(); i++)
	{
		if (models[i].getTime() == month)
		{
			vector<Componente> tmp = models[i].getComponents();
			for (int i = 0; i < tmp.size(); i++)
			{
				eliminaComponenti(tmp[i]);
			}
			//elimina l'elettrodomestico venduto dalla coda
			models.erase(models.begin() + i);
			i--;
		}
	}
}

void Gestione::componenti_arrivati()
{
	for (int i = 0; i < parts.size(); i++)
	{
		
		if (parts[i].getWaitingTime() == month)
		{
			//id ok
			aggiungiComponenti(parts[i]);
			//elimina componenti arrivati dalla coda
			parts.erase(parts.begin() + i);
			i--;
		}
	}
}
void Gestione::ordina_componenti()
{
	vector<Componente> tmp;
	//scandisce tutti gli ordini
	for (int i = 0; i < orders.size(); i++)
	{
		//prende gli ordini del mese 
		int idel = orders[i].getModelRequired();
		int qta = orders[i].getQuantity();
		double prex = 0;
		for (int j = 0; j < elet_disponibili.size(); j++)
		{	

			if (elet_disponibili[j].getId() == idel && orders.size() > 0 && orders[i].getTimeStamp() <= month && cassa >= (elet_disponibili[j].calculatePrice(qta)))    // **Condizione per ordinare i componenti
			{
				prex = elet_disponibili[j].calculatePrice(qta);
				//prende l'elettrodomestico richiesto dall'ordine
				Elettrodomestico tmp1 = cercaElettrodomestico(orders[i].getModelRequired());
				//estrapola i componenti dell'elettrodomestico
				tmp = tmp1.getComponents();

				//aggiunge i componenti alla coda parts
				for (int k = 0; k < tmp.size(); k++)
				{
					aggiungiComponenti(orders[i].getQuantity(), tmp[k]);
				}
				cassa -= prex;
				aggiungiElettrodomestici(orders[i].getQuantity(), tmp1);
				ordini_in_attesa.push_back(Ordine_in_attesa(orders[i], month, Elettrodomestico_in_attesa(tmp1, month)));
				orders.erase(orders.begin() + i);
				i--;
			}
		}
	}
}

Elettrodomestico Gestione::cercaElettrodomestico(int id)
{
	for (int i = 0; i < elet_disponibili.size(); i++)
	{
		if (id == elet_disponibili[i].getId())
			return elet_disponibili[i];
	}
}

void Gestione::aggiungiComponenti(int qta, Componente com)
{
	Componente_in_attesa tmp{com,month};
	parts.push_back(tmp);
	parts[parts.size() - 1].incrementQuantity(qta);
}

void Gestione::eliminaComponenti(Componente compon)
{
	for (int i = 0; i < magazzino.size(); i++)
	{
		if (magazzino[i].getId()==compon.getId())
		{
			magazzino[i].eliminaComponente(compon.getQuantity());
		}
	}
}
void Gestione::aggiungiElettrodomestici(int qta, Elettrodomestico elett)
{
	for (int i = 0; i < qta; i++)
	{
		models.push_back(Elettrodomestico_in_attesa(elett, month));
	}

}

void Gestione::aggiungiComponenti(Componente_in_attesa com)
{

	for (int i = 0; i < magazzino.size(); i++)
	{
		if (magazzino[i].getId() == com.getId())
		{
			magazzino[i].setQuantity(magazzino[i].getQuantity() + com.getComponente().getQuantity());
		}
	}
}