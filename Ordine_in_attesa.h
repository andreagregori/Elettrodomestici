#ifndef ORDINE_IN_ATTESA_H
#define ORDINE_IN_ATTESA_H


#include <iostream>
#include <vector>
#include "Ordine.h"

using namespace std;

class Ordine_in_attesa : public Ordine			//Steven
{
public:
	Ordine_in_attesa();
	Ordine_in_attesa(Ordine ord, int month, Elettrodomestico_in_attesa item);
	Ordine_in_attesa(Ordine ord, double price, int time);
	~Ordine_in_attesa();

	bool operator<(const Ordine& ord) const;

	int getTimeStamp() const;
	int getModelRequired() const;
	int getQuantity() const;

	void setTimeStamp(int time);
	void setModelRequired(int model);
	void setQuantity(int num);
	int tempo_necessario(Elettrodomestico e);

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

#endif // !ORDINE_IN_ATTESA_H