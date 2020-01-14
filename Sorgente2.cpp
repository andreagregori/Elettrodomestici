//Steven Binotto

#include "Intestazione.h"
#include <iostream>
#include <fstream>
using namespace std;

//ELETTRODOMESTICO

/*
	int id;
	string name;
	vector<Componente> components;
*/

//costruttore di un oggetto vuoto
Elettrodomestico::Elettrodomestico()
{
	id = 0;
	name = null;
	components = nullptr;
}

//costruttore di un oggetto
Elettrodomestico::Elettrodomestico(Ordine order)		//devo capire se qualcuno mi da i dati o se devo prendermeli io
{
	id = order.get_id();
	/*ifstream myfile;
	myfile.open("models.dat");
	for(int i = 0; i++; name = ;
	components = nullptr;*/
}

//distruttore
Elettrodomestico::~Elettrodomestico()
{
	delete[] components;
	components = nullptr;
	id = 0;
	name = null;
}

//restituisce l'id
int Elettrodomestico::get_id()
{
	return id;
}

//restituisce il nome del modello
string Elettrodomestico::get_name()
{
	return name;
}

//restituisce un vettore di componenti
Componente* Elettrodomestico::get_components()
{
	return components;
}

//modifica l'id
void Elettrodomestico::set_id(int num)
{
	if (num < 0)		//l'id deve essere un numero positivo
		throw Invalid();
	id = num;
}

//modifica il nome
void Elettrodomestico::set_name(string model)
{
	name = model;
}

//modifica il vettore di componenti
void Elettrodomestico::set_components(Componente* parts)
{
	delete[] components;
	components = nullptr;		//serve questa riga o è una cazzata?
	for (int i = 0; i < parts.size(); i++)
		components.push_back(parts[i]);
}


//ELETTRODOMESTICO IN ATTESA

/*
	Elettrodomestico model;
	int waiting_time;
*/

//costruttore oggetto vuoto
Elettrodomestico_in_attesa::Elettrodomestico_in_attesa() 
{
	model = new Elettrodomestico();
	waiting_time = 0;
}

//costruttore oggetto
Elettrodomestico_in_attesa::Elettrodomestico_in_attesa(Elettrodomestico modello, int time)
{
	model = modello;
	waiting_time = time;
}

//distruttore oggetto
Elettrodomestico_in_attesa::~Elettrodomestico_in_attesa() 
{
	//invoco il distruttore di Elettrodomestico;
	waiting_time = 0;
}


//restituisce il tempo di attesa
int Elettrodomestico_in_attesa::get_time()
{
	return waiting_time;
}

//restituisce il modello in attesa
Componente Elettrodomestico_in_attesa::get_model(); // o get_item()
{
	return model;
}

//modifica il tempo di attesa
void Elettrodomestico_in_attesa::set_time(int time)
{
	waiting_time = time;
}

//modifica il modello in attesa
void Elettrodomestico_in_attesa::set_model(Elettrodomestico item)
{
	model = item;
}

//decrementa di 1 il tempo di attesa
void Elettrodomestico_in_attesa::decrement()
{
	waiting_time--;
}


//MAGAZZINO

// vector<Componente_in_attesa> available;

//costruttore magazzino vuoto
Magazzino::Magazzino() 
{
	available = nullptr;
}

//magazzino con componenti
Magazzino::Magazzino(Componente_in_attesa* components) //si passa così?
{
	for (int i = 0; i < components.size(); i++)
		available.push_back(components[i]);
}

//distruttore
Magazzino::~Magazzino() 
{
	delete[] available;
	available = nullptr;
}

//inserimento componente
void Magazzino::insert_component(Componente_in_attesa item)
{
	available.push_back(item); //or insert
}

//per la cancellazione ci pensa Check o devo fornire qualcosa?
