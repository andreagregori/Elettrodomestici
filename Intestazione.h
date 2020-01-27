#pragma once
//File di intestazione

#include <iostream>
#include <vector>

using namespace std;

class Componente					//Francesco
{
public:
	Componente();
	Componente(int id, string name, int time, int quantity, double prezzo1, double prezzo2, double prezzo3);

	void setId(int id);
	void setName(string name);
	void setDeliveryTime(int time);
	void setQuantity(int qta);

	int getId() const;
	string getName() const;
	int getDeliveryTime() const;
	int getQuantity() const;
	double getPrice(int qta) const;
	double* getPrices();

	void incrementQuantity(int qta_elett);
	void eliminaComponente(int qta);

private:
	int id;
	string name;
	int delivery_time;
	int quantity;
	double prezzi[3];
};

ostream& operator<< (ostream& os, const Componente& c);

class Componente_in_attesa : public Componente		//Francesco
{									//Classe che Eredita da Componente
public:
	Componente_in_attesa(Componente component, int time_stamp);

	void setTimeStamp(int time);
	int getTimeStamp() const;
	int getWaitingTime() const;
	Componente getComponente() const;
	int getId() const;

private:
	Componente componente;
	int waiting_time;
	int time_stamp;
};

ostream& operator<< (ostream& os, const Componente_in_attesa& c);

class Elettrodomestico					//Steven
{
public:
	class Invalid {};
	Elettrodomestico();
	Elettrodomestico(int num, string model, const vector<Componente>& parts);
	Elettrodomestico(int num, string model, const vector<Componente>& parts, double prezzo);
	~Elettrodomestico();

	int getId() const;
	string getName() const;
	vector<Componente> getComponents() const;
	double getPrice() const;
	double calculatePrice();

	void setId(int num);
	void setName(string model);
	void setComponents(const vector<Componente>& parts);
	void setPrice(double prezzo);


private:
	int id;
	string name;
	double price;
	vector<Componente> components;
};

ostream& operator<<(ostream& os, const Elettrodomestico& el);

class Elettrodomestico_in_attesa : public Elettrodomestico		//Steven
{									//Classe che eredita da Elettrodomestico
public:
	Elettrodomestico_in_attesa();
	Elettrodomestico_in_attesa(Elettrodomestico modello, int month);
	~Elettrodomestico_in_attesa();

	int getTime() const;
	Elettrodomestico getModel() const;
	int calculateTime(int month);

	void setTime(int time);
	void setModel(Elettrodomestico item);


private:
	Elettrodomestico model;
	int waiting_time;
};

ostream& operator<<(ostream& os, const Elettrodomestico_in_attesa& el);


class Ordine			//Steven
{
public:
	Ordine();
	Ordine(int time, int model, int num);
	~Ordine();

	bool operator<(const Ordine& ord) const;

	int getTimeStamp() const;
	int getModelRequired() const;
	int getQuantity() const;

	void setTimeStamp(int time);
	void setModelRequired(int model);
	void setQuantity(int num);
	int tempo_necessario(Elettrodomestico e);

private:
	int time_stamp;
	int model_required;
	int quantity;
};

ostream& operator<<(ostream& os, const Ordine& ord);


class Ordine_in_attesa : public Ordine			//Steven
{
public:
	Ordine_in_attesa();
	Ordine_in_attesa(Ordine ord, int month, Elettrodomestico_in_attesa item);
	Ordine_in_attesa(Ordine ord, double price, int time);
	~Ordine_in_attesa();

	Ordine getOrder() const;
	double getTotalPrice() const;
	int getTime() const;

	void setOrder(Ordine ord);
	void setTotalPrice(double price);
	void setTime(int time);

private:
	Ordine order;
	int waiting_time;
	double total_price;
};

ostream& operator<<(ostream& os, const Ordine_in_attesa& ord);


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
