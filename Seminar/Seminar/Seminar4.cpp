// Lab01.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <conio.h>

using namespace std;


struct Student
{
	int id;
	char nume[32];
	char prenume[32];
	int data_nasterii[3];
	int calcul_profit()
	{
		return 20;
	}
};

// Structura care defineste un pacient ( minim 3 atribute, minim 3 tipuri de date, alocare dinamica pt c.p un atribut)
struct Pacient
{
	int id;
	char nume[32];
	char prenume[32];
	int* varsta;

};

class Test
{
public:
	char f[16];
};

int params_example_1(int param1, int* param2, char* param3);
int params_example_2(int param1, int* param2, char* param3);
void params_example_3(int param1[], char param2[]);
void params_example_4(int param1[], char param2[]);
void params_ex(int p1, int p2, int p3);


void params_struct_example(Student s);
void params_struct_example(Student* s);

void ref_param(Student& s);
void simple_param(Student s);



int main()
{
	int p1 = 5;
	int p2 = 12;
	char p3 = 'A';

	params_example_1(p1, &p2, &p3);  // dupa ce intram in fct, p1 nu se modifica pt ca a fost transim prin valoare (ctrl + click pt a intra  direct in fct)
	params_ex(p1, p2, p3);


	int  p11 = 35;
	int  p22[5] = { 1, 2, 3, 4, 5 };
	char p23[5] = "Test";

	params_example_2(p11, p22, p23);

	int  p31[5] = { 1, 2, 3, 4, 5 };
	char p32[5] = { 'T', 'e', 's', 't', '\0' };
	params_example_3(p31, p32);

	params_example_4(p31, p32);

	/////// Structuri de date ///////////

	Student s; //alocat static

	s.id = 12;
	strcpy_s(s.nume, "Popescu");   //folosim s.ceva pt ca e alocat static ( folosim -> pt dinamic)
	strcpy_s(s.prenume, "Cosmin");
	s.data_nasterii[0] = 22;
	s.data_nasterii[1] = 4;
	s.data_nasterii[2] = 2001;

	//Student s_test;
	//// Sa se seteze toate atributele cu '='

	//s_test.nume = "Popescu";     //nu merge
	//s_test.prenume = "Cosmin";
	//s_test.data_nasterii[] = { 22, 4, 2001 };

	ref_param(s);
	simple_param(s);
	Test yy;

	strcpy_s(yy.f, "testare");
	params_struct_example(s);

	params_struct_example(&s);

	Pacient p;

	p.id = 10;
	strcpy_s(p.nume, "Popescu");
	strcpy_s(p.nume, "Cosmin");
	p.varsta = new int(34);   //alocat dinamic

}

int params_example_1(int param1, int* param2, char* param3)
{
	param1 += 1;

	*param2 += 1;

	*param3 += 1;

	return 0;
}

int params_example_2(int param1, int* param2, char* param3)
{
	param1 += 1;

	param2[0] = 100;

	param3[1] = '#';

	return 0;
}

void params_example_3(int param1[], char param2[])  // se modifica valorile pt ca astepta un vector si se transmite direct prin adresa
{
	param1[0] = 100;

	param2[1] = '#';
}

void params_example_4(int param1[], char param2[])   //merge pt ca param1[] se transmite prin adresa
{
	params_example_2(0, param1, param2);
}

void params_struct_example(Student ls)
{
	ls.nume[0] = '#';
	ls.data_nasterii[0] = 0;
}

void params_struct_example(Student* ls)
{
	(*ls).nume[0] = '#';
	(*ls).data_nasterii[0] = 0;
}

void params_ex(int p1, int p2, int p3)
{


}

void ref_param(Student& s)  // se modifica din cauza referintei
{
	s.nume[0] = '@';
	s.data_nasterii[0] = -1;
}
void simple_param(Student s)
{
	s.nume[0] = '$';
	s.data_nasterii[0] = -2;
}