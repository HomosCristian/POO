#include <iostream>
using namespace std;

class Sejur {
	const int id;
	char* destinatie;
	int pretBaza;
	int nrExcursiiOptionale;
	int* pretExcursie;
public:
	Sejur() : id(0), pretBaza(0), nrExcursiiOptionale(0) {
		this->destinatie = new char[strlen("Unknown") + 1];
		strcpy_s(this->destinatie, strlen("Unknown") + 1, "Unknown");

		this->pretExcursie = nullptr;
	}

	Sejur(int _id, const char* _destinatie, int _pretBaza, int _nrExcursiiOptionale, int* _pretExcursie) : id(_id), pretBaza(_pretBaza), nrExcursiiOptionale(_nrExcursiiOptionale) {
		this->destinatie = new char[strlen(_destinatie) + 1];
		strcpy_s(this->destinatie, strlen(_destinatie) + 1, _destinatie);

		if (_nrExcursiiOptionale > 0 && _pretExcursie != nullptr) {
			this->pretExcursie = new int[this->nrExcursiiOptionale];
			for (int i = 0; i < this->nrExcursiiOptionale; i++) {
				this->pretExcursie[i] = _pretExcursie[i];
			}
		}
		else {
			this->pretExcursie = nullptr;
			this->nrExcursiiOptionale = 0;
		}
	}

	Sejur(const Sejur& s): id(s.id), pretBaza(s.pretBaza), nrExcursiiOptionale(s.nrExcursiiOptionale) {
		this->destinatie = new char[strlen(s.destinatie) + 1];
		strcpy_s(this->destinatie, strlen(s.destinatie) + 1, s.destinatie);

		if (s.nrExcursiiOptionale > 0 && s.pretExcursie != nullptr) {
			this->pretExcursie = new int[this->nrExcursiiOptionale];
			for (int i = 0; i < this->nrExcursiiOptionale; i++) {
				this->pretExcursie[i] = s.pretExcursie[i];
			}
		}
		else {
			this->pretExcursie = nullptr;
			this->nrExcursiiOptionale = 0;
		}
	}

	Sejur operator=(const Sejur& s) {
		if (this != &s) {
			delete[] this->destinatie;
			delete[] this->pretExcursie;

			this->pretBaza = s.pretBaza;
			this->nrExcursiiOptionale = s.nrExcursiiOptionale;

			this->destinatie = new char[strlen(s.destinatie) + 1];
			strcpy_s(this->destinatie, strlen(s.destinatie) + 1, s.destinatie);

			if (s.nrExcursiiOptionale > 0 && s.pretExcursie != nullptr) {
				this->pretExcursie = new int[this->nrExcursiiOptionale];
				for (int i = 0; i < this->nrExcursiiOptionale; i++) {
					this->pretExcursie[i] = s.pretExcursie[i];
				}
			}
			else {
				this->pretExcursie = nullptr;
				this->nrExcursiiOptionale = 0;
			}
		}
		return *this;
	}

	friend ostream& operator<<(ostream& out, const Sejur& s) {
		out << "\nId: " << s.id;
		out << "\nDestinatia: " << s.destinatie;
		out << "\nPret baza: " << s.pretBaza;
		out << "\nNr excursii optionale: " << s.nrExcursiiOptionale;
		out << "\nPreturi: ";
		for (int i = 0; i < s.nrExcursiiOptionale; i++) {
			out << s.pretExcursie[i];
		}
		return out;
	}

	friend istream& operator>>(istream& in, Sejur& s) {
		cout << "Introduceti destinatia: ";
		char buffer[100];
		in >> ws;
		in.getline(buffer, 99);
		if (s.destinatie != nullptr) {
			delete[] s.destinatie;
		}
		s.destinatie = new char[strlen(buffer) + 1];
		strcpy_s(s.destinatie, strlen(buffer) + 1, buffer);

		cout << "Introduceti pretul de baza: ";
		in >> s.pretBaza;

		cout << "Introduceti nr de excursii optionale: ";
		in >> s.nrExcursiiOptionale;

		
		cout << "Introduceti preturile: ";
		s.pretExcursie = new int[s.nrExcursiiOptionale];
		for (int i = 0; i < s.nrExcursiiOptionale; i++) {
			in >> s.pretExcursie[i];
		}


		return in;
	}
};

int main() {

	int preturi[] = { 200, 100, 500 };
	Sejur s1, s2(10, "Grecia", 2000, 3, preturi);

	cout << s2 << endl;
	s1 = s2;

	cout << s1 << endl;

	//float pretTotal = float(s2);
	//cout <<endl<< pretTotal << endl;

	Sejur s3;
	cin >> s3;
	return 0;
}