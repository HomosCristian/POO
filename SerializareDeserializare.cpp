#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Person {
public:
    Person() : name(nullptr), age(0), address(nullptr) {}
    Person(const string& n, int a, const string& m) : age(a) {
        name = new char[n.size() + 1];
        strcpy_s(name, n.size() + 1, n.c_str());

        address = new char[m.size() + 1];
        strcpy_s(address, m.size() + 1, m.c_str());
    }

    // Destructor pentru a elibera memoria alocata dinamic
    ~Person() {
        delete[] name;
        delete[] address;
    }

    // Funcție de serializare
    void Serialize(ofstream& ofs) const {
        size_t nameLength = strlen(name) + 1;
        ofs.write(reinterpret_cast<const char*>(&nameLength), sizeof(nameLength)); // Scriem lungimea numelui
        ofs.write(name, nameLength);
        ofs.write(reinterpret_cast<const char*>(&age), sizeof(age));

        size_t addressLength = strlen(address) + 1;
        ofs.write(reinterpret_cast<const char*>(&addressLength), sizeof(addressLength)); // Scriem lungimea numelui
        ofs.write(address, addressLength);
       
    }

    // Funcție de deserializare
    void Deserialize(ifstream& ifs) {
        size_t nameLength;
        ifs.read(reinterpret_cast<char*>(&nameLength), sizeof(nameLength)); // Citim lungimea numelui
        delete[] name;
        name = new char[nameLength];
        ifs.read(name, nameLength);
        ifs.read(reinterpret_cast<char*>(&age), sizeof(age));

        size_t addressLength;
        ifs.read(reinterpret_cast<char*>(&addressLength), sizeof(addressLength)); // Citim lungimea numelui
        delete[] address;
        address = new char[addressLength];
        ifs.read(address, addressLength);


    }

    void DisplayInfo() const {
        cout << "Name: " << name << ", Age: " << age << ", Address: "<< address<< endl;
    }

private:

    char* address;
    char* name;
    int age;
};

int main() {
    // Salvare obiect într-un fișier binar
    {
        ofstream outputFile("person.dat", ios::binary);
        if (!outputFile) {
            cerr << "Error opening file for writing." << endl;
            return 1;
        }

        //Person personToSave("John Doe", 25);
        //personToSave.Serialize(outputFile);

        Person personToSave("John Doe", 25, "Bucuresti");
        personToSave.Serialize(outputFile);

       
    }

    // Restaurare obiect din fișier binar
    {
        ifstream inputFile("person.dat", ios::binary);
        if (!inputFile) {
            cerr << "Error opening file for reading." << endl;
            return 1;
        }

        Person restoredPerson;
        restoredPerson.Deserialize(inputFile);

        cout << "Object restored successfully." << endl;
        restoredPerson.DisplayInfo();
    }

    return 0;
}
