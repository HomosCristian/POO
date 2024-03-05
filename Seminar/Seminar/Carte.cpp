#include <iostream>
#include <string>

using namespace std;


class Carte
{
	char* titlu;
	string autor;
	int nr_pag;
	double pret;
	bool electronica;
	int* nr_cuv_pag;

	//Default constructor
	
public:

	Carte() 
	{


	}
	
	//Constructor cu parametrii

	Carte(char* _titlu, string _autor, int _nr_pag, double _pret, bool _electronica, int* _nr_cuv_pag) : autor(_autor), nr_pag(_nr_pag), pret(_pret), electronica(_electronica)
	{

		this->titlu = new char[strlen(_titlu) + 1];
		strcpy_s(this->titlu, strlen(_titlu) + 1, _titlu);

		this->nr_cuv_pag = new int[_nr_pag];
		for (int index = 0; index < _nr_pag; index++)
		{
			this->nr_cuv_pag[index] = _nr_cuv_pag[index];
		}

	}
	//Constructor de copiere

	Carte(const Carte& carte)
	{
		this->titlu = new char[strlen(carte.titlu) + 1];
		strcpy_s(this->titlu, strlen(carte.titlu) + 1, carte.titlu);

		this->autor = carte.autor;
		this->nr_pag = carte.nr_pag;
		this->pret = carte.pret;
		this->electronica = carte.electronica;


		this->nr_cuv_pag = new int[carte.nr_pag];
		for (int index = 0; index < carte.nr_pag; index++)
		{
			this->nr_cuv_pag[index] = carte.nr_cuv_pag[index];
		}

	}

	//Setters

	void set_nr_cuv_pag(int* _nr_cuv_pag, int _nr_pag)
	{
		this->nr_pag = _nr_pag;

		this->nr_cuv_pag = new int[nr_pag];
		for (int index = 0; index < _nr_pag; index++)
		{
			this->nr_cuv_pag[index] = _nr_cuv_pag[index];
		}
	}

	void set_autor(string _autor)
	{
		this->autor = _autor;
	}

	void set_nr_pag(int _nr_pag)
	{
		this->nr_pag = _nr_pag;
	}

	void set_pret(double _pret)
	{
		this->pret = _pret;
	}

	void set_electronica(bool _electronica)
	{
		this->electronica = _electronica;
	}

	void set_titlu(char* _titlu)
	{
		this->titlu = new char[strlen(_titlu) + 1];
		strcpy_s(this->titlu, strlen(_titlu) + 1, _titlu);
	}

	//Getters

	char* get_titlu() { return this->titlu; }
	string get_autor() { return this->autor; }
	int get_nr_pag() { return this->nr_pag; }
	double get_pret() { return this->pret; }
	bool get_electronica() { return this->electronica; }
	int* get_nr_cuv_pag() { return this->nr_cuv_pag; }

	//Destructor

	~Carte()
	{
		delete this->titlu;
		delete this->nr_cuv_pag;
	}

};


int main()
{
	Carte c0;

	c0.set_autor("Mihail Sadoveanu");
	c0.set_electronica(false);
	c0.set_nr_pag(300);
	c0.set_pret(50.45);
	
	c0.set_titlu((char*)"Baltagul");
	
	int nr_cuv_pag[5] = { 150, 143, 113, 123, 146 };
	c0.set_nr_cuv_pag(nr_cuv_pag, 5);

	
}