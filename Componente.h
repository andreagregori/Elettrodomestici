//@autor FRANCESCO BORTOLOTTO

#ifndef COMPONENTE_H
#define COMPONENTE_H
#include <iostream>
#include <vector>

using namespace std;

//CLASSE COMPONENTE

class Componente			
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

#endif //COMPONENTE_H
