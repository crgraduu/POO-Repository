#include <iostream>
#include <cstring>
using namespace std;

class Calatorie {
private:
    char* numeDestinatie;     // atribut alocat dinamic
    const int idCalatorie;    // atribut constant

public:

    // Constructor cu un parametru
    Calatorie(int id)
        : idCalatorie(id)
    {
        numeDestinatie = new char[strlen("Necunoscut") + 1];
        strcpy_s(numeDestinatie, strlen("Necunoscut")+1, "Necunoscut");
    }

    // Getter pentru atributul constant
    int getId() const {
        return idCalatorie;
    }

    // Setter pentru destinatie
    void setDestinatie(const char* destinatie) 
    {
        if (numeDestinatie)
            delete[] numeDestinatie;

        numeDestinatie = new char[strlen(destinatie) + 1];
        strcpy_s(numeDestinatie, strlen(destinatie)+1, destinatie);
    }

    // Operator =
    Calatorie& operator=(const Calatorie& c) {
        if (this != &c) 
        {
            if (numeDestinatie)
                delete[] numeDestinatie;

            numeDestinatie = new char[strlen(c.numeDestinatie) + 1];
            strcpy_s (numeDestinatie, strlen(c.numeDestinatie) + 1,  c.numeDestinatie);
        }
        return *this;
    }

    // Operator functie: modifica numele destinatiei
    void operator()(const char* nouaDestinatie) {
        setDestinatie(nouaDestinatie);
    }

    // Metoda de afisare
    void afisare() const {
        cout << "Calatorie #" << idCalatorie
            << " spre: " << numeDestinatie << endl;
    }

    // Destructor
    ~Calatorie() {
        delete[] numeDestinatie;
    }
};

int main() {

    // Test constructor
    Calatorie c1(101);
    c1.afisare();

    // Test setter
    c1.setDestinatie("Paris");
    c1.afisare();

    // Test operator=
    Calatorie c2(202);
    c2 = c1;
    c2.afisare();

    // Test operator functie (modifica destinatie)
    c1("Barcelona");
    c1.afisare();

    return 0;
}
