//Francesco Bortolotto
//Ho modificato anche l'intestazione
#include "Gestione.cpp"
vector<Ordine> Gestione::ordini_evasi()
{
	vector<Ordine> tmp;
	for (int i = 0; i < ordini_in_attesa.size(); i++)
	{
		if (ordini_in_attesa.getWaitingTime == month)
		{
			tmp.push_back(ordini_in_attesa[i]);
			//elimina l'ordine venduto dalla coda
			//ordini_in_attesa.erase(i);
		}
	}
	return tmp;
}

vector<Elettrodomestico> Gestione:: elettrodomestici_venduti()
{
	vector<Elettrodomestico> tmp;
	for (int i = 0; i < models.size(); i++)
	{
		if(models[i].getWaitingTime == month)
		{ 
			tmp.push_back(models[i]);
			//elimina l'elettrodomestico venduto dalla coda
			//models.erase(i);
		}
	}
	return tmp;
}

vector<Componente> Gestione::componenti_arrivati()
{
	vector<Componente> tmp;
	for (int i = 0; i < parts.size(); i++)
	{
		if (parts[i].getWaitingTime == month)
		{
			tmp.push_back(parts[i]);
			//elimina componenti arrivati dalla coda
			//parts.erase(i);
		}
	}
	return tmp;
}

vector<Componente_in_attesa> Gestione::ordina_componenti()
{
	vector<Componente_in_attesa> tmp;
	//scandisce tutti gli ordini
	for (int i = 0; i < orders.size(); i++)
	{
		//prende gli ordini del mese 
		if (orders[i].getTimeStamp == month)    // **Condizione per ordinare i componenti
		{
			//prende l'elettrodomestico richiesto dall'ordine
			Elettrodomestico tmp1 = cercaElettrodomestico(orders[i].getId);
			//estrapola i componenti dell'elettrodomestico
			tmp = tmp1.getComponenti();

			//aggiunge i componenti alla coda parts
			for (int j = 0; j < tmp.size() < j++)
			{
				aggiungiComponenti(orders[i].getQuantity(), tmp[j]);
			}

			aggiungiElettrodomestici(orders[i].getQuantity(), tmp1);
			ordini_in_attesa.push_back(orders[i]);
			orders.erase[i];
		}
	}
	return tmp;
}

Elettrodomestico Gestione::cercaElettrodomestico(int id)
{
	for (int i = 0; i < elet_disponibili.size(); i++)
	{
		if (id == elet_disponibili[i].getId())
			return elet_disponibili[i];
	}
}

vector<Ordine> Gestione::ordiniEvasi()
{
	vector<Ordine> tmp;
	for (int i = 0; i < ordini_in_attesa.size(); i++)
	{
		if (ordini_in_attesa[i].getWaitingTime == month)
		{
			tmp.push_back(ordini_in_attesa[i]);
			//elimina ordine venduto dalla coda
			ordini_in_attesa.erase(i);
		}
	}
	return tmp;
}

void Gestione::aggiungiComponenti(int qta, Componente component)
{
	parts.push_back(Componente_in_attesa(component, month));
	parts[parts.size() - 1].incrementQuantity(qta);
}

void Gestione::aggiungiElettrodomestici(int qta, Elettrodomestico elett)
{
	for (int i = 0; i < qta; i++)
	{
		models.push_back(Elettrodomestico_in_attesa(elett, month));
	}

}
