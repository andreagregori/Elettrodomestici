//Steven Binotto
#include "Elettrodomestico.h"
#include "Elettrodomestico_in_attesa.h"
#include "Ordine.h"
#include "Ordine_in_attesa.h"
#include "Componente.h"
#include "Componente_in_attesa.h"
//ELETTRODOMESTICO

//costruttore di un oggetto vuoto
Elettrodomestico::Elettrodomestico()
{
	id = 0;
	name = "";
	price = 0;
}

//costruttore di un oggetto
Elettrodomestico::Elettrodomestico(int num, string model, const vector<Componente>& parts)
{
	id = num;
	name = model;
	components = parts;
	price = calculatePrice();
}

//costruttore di un oggetto
Elettrodomestico::Elettrodomestico(int num, string model, const vector<Componente>& parts, double prezzo)
{
	id = num;
	name = model;
	components = parts;
	price = prezzo;
}

//distruttore
Elettrodomestico::~Elettrodomestico()
{
	id = 0;
	name = "";
	price = 0;
}

//restituisce l'id
int Elettrodomestico::getId() const
{
	return id;
}

//restituisce il nome del modello
string Elettrodomestico::getName() const
{
	return name;
}

//restituisce un vettore di componenti
vector<Componente> Elettrodomestico::getComponents() const
{
	return components;
}

//restituisce il prezzo del prodotto
double Elettrodomestico::getPrice() const
{
	return price;
}

//modifica l'id
void Elettrodomestico::setId(int num)
{
	if (num < 0)		//l'id deve essere un numero positivo
		throw Invalid();
	id = num;
}

//modifica il nome
void Elettrodomestico::setName(string model)
{
	name = model;
}

//modifica il vettore di componenti
void Elettrodomestico::setComponents(const vector<Componente>& parts)
{
	for (int i = 0; i < parts.size(); i++)
		components.push_back(parts[i]);
}

//modifica il prezzo del prodotto
void Elettrodomestico::setPrice(double prezzo)
{
	price = prezzo;
}


double Elettrodomestico::calculatePrice(int qta)
{
	double sum = 0;
	for (int i = 0; i < components.size(); i++)
		sum += components[i].getPrice(components[i].getQuantity()*qta) * components[i].getQuantity()*qta;
	return sum;
}
//calcola il prezzo del prodotto
double Elettrodomestico::calculatePrice()
{
	double sum = 0;
	for (int i = 0; i < components.size(); i++)
		sum += components[i].getPrice(components[i].getQuantity()) * components[i].getQuantity();
	return sum;
}

ostream& operator<<(ostream& os, const Elettrodomestico& el)
{
	os <<"ID:" << el.getId() << "  NOME:" << el.getName() << " PREZZO:" << el.getPrice() << " euro  COMPONENTI(";
	vector<Componente> v = el.getComponents();
	for (int i = 0; i < v.size(); ++i)
		os << v[i] << ", ";
	os << ")";
	return os;
}





//ELETTRODOMESTICO IN ATTESA

//costruttore oggetto vuoto
Elettrodomestico_in_attesa::Elettrodomestico_in_attesa()
{
	Elettrodomestico model();
	waiting_time = 0;
}

//costruttore oggetto
Elettrodomestico_in_attesa::Elettrodomestico_in_attesa(Elettrodomestico modello, int month)
{
	model = modello;
	waiting_time = calculateTime(month);
}

//distruttore oggetto
Elettrodomestico_in_attesa::~Elettrodomestico_in_attesa()
{
	//invoco il distruttore di Elettrodomestico;
	waiting_time = 0;
}


//restituisce il tempo di attesa
int Elettrodomestico_in_attesa::getTime() const
{
	return waiting_time;
}

//restituisce il modello in attesa
Elettrodomestico Elettrodomestico_in_attesa::getModel() const
{
	return model;
}

//modifica il tempo di attesa
void Elettrodomestico_in_attesa::setTime(int time)
{
	waiting_time = time;
}

//modifica il modello in attesa
void Elettrodomestico_in_attesa::setModel(Elettrodomestico item)
{
	model = item;
}

//calcola il mese di vendita dell'oggetto
int Elettrodomestico_in_attesa::calculateTime(int month)
{
	int max = 0;
	vector<Componente> parti = model.getComponents();
	for (int i = 0; i < parti.size(); i++)
	{
		if (parti[i].getDeliveryTime() > max)		//guardo il tempo di spedizione dei componenti
			max = parti[i].getDeliveryTime();		//cerco il più grande
	}
	max += month;						//aggiungo i mesi già grascorsi...
	return max + 1;									//... e il mese per la produzione
}

int Elettrodomestico_in_attesa::getId() const
{
	return model.getId();
}

//restituisce il nome del modello
string Elettrodomestico_in_attesa::getName() const
{
	return model.getName();
}

//restituisce un vettore di componenti
vector<Componente> Elettrodomestico_in_attesa::getComponents() const
{
	return model.getComponents();
}

//restituisce il prezzo del prodotto
double Elettrodomestico_in_attesa::getPrice() const
{
	return model.getPrice();
}

//modifica l'id
void Elettrodomestico_in_attesa::setId(int num)
{
	model.setId(num);
}

//modifica il nome
void Elettrodomestico_in_attesa::setName(string n)
{
	model.setName(n);
}

//modifica il vettore di componenti
void Elettrodomestico_in_attesa::setComponents(const vector<Componente>& parts)
{
	model.setComponents(parts);
}

//modifica il prezzo del prodotto
void Elettrodomestico_in_attesa::setPrice(double prezzo)
{
	model.setPrice(prezzo);
}

//calcola il prezzo del prodotto
double Elettrodomestico_in_attesa::calculatePrice()
{
	return model.calculatePrice();
}

ostream& operator<<(ostream& os, const Elettrodomestico_in_attesa& el)
{
	os << el.getModel();
	return os;
}




//ORDINE

//costruttore oggetto vuoto
Ordine::Ordine()
{
	time_stamp = 0;
	model_required = 0;
	quantity = 0;
}

//costruttore ogGetto Ordine
Ordine::Ordine(int time, int model, int num)
{
	time_stamp = time;
	model_required = model;
	quantity = num;
}

//distruttore
Ordine::~Ordine()
{
	time_stamp = 0;
	model_required = 0;
	quantity = 0;
}

//restituisce il mese dell'ordine
int Ordine::getTimeStamp() const
{
	return time_stamp;
}

//restituisce il modello
int Ordine::getModelRequired() const
{
	return model_required;
}

//restituisce la quantità di modelli
int Ordine::getQuantity() const
{
	return quantity;
}

//modifica il mese dell'ordine
void Ordine::setTimeStamp(int time)
{
	time_stamp = time;
}

//modifica il modello richiesto
void Ordine::setModelRequired(int model)
{
	model_required = model;
}

//modifica la quantità di modelli
void Ordine::setQuantity(int num)
{
	quantity = num;
}

bool Ordine::operator<(const Ordine& ord) const {
	return (time_stamp < ord.time_stamp);
}

int Ordine::tempo_necessario(Elettrodomestico e)
{
	return Elettrodomestico_in_attesa(e, 0).calculateTime(0);
}

ostream& operator<<(ostream& os, const Ordine& ord)
{
	os <<"TIMESTAMP:" << ord.getTimeStamp() << " ID:" << ord.getModelRequired() << " QTA:" << ord.getQuantity();
	return os;
}




//ORDINE IN ATTESA

//costruttore oggetto vuoto
Ordine_in_attesa::Ordine_in_attesa()
{
	Ordine order();
	total_price = 0;
	waiting_time = 0;
}

//costruttore oggetto ordine_in_attesa
Ordine_in_attesa::Ordine_in_attesa(Ordine ord, int month, Elettrodomestico_in_attesa item)
{
	order = ord;
	total_price = item.getPrice() * ord.getQuantity();
	waiting_time = item.calculateTime(month);
}

//costruttore oggetto ordine_in_attesa
Ordine_in_attesa::Ordine_in_attesa(Ordine ord, double price, int time)
{
	order = ord;
	total_price = price;
	waiting_time = time;
}

//distruttore
Ordine_in_attesa::~Ordine_in_attesa()
{
	//distruttore di ordine su order
	total_price = 0;
	waiting_time = 0;
}

//restituisce l'oggetto ordine
Ordine Ordine_in_attesa::getOrder() const
{
	return order;
}

//restituisce quanti soldi guadagno da questo ordine
double Ordine_in_attesa::getTotalPrice() const
{
	return total_price;
}

//restituisce il mese in cui verrà venduto l'ordine
int Ordine_in_attesa::getTime() const
{
	return waiting_time;
}

//mdifica l'oggetto ordine
void Ordine_in_attesa::setOrder(Ordine ord)
{
	order = ord;
}

//modifica l'incasso totale
void Ordine_in_attesa::setTotalPrice(double price)
{
	total_price = price;
}

//modifica il mese dell'incasso
void Ordine_in_attesa::setTime(int time)
{
	waiting_time = time;
}

ostream& operator<<(ostream& os, const Ordine_in_attesa& ord)
{
	os << ord.getOrder();
	return os;
}

int Ordine_in_attesa::getTimeStamp() const
{
	return order.getTimeStamp();
}

//restituisce il modello
int Ordine_in_attesa::getModelRequired() const
{
	return order.getModelRequired();
}

//restituisce la quantità di modelli
int Ordine_in_attesa::getQuantity() const
{
	return order.getQuantity();
}

//modifica il mese dell'ordine
void Ordine_in_attesa::setTimeStamp(int time)
{
	order.setTimeStamp(time);
}

//modifica il modello richiesto
void Ordine_in_attesa::setModelRequired(int model)
{
	order.setModelRequired(model);
}

//modifica la quantità di modelli
void Ordine_in_attesa::setQuantity(int num)
{
	order.setQuantity(num);
}

bool Ordine_in_attesa::operator<(const Ordine& ord) const {
	return (order.getTimeStamp() < ord.getTimeStamp());
}

int Ordine_in_attesa::tempo_necessario(Elettrodomestico e)
{
	return Elettrodomestico_in_attesa(e, 0).calculateTime(0);
}