#include <iostream>
using namespace std;

class Patient
{
	const int id;
	char* name;
	string address;
	int medicalInvestigationsCount;
	string* medicalInvestigations;
	int birthYear;
	static int patientsCount;

public:

	//Constructor default
	Patient() : id(++patientsCount), address(""), medicalInvestigationsCount(0), birthYear(0) {
		this->name = nullptr;
		this->medicalInvestigations = nullptr;
	}

	//Constructor cu toti parametrii
	Patient(const char* _name, string _address, int _medicalInvestigationsCount, string* _medicalInvestigations, int _birthYear) : id(++patientsCount), address(_address), medicalInvestigationsCount(_medicalInvestigationsCount), birthYear(_birthYear) {

		this->name = new char[strlen(_name) + 1];
		strcpy_s(this->name, strlen(_name) + 1, _name);


		if (this->medicalInvestigations != nullptr && this->medicalInvestigationsCount > 0) {
			this->medicalInvestigations = new string[_medicalInvestigationsCount];
			for (int i = 0; i < _medicalInvestigationsCount; i++) {
				this->medicalInvestigations[i] = _medicalInvestigations[i];
			}
		}
		else {
			this->medicalInvestigations = nullptr;
			this->medicalInvestigationsCount = 0;
		}
	}

	//Constructor de copiere
	Patient(const Patient& p) : id(++patientsCount), address(p.address), medicalInvestigationsCount(p.medicalInvestigationsCount), birthYear(p.birthYear) {
		this->name = new char[strlen(p.name) + 1];
		strcpy_s(this->name, strlen(p.name) + 1, p.name);


		if (this->medicalInvestigations != nullptr && this->medicalInvestigationsCount > 0) {
			this->medicalInvestigations = new string[p.medicalInvestigationsCount];
			for (int i = 0; i < p.medicalInvestigationsCount; i++) {
				this->medicalInvestigations[i] = p.medicalInvestigations[i];
			}
		}
		else {
			this->medicalInvestigations = nullptr;
			this->medicalInvestigationsCount = 0;
		}
	}

	//Destructor
	~Patient() {
		delete[] this->name;
		delete[] this->medicalInvestigations;
		patientsCount--;
	}

	//Getters

	int getId() const {
		return this->id;
	}
	 
	const char* getName() const  {
		return	this->name;
	}

	string getAddress() const {
		return this->address;
	}

	int getMedicalInvestigationsCount() const {
		return this->medicalInvestigationsCount;
	}

	string* getMedicalInvestigations() const {
		return this->medicalInvestigations;
	}

	int getBirthYear() const {
		return this->birthYear;
	}

	//Setters

	void setName(const char* _name) {
		delete[] this->name;
		this->name = new char[strlen(_name) + 1];
		strcpy_s(this->name, strlen(_name) + 1, _name);
	}

	void setAddress(string _address) {
		this->address = _address;
	}

	void setMedicalInvestigations(string* _medicalInvestigations, int _medicalInvestigationsCount) {
		delete[] this->medicalInvestigations;
		if (this->medicalInvestigations != nullptr && this->medicalInvestigationsCount > 0) {
			this->medicalInvestigations = new string[_medicalInvestigationsCount];
			for (int i = 0; i < _medicalInvestigationsCount; i++) {
				this->medicalInvestigations[i] = _medicalInvestigations[i];
			}
		}
		else {
			this->medicalInvestigations = nullptr;
			this->medicalInvestigationsCount = 0;
		}
	}

	void setBirthYear(int _birthYear) {
		this->birthYear = _birthYear;
	}

	//Operatori
	Patient& operator=(const Patient& other) {
		if (this != &other) { // Evită auto-atribuirea
			// Eliberează memoria existentă
			delete[] this->name;
			delete[] this->medicalInvestigations;

			// Copiază numele
			if (other.name != nullptr) {
				this->name = new char[strlen(other.name) + 1];
				strcpy_s(this->name, strlen(other.name) + 1, other.name);
			}
			else {
				this->name = nullptr;
			}

			// Copiază adresa
			this->address = other.address;

			// Copiază investigațiile medicale
			if (other.medicalInvestigations != nullptr && other.medicalInvestigationsCount > 0) {
				this->medicalInvestigationsCount = other.medicalInvestigationsCount;
				this->medicalInvestigations = new string[other.medicalInvestigationsCount];
				for (int i = 0; i < other.medicalInvestigationsCount; i++) {
					this->medicalInvestigations[i] = other.medicalInvestigations[i];
				}
			}
			else {
				this->medicalInvestigations = nullptr;
				this->medicalInvestigationsCount = 0;
			}

			// Copiază anul nașterii
			this->birthYear = other.birthYear;

			// NOTĂ: `id` rămâne neschimbat deoarece este `const`
		}
		return *this;
	}

};

int Patient::patientsCount = 0;

int main() {


	//string* medicInv = new string[4];
	//medicInv[0] = "Medic inv 1";
	//medicInv[1] = "Medic inv 2";
	//medicInv[2] = "Medic inv 3";

	string medicInv[] = { "m1", "m2", "m3" };


	Patient p1, p2("Cristi", "Bucuresti", 3, medicInv, 2002);
	cout << p2.getName();

	p1 = p2;
	cout << endl << p1.getName();

	return 0;
}