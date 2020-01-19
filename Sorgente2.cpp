//Steven Binotto

//ELETTRODOMESTICO

//costruttore di un oggetto vuoto
Elettrodomestico::Elettrodomestico()
{
	id = 0;
	name = null;
	components = nullptr;
	price = 0;
}

//costruttore di un oggetto
Elettrodomestico::Elettrodomestico(int num, string model, const vector<Componente>& parts)		
{
	id = num;
	name = model;
	components = parts;
	price = this.calculatePrice(components);
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
	delete[] components;
	components = nullptr;
	id = 0;
	name = null;			//E SE RICHIAMASSI IL COSTRUTTORE VUOTO???
	price = 0;
}

//restituisce l'id
int Elettrodomestico::getId()
{
	return id;
}

//restituisce il nome del modello
string Elettrodomestico::getName()
{
	return name;
}

//restituisce un vettore di componenti
Componente* Elettrodomestico::getComponents()
{
	return components;
}

//restituisce il prezzo del prodotto
double Elettrodomestico::getPrice()
{
	return price;
}

//modifica l'id
void Elettrodomestico::setId(int num)
{
	if (num < 0)		//l'id deve essere un numero positivo
		throw Invalid();		//SCRIVERE CLASSE INVALID?
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
	delete[] components;
	components = nullptr;		//serve questa riga o è una cazzata?
	for (int i = 0; i < parts.size(); i++)
		components.push_back(parts[i]);
}

//modifica il prezzo del prodotto
void Elettrodomestico::setPrice(double prezzo)
{
	price = prezzo;
}

//calcola il prezzo del prodotto
double Elettrodomestico::calculatePrice(const vector<Componente>& pezzi)
{
	double sum = 0;
	for (int i = 0; i < pezzi.size(); i++)
		sum += pezzi[i].getPrice() * pezzi[i].getQuantity();
	return sum;
}







//ELETTRODOMESTICO IN ATTESA

//costruttore oggetto vuoto
Elettrodomestico_in_attesa::Elettrodomestico_in_attesa() 
{
	model = new Elettrodomestico();
	waiting_time = 0;
}

//costruttore oggetto
Elettrodomestico_in_attesa::Elettrodomestico_in_attesa(Elettrodomestico modello)
{
	model = modello;
	waiting_time = this.calculateTime();
}
//costruttore oggetto
Elettrodomestico_in_attesa::Elettrodomestico_in_attesa(Elettrodomestico modello, int time)
{
	model = modello;
	waiting_time = time;
}

//distruttore oggetto
Elettrodomestico_in_attesa::~Elettrodomestico_in_attesa() 
{
	//invoco il distruttore di Elettrodomestico;
	waiting_time = 0;
}


//restituisce il tempo di attesa
int Elettrodomestico_in_attesa::getTime()
{
	return waiting_time;
}

//restituisce il modello in attesa
Componente Elettrodomestico_in_attesa::getModel();
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
int calculateTime()
{
	int max = 0;
	vector<Componente> parti = model.getComponents();
	for (int i = 0; i < parti.size(); i++)
	{
		if (parti[i].getDeliveryTime() > max)		//guardo il tempo di spedizione dei componenti
			max = parti[i].getDeliveryTime();		//cerco il più grande
	}
	max += /*getMeseCorrente*/;						//aggiungo i mesi già grascorsi...
	return max + 1;									//... e il mese per la produzione
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
int Ordine::getTimeStamp()
{
	return time_stamp;
}

//restituisce il modello
int Ordine::getModelRequired()
{
	return model_required;
}

//restituisce la quantità di modelli
int Ordine::getQuantity()
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







//ORDINE IN ATTESA

//costruttore oggetto vuoto
Ordine_in_attesa::Ordine_in_attesa()
{
	order = new Ordine();
	total_price = 0;
	waiting_time = 0;
}

//costruttore oggetto ordine_in_attesa
Ordine_in_attesa::Ordine_in_attesa(Ordine ord, double price, Elettrodomestico_in_attesa item)
{
	order = ord;
	total_price = price;
	waiting_time = item.calculateTime();
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
Ordine Ordine_in_attesa::getOrder()
{
	return order
}

//restituisce quanti soldi guadagno da questo ordine
double Ordine_in_attesa::getTotalPrice(Elettrodomestico item)
{
	return this.getQuantity() * item.getPrice();
}

//restituisce il mese in cui verrà venduto l'ordine
int Ordine_in_attesa::getTime()
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
