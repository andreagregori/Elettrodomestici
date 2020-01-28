//@autor STEVEN BINOTTO

#ifndef ELETTRODOMESTICO_IN_ATTESA_H
#define ELETTRODOMESTICO_IN_ATTESA_H


#include <iostream>
#include <vector>
#include "Elettrodomestico.h"

using namespace std;

class Elettrodomestico_in_attesa : public Elettrodomestico		//Steven
{									//Classe che eredita da Elettrodomestico
public:
	Elettrodomestico_in_attesa();
	Elettrodomestico_in_attesa(Elettrodomestico modello, int month);
	~Elettrodomestico_in_attesa();

	int getId() const;
	string getName() const;
	vector<Componente> getComponents() const;
	double getPrice() const;
	double calculatePrice();

	void setId(int num);
	void setName(string model);
	void setComponents(const vector<Componente>& parts);
	void setPrice(double prezzo);

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

#endif // !ELETTRODOMESTICO_IN_ATTESA_H