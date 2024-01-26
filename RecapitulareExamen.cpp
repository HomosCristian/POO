#include <iostream>
#include <fstream>
#include<string>
using namespace std;

class AbstractPur
{
public:
	virtual string AfiseazaUnMesaj() = 0;
};


class Patient: public AbstractPur
{
	int id;
	char* name;
	string address;
	int medicalInvestigationsCount;
	string* medicalInvestigations;
	int birthYear;
	static int patientsCount;

public:

	//Constructor fara parametrii

	Patient() 
	{
		this->id = 00000;
		this->name = new char[strlen("NuStim") + 1];//aici alocam spatiu, iar +1 este pentru terminatorul de sir
		strcpy_s(this->name, strlen("NuStim") + 1, "NuStim");
		this->medicalInvestigationsCount = 0;
		this->medicalInvestigations = nullptr;
		this->birthYear = 0;
	}

	//Constructor cu parametrii

	Patient(int _id, const char* _name, string _address, int _medicalInvestigationsCount, const string* _medicalInvestigations, int _birthYear) : id(_id), address(_address), medicalInvestigationsCount(_medicalInvestigationsCount), birthYear(_birthYear)
	{

		this->name = new char[strlen(_name) + 1];
		strcpy_s(name, strlen(_name) + 1, _name);

		this->medicalInvestigations = new string[_medicalInvestigationsCount];
		for (int i = 0; i < _medicalInvestigationsCount; i++)
		{
			this->medicalInvestigations[i] = _medicalInvestigations[i];
		}
		IncrementPatientsCount();
	}

	//Constructor de copiere

	Patient(const Patient& p) : Patient(p.id, p.name, p.address, p.medicalInvestigationsCount, p.medicalInvestigations, p.birthYear)
	{

	}

	//Getters

	int get_id() { return this->id; }

	char* get_name()
	{
		delete[] this->name;
		char* copy = new char[strlen(name) + 1];
		strcpy_s(copy, strlen(name) + 1, name);
	}

	string get_address() { return this->address; }

	int get_medicalInvestigationsCount() { return this->medicalInvestigationsCount; }

	string* get_medicalInvestigations()
	{
		delete[] this->medicalInvestigations;
		string* copy = new string[medicalInvestigationsCount];
		for (int i = 0; i < medicalInvestigationsCount; i++)
		{
			copy[i] = medicalInvestigations[i];
		}
	}

	int get_birthYear() { return this->birthYear; }

	static int get_patientsCount()
	{
		return Patient::patientsCount;
	}

	//Seters

	void set_id(int _id)
	{
		this->id = _id;
	}

	void set_name(const char* _name)
	{
		delete[] this->name;
		this->name = new char[strlen(_name) + 1];
		strcpy_s(name, strlen(_name) + 1, _name);
	}

	void set_address(string _adress)
	{
		this->address = _adress;
	}

	void set_medicalInvestigationsCount(int _medicalInvestigationsCount)
	{
		this->medicalInvestigationsCount = _medicalInvestigationsCount;
	}

	void set_medicalInvestigations(const string* _medicalInvestigations, int _medicalInvestigationsCount)
	{
		delete[] medicalInvestigations;
		this->medicalInvestigations = new string[_medicalInvestigationsCount];
		for (int i = 1; i < _medicalInvestigationsCount; i++)
		{
			this->medicalInvestigations[i] = _medicalInvestigations[i];
		}
	}

	//Supraincarcare operator "="

	Patient& operator = (Patient p)
	{
		if (this == &p)
		{
			return *this;
		}

		this->id = p.id;
		this->address = p.address;
		this->medicalInvestigationsCount = p.medicalInvestigationsCount;
		this->birthYear = p.birthYear;

		delete[] this->name;
		this->name = new char[strlen(p.name) + 1];
		strcpy_s(name, strlen(p.name) + 1, p.name);

		delete[] this->medicalInvestigations;
		this->medicalInvestigations = new string[p.medicalInvestigationsCount];
		for (int i = 0; i < p.medicalInvestigationsCount; i++)
		{
			this->medicalInvestigations[i] = p.medicalInvestigations[i];
		}

		return *this;
	}

	//Supraincarcare !

	bool operator!() {
		if (name != nullptr)
			return true;
		else
			return false;
		
	}

	//Supraincarcare []
	//int& operator[](int index)
	//{
	//	if (index >= 0 && index < medicalInvestigationsCount)
	//	{
	//		return medicalInvestigations[index] ;  //Merge daca medicalinvestigations era tot un int
	//	}
	//	throw exception("index invalid");
	//}

	//Supraincarcare preincrementare
	Patient operator++()
	{
		this->birthYear++;
		return *this;
	}

	//Supraincarcare postincrementare
	Patient operator++(int i)
	{
		Patient copie = *this;
		this->birthYear += i;//nu e implementata bine, i trebuie sa fie 1
		return copie;
	}

	//Supraincarcare op+

	Patient operator+(int valoare)
	{
		Patient copie = *this;
		copie.birthYear += valoare;
		return copie;
	}

	//Supraincarcare cast
	explicit operator int()
	{
		return birthYear;
	}

	//Supraincarcare operaotrului afisare

	friend ostream& operator<<(ostream& os, const Patient& p)
	{
		os << p.id << endl;
		os << p.name << endl;
		os << p.address << endl;
		os << p.medicalInvestigationsCount << endl;
		for (int i = 0; i < p.medicalInvestigationsCount; i++)
		{
			os << p.medicalInvestigations[i] << ", ";
		}
		os << endl;
		os << p.birthYear << endl;
		os << p.patientsCount << endl;
		return os;
	}

	friend istream& operator>>(istream& is, Patient& p)
	{

		cout << "Introduceti ID-ul pacientului:   ";
		is >> p.id;

		//citire pt char*
		cout << "Introduceti numele pacientului:   ";
		char aux[100];
		is >> ws;
		is.getline(aux, 99);
		if (p.name != nullptr)
		{
			delete[]p.name;
		}
		p.name = new char[strlen(aux) + 1];
		strcpy_s(p.name, strlen(aux) + 1, aux);

		cout << "Introduceti adresa pacientului:  ";
		is >> p.address;

		cout << "Introduceti numarul de inverstigatii medicale:  ";
		is >> p.medicalInvestigationsCount;
		if (p.medicalInvestigations != nullptr)
		{
			delete[]p.medicalInvestigations;
		}
		p.medicalInvestigations = new string[p.medicalInvestigationsCount];

		cout << "Introduceti denumirea investigatiei:  ";
		for (int i = 0; i < p.medicalInvestigationsCount; i++)
		{
			is >> p.medicalInvestigations[i];
		}

		cout << "Introduceti anul nasterii pacientului:  ";
		is >> p.birthYear;



		return is;
	}

	//Fisiere
	friend ofstream& operator<<(ofstream& os, const Patient& p)
	{
		os << p.id << endl;
		os << p.name << endl;
		os << p.address << endl;
		os << p.medicalInvestigationsCount << endl;
		for (int i = 0; i < p.medicalInvestigationsCount; i++)
		{
			os << p.medicalInvestigations[i] << endl;
		}

		os << p.birthYear << endl;
		os << p.patientsCount << endl;
		return os;
	}


	friend ifstream& operator>>(ifstream& is, Patient& p)
	{


		is >> p.id;


		//citire pt char*
		char aux[100];
		is >> ws;
		is.getline(aux, 99);
		if (p.name != nullptr)
		{
			delete[]p.name;
		}
		p.name = new char[strlen(aux) + 1];
		strcpy_s(p.name, strlen(aux) + 1, aux);


		is >> p.address;

		is >> p.medicalInvestigationsCount;
		if (p.medicalInvestigations != nullptr)
		{
			delete[]p.medicalInvestigations;
		}
		p.medicalInvestigations = new string[p.medicalInvestigationsCount];


		for (int i = 0; i < p.medicalInvestigationsCount; i++)
		{
			is >> p.medicalInvestigations[i];
		}

		is >> p.birthYear;



		return is;
	}

	


	//Metode pt static

	static void IncrementPatientsCount()
	{
		Patient::patientsCount++;
	}

	static void DecrementPatientsCount()
	{
		Patient::patientsCount--;
	}

	//Destructor

	~Patient()
	{
		if (this->name != nullptr)
		{
			delete[] this->name;
		}
		if (this->medicalInvestigations != nullptr)
		{
			delete[] this->medicalInvestigations;
		}
		if (this->patientsCount = NULL)
		{
			DecrementPatientsCount();
		}
	}

	//Functie virtuala
	virtual string afiseazaTipulClasei()
	{
		return "Patient";
	}

	//Functie clasa abstracata

	string AfiseazaUnMesaj()
	{
		return "Acest pacient nu este la terapie intensiva";
	}

};

//Comutativitatea ppt op +
Patient operator+(int valoare, Patient p)
{
	//nu este nevoie sa facem o copie locala
	//deoarece s este transmis prin valoare
	//p.birthYear += valoare;       ???????????????
	return p;
}


int Patient::patientsCount = 0;

class PatientIntensiveCare : public Patient
{
	int priority;
	string complications;
public:
	//Constructor default
	PatientIntensiveCare() : Patient()  
	{
		this->priority = 0;
		this->complications = "NuStim";

	}
	//Constructor cu param
	PatientIntensiveCare(int _id, const char* _name, string _address, int _medicalInvestigationsCount, const string* _medicalInvestigations, int _birthYear, int _priority, string _complications) : Patient( _id, _name, _address, _medicalInvestigationsCount, _medicalInvestigations, _birthYear)
	{
		this->priority = _priority;
		this->complications = _complications;

	}

	//Constructor de copiere
	PatientIntensiveCare(const PatientIntensiveCare& pi) : Patient(pi)
	{

		this->priority = pi.priority;
		this->complications = pi.complications;
	}

	//Destructor
	~PatientIntensiveCare()
	{

	}

	//Operatorul =
	PatientIntensiveCare& operator=(const PatientIntensiveCare& pi)
	{
		if (this != &pi)
		{
			Patient::operator=(pi);   //upcasting
			this->priority = pi.priority;
			this->complications = pi.complications;
		}
		return *this;
	}

	//downcasting
	PatientIntensiveCare(const Patient& p) : Patient(p)
	{
		this->priority = 3;
		this->complications = "ceva naspa";

	}

	friend ostream& operator << (ostream& os, const PatientIntensiveCare& pi)
	{
		os << (Patient&)pi << endl;   //Apelam din clasa de baza
		os << pi.priority << endl;
		os << pi.complications << endl;
		return os;
	}

	string afiseazaTipulClasei()
	{
		return "Patient Intensive Care";
	}

	string AfiseazaUnMesaj()
	{
		return "Acest pacient este la terapie intensiva";
	}
};

int main()
{
	string* medicInv = new string[4];
	medicInv[1] = "Medic inv 1";
	medicInv[2] = "Medic inv 2";
	medicInv[3] = "Medic inv 3";

	Patient p1, p2(12345, "Cristi", "Bucuresti", 3, medicInv, 2002);

	//Testare operator =
	/*p2 = p2;

	p1 = p2;*/

	//Testare operator afisare/ scriere

	/*cin >> p1;
	cout << endl;
	cout << p1 << endl;*/

	//Testare fisiere

	/*ofstream f("exemplu1.txt", ios::out);
	f << p1;
	f.close();*/

	/*Patient pCitireText;
	cout << pCitireText << endl;
	ifstream g("exemplu2.txt", ios::in);*/
	
	//Testare mostenire/specializare

	PatientIntensiveCare pi1;
	cout << pi1 << endl;

	PatientIntensiveCare pi2(12345, "Cristi", "Bucuresti", 4, medicInv, 2002, 2, "ceva rau");
	cout << pi2 << endl;

	PatientIntensiveCare pi3 = pi1;
	cout << pi3 << endl;
	pi2 = pi1;
	cout << pi2 << endl;

	PatientIntensiveCare pi4;
	Patient pUpCasting = pi4;

	//Testare virtualizare

	Patient* p5 = new Patient();
    PatientIntensiveCare* p6 = new PatientIntensiveCare();

	cout << p5->afiseazaTipulClasei() << endl;
	cout << p6->afiseazaTipulClasei() << endl;

	cout << p5->AfiseazaUnMesaj() << endl;
	cout << p6->AfiseazaUnMesaj() << endl;


	return 0;
}