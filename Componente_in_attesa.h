//@autor FRANCESCO BORTOLOTTO

#ifndef COMPONENTE_IN_ATTESA_H
#define COMPONENTE_IN_ATTESA_H


#include "Componente.h"
#include <iostream>
#include <vector>

using namespace std;

class Componente_in_attesa : public Componente
{									//Classe che Eredita da Componente
public:
	Componente_in_attesa();
	Componente_in_attesa(Componente component, int time_stamp);

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

	void setTimeStamp(int time);
	int getTimeStamp() const;
	int getWaitingTime() const;
	Componente getComponente() const;

private:
	Componente componente;
	int waiting_time;
	int time_stamp;
};

ostream& operator<< (ostream& os, const Componente_in_attesa& c);

#endif // !COMPONENTE_IN_ATTESA_H