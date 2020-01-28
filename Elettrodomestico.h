#ifndef ELETTRODOMESTICO_H
#define ELETTRODOMESTICO_H

#include <iostream>
#include <vector>
#include "Componente.h"
#include "Componente_in_attesa.h"
using namespace std;

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
	double calculatePrice(int qta);

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

#endif //!ELETTRODOMESTICO_H