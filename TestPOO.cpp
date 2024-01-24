#include <iostream>
using namespace std;

class Patient
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

	Patient() : id(0), name(nullptr), address(""), medicalInvestigationsCount(0), medicalInvestigations(nullptr), birthYear(0)
	{

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
		IncrementPatientsCount;
	}

	//Constructor de copiere

	Patient(Patient& p) : Patient(p.id, p.name, p.address, p.medicalInvestigationsCount, p.medicalInvestigations, p.birthYear)
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

	//Supraincarcare operaotrului "++"






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
		delete[] this->name;
		delete[] this->medicalInvestigations;
		DecrementPatientsCount;
	}
};

int Patient::patientsCount = 0;

int main()
{
	string* medicInv = new string[4];
	medicInv[1] = "Medic inv 1";
	medicInv[2] = "Medic inv 2";
	medicInv[3] = "Medic inv 3";

	Patient p1, p2(12345, "Cristi", "Bucuresti", 3, medicInv, 2002);
	p2 = p2;

	p1 = p2;


	return 0;
}