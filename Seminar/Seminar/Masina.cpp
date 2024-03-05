//Aplicatie Masina : string marca, char* model, string nr_inmatriculare, static int total_masini_fabricate
//Metode:get si set (toti membrii sunt privati) + exemplificatie in main

#include<iostream>
using namespace std;

class Masina
{
	string marca;
	char* model;
	string nr_inmatriculare;
	static int total_masini_fabricate;
public:
	//Constructor

	Masina(string _marca, char* _model, string _nr_inmatriculare) : marca(_marca), nr_inmatriculare(_nr_inmatriculare)
	{
		
		this->model = new char[strlen(_model) + 1];
		strcpy_s(this->model, strlen(_model) + 1, _model);   //_model este un parametru al lui model 
		// this->set_model(_model); SAU ASA DACA AM SETTERUL FACUT DEJA

		incrementCarNr(); //asa e optim
	}

	//setters

	void set_Marca(string _marca)
	{
		this->marca = _marca; //pointer la obiectul curent
	}

	void set_NrInmatriculare(string _nr_inmatriculare)
	{
		this->nr_inmatriculare = _nr_inmatriculare;
	}

	void set_Model(char* _model)
	{
		this->model = new char[strlen(_model) + 1];
		strcpy_s(this->model, strlen(_model) + 1, _model);
	}

	//getters

	string get_Marca() { return this->marca; }
//	char* get_Model() { return this->model; }  //nu merge ca e shallow copy
	char* get_Model()
	{ 
		char* tmp = new char[strlen(this->model) + 1]; //facem copie
		strcpy_s(tmp, strlen(this->model) + 1, this->model);
	}
	string get_NrInmatriculare() { return this->nr_inmatriculare; }
	 
	static void incrementCarNr()
	{
		Masina::total_masini_fabricate++;
	}
	
};

int Masina::total_masini_fabricate = 0;

int main()
{
	Masina m("Dacia", (char*)"Spring", "B123AAA");
	//Masina::incrementCarNr(); merge si asa dar nu e optim

	Masina m1("Ford", (char*)"Focus", "B134BBB");
	//Masina::incrementCarNr();

	return 0;
}

// de facut destructori