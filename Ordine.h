//@autor STEVEN BINOTTO

#ifndef ORDINE_H
#define ORDINE_H


#include <iostream>
#include <vector>

#include "Componente.h"
#include "Componente_in_attesa.h"
#include "Elettrodomestico.h"
#include "Elettrodomestico_in_attesa.h"

using namespace std;

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

#endif // !ORDINE_H