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
	Elettrodomestico();
	Elettrodomestico(int num, string model, const vector<Componente> parts);
	Elettrodomestico(int num, string model, const vector<Componente> parts, double prezzo);
	~Elettrodomestico();
	
	/*Elettrodomestico(const Elettrodomestico& el);
	Elettrodomestico& operator=(const Elettrodomestico& el);
	Elettrodomestico(Elettrodomestico&& el);
	Elettrodomestico& operator=(Elettrodomestico&& el);*/
	
	int getId();
	string getName();
	vector<Componente> getComponents();
	double getPrice();
	double calculatePrice(const vector<Componente> pezzi);
	
	void setId(int num);
	void setName(string model);
	void setComponents(const vector<Componente> parts);
	void setPrice(double prezzo);

	
private:
	int id;
	string name;
	double price;
	vector<Componente> components;
};


class Elettrodomestico_in_attesa : public Elettrodomestico		//Steven
{									//Classe che eredita da Elettrodomestico
public:
	Elettrodomestico_in_attesa();
	Elettrodomestico_in_attesa(Elettrodomestico modello);
	Elettrodomestico_in_attesa(Elettrodomestico modello, int time);
	~Elettrodomestico_in_attesa();
	
	/*Elettrodomestico_in_attesa(const Elettrodomestico_in_attesa& el);
	Elettrodomestico_in_attesa& operator=(const Elettrodomestico_in_attesa& el);
	Elettrodomestico_in_attesa(Elettrodomestico_in_attesa&& el);
	Elettrodomestico_in_attesa& operator=(Elettrodomestico_in_attesa&& el);*/
	
	int getTime();
	Componente getModel();
	int calculateTime();
	
	void setTime(int time);
	void setModel(Elettrodomestico item);

	
private:
	Elettrodomestico model;
	int waiting_time;
};


class Ordine			//Steven
{
public:
	Ordine();
	Ordine(int time, int model, int num);
	~Ordine();
	
	/*Ordine(const Ordine& or);
	Ordine& operator=(const Ordine& or);
	Ordine(Ordine&& or);
	Ordine& operator=(Ordine&& or);*/
	
	int getTimeStamp();
	int getModelRequired();
	int getQuantity();
	
	void setTimeStamp(int time);
	void setModelRequired(int model);
	void setQuantity(int num);

private:
	int time_stamp;
	int model_required;
	int quantity;
};

class Ordine_in_attesa : public Ordine			//Steven
{
public:
	Ordine_in_attesa();
	Ordine_in_attesa(Ordine ord, double price, Elettrodomestico_in_attesa item);
	Ordine_in_attesa(Ordine ord, double price, int time);
	~Ordine_in_attesa();
	
	/*Ordine_in_attesa(const Ordine_in_attesa& or);
	Ordine_in_attesa& operator=(const Ordine_in_attesa& or);
	Ordine_in_attesa(Ordine_in_attesa&& or);
	Ordin_in_attesa& operator=(Ordine_in_attesa&& or);*/
	
	Ordine getOrder();
	double getTotalPrice(Elettrodomestico item);
	int getTime();
	
	void setOrder(Ordine ord);
	void setTotalPrice(double price);
	void setTime(int time);

private:
	Ordine order;
	int waiting_time;
	double total_price;
};


class Gestione			//Andrea
{
public:
	Gestione();
	~Gestione(){}

	void inizializza_comp();
	void inizializza_elet();
	void inizializza_orders();

	vector<Ordine> ordini_evasi();
	vector<Elettrodomestico> elettrodomestici_venduti();
	vector<Componente> componenti_arrivati();
	vector<Componente_in_attesa> ordina_componenti();
	Elettrodomestico cercaElettrodomestico(int id);
	void aggiungiComponenti(int qta, Componente component);
	void aggiungiElettrodomestici(int qta, Elettrodomestico elett);

	bool is_componente(int id);
	bool is_elettrodomestico(int id);

private:
	int month;
	vector<Componente_in_attesa> parts;
	vector<Elettrodomestico_in_attesa> models;
	vector<Ordine_in_attesa> ordini_in_attesa;
	vector<Ordine> orders;
	vector<Elettrodomestico> elet_disponibili;
	vector<Componente> comp_disponibili;
};


//Eventuali helper function e overload operatori
