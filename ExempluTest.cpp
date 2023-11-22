/*
Sa se implementeze o clasa spital conform urm cerinte:
   Clasa are cel putin urmatoarele atribute:
     * cif (cod de identificare fiscala - valoare de tip sir de caractere - sa atibuie valoare la crearea obiectului si sa nu mai poata fi modificata)
     * nume ( sir de caractere )
     * adresa - | | -
     * medici ( vector de valori string, alocat dinamic )
     * nrMedici
     * nrSpitale ( va retine nr de sptale - obiecte de tipul spital - instatiate vreodata - static int

   Se vor implementa:
- constructor fara parametrii
- constructor cu toti parametrii necesari instantierii unui obiect complet
- constructor de copiere
- destructor

- supraincarcare operator =
- supraincarcare operatori de citire si scriere din/in consola (>> si <<)
- supraincarcare operator [] - returneaza medicul de pe o pozitie data (atat in mod scriere cat si in mod citire)
- supraincarcare operaotr !
- cast explicit int

- metodele get si set
- cel putin unul dintre atributele de tip sir de caractere trebuie sa fie de tip char*
- toate atributele trebuie sa fie private
*/

#include <iostream>
using namespace std;

class Spital
{
    const string cif;
    char* nume;
    string adresa;
    string* medici;
    int nrMedici;
    static int nrSpitale;

public:

    //Constructor fara parametrii

    Spital() : cif(""), nume(nullptr), adresa(""), medici(nullptr), nrMedici(0)
    {

    }

    //Constructor cu toti parametrii

    Spital( string _cif,const char* _nume, string _adresa, const string* _medici, int _nrMedici) : cif(_cif), adresa(_adresa), nrMedici(_nrMedici)
    {
        if (this->nume != nullptr)
        {
            this->nume = new char[strlen(_nume) + 1];
            strcpy_s(this->nume, strlen(_nume) + 1, _nume);
        }
        else
            this->nume = nullptr;

        this->medici = new string[_nrMedici];
        for (int i = 0; i < _nrMedici; i++)
        {
            this->medici[i] = _medici[i];
        }
        incrementSpital();
    }

    //Constructor de copiere

    Spital(Spital& s) : Spital(s.cif, s.nume, s.adresa, s.medici, s.nrMedici)
    {

    }

    //Getters

    const string get_cif() { return this->cif; }
    
    char* get_nume()
    {
      char* copy = new char [strlen(nume) + 1];
      strcpy_s(copy, strlen(this->nume) + 1, this->nume);
    }
   
    string get_adresa() { return this->adresa; }
    
    string* get_medici()
    {
        string* copy = new string[nrMedici];
        for (int i = 0; i < nrMedici; i++)
        {
            copy[i] = medici[i];
        }
    }
    int get_nrMedici() { return this->nrMedici; }

    //Setters

    void set_nume(const char* _nume)
    {
        if (_nume != nullptr)
        {
            delete[] this->nume;
            this->nume = new char[strlen(_nume) + 1];
            strcpy_s(this->nume, strlen(_nume) + 1, _nume);
        }
        else this->nume = nullptr;
       
    }

    void set_adresa(string _adresa)
    {
        this->adresa = _adresa;
    }

    void set_medici(string* _medici, int _nrMedici)
    {
        this->nrMedici = _nrMedici;

        this->medici = new string[nrMedici] + 1;
        for (int i = 0; i < _nrMedici; i++)
        {
            this->medici[i] = _medici[i];
        }
    }

    void set_nrMedici(int _nrMedici)
    {
        this->nrMedici = _nrMedici;
    }
      
    static void incrementSpital()
    {
        Spital::nrSpitale++;
    }

    //Supraincarcare oprator =
    
    Spital& operator = (Spital s)
    {
        if (this == &s)
        {
            return *this;
        }

        delete[] this->nume;
        this->nume = new char[strlen(s.nume) + 1];
        strcpy_s(nume, strlen(s.nume) + 1, s.nume);

        delete[] this->medici;
        this->medici = new string[s.nrMedici];
        for (int i = 1; i < s.nrMedici; i++)
        {
            this->medici[i] = s.medici[i];
        }

        this->adresa = s.adresa;
        this->nrMedici = s.nrMedici;


        return *this;
    }
    //Destructor
    
    ~Spital()
    {
        delete[] this->nume;
        delete[] this->medici;
        Spital::nrSpitale--;
    }
};

int Spital::nrSpitale = 0;


int main()
{
    return 0;
}