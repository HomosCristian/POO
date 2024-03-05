#include <iostream>
#include <string>
using namespace std;


class A {

	string attrA= " ";
public:

	A(string attrA) : attrA(attrA) {}
	string show()
	{
		cout << " Eu sunt A";
	}
	
};

class B : public A {
	string attrB;
public:

	B(string attrA, string attrB) : A(attrA), attrB(attrB) {}
	string show() override
};

void show(A) {

}

int main()
{
	A** vect = new A * [4];
	vect[0] = new A("ddf");
	vect[1] = new B("ddfedf", "svfevd");
	vect[2] = new B("ddvvfdsvsdf", "geviug");
	vect[3] = new A("ddf");
	// populam pozitiile



	cout << vect[0]->show() << endl;
	cout << vect[1]->show() << endl;
	cout << vect[2]->show() << endl;
	cout << vect[3]->show() << endl;

	return 0;
}