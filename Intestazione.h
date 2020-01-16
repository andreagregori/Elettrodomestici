//File di intestazione

#include <iostream>
#include <vector>

using namespace std;

class Componente					//Francesco
{
public:
	Componente();
	Componente(int id, string name, int time, int quantity);
	~Componente();

	void setId(int id);
	void setName(string name);
	void setDeliveryTime(int time);
	void setQuantity(int qta);

	int getId();
	string getName();
	int getDeliveryTime();
	int getQuantity();
	

private:
	int id;
	string name;
	int delivery_time;
	int quantity;
};


class Componente_in_attesa : public Componente		//Francesco
{									//Classe che Eredita da Componente
public:
	Componente_in_attesa();
	Componente_in_attesa(Componente component, int time_stamp);
	~Componente_in_attesa();

	void setTimeStamp(int time);
	int getTimeStamp();
	int getWaitingTime();

private:
	Componente componente;
	int waiting_time;
	int time_stamp;
};



class Elettrodomestico					//Steven
{
public:
	Elettrodomestico(){}
	~Elettrodomestico(){}

private:
	int id;
	string name;
	double price;
	vector<Componente> components;
};


class Elettrodomestico_in_attesa : public Elettrodomestico		//Steven
{										//Classe che eredita da Elettrodomestico
public:
	Elettrodomestico_in_attesa(){}
	~Elettrodomestico_in_attesa(){}

private:
	//Eredita i dati membro di Elettredomestico (come prima, non so se si fa così)
	int waiting_time;
};


class Ordine			//Andrea
{
public:
	Ordine(){}
	~Ordine(){}

private:
	int time_stamp;
	int model_required;
	int quantity;
};


class Magazzino			//Steven
{
public:
	Magazzino(){}
	~Magazzino(){}

private:
	vector<Componente_in_attesa> available;
};

class Gestione			//Andrea
{
public:
	Gestione();
	~Gestione(){}

	void inizializza_comp();
	void inizializza_elet();
	void inizializza_orders();

	bool is_componente(int id);
	bool is_elettrodomestico(int id);

private:
	int month;
	vector<Componente_in_attesa> parts;
	vector<Elettrodomestico_in_attesa> models;
	vector<Ordine> orders;
	vector<Elettrodomestico> elet_disponibili;
	vector<Componente> comp_disponibili;
};


//Eventuali helper function e overload operatori
