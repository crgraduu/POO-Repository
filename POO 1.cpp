// POO 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

// Clasa 1: Camera
class Camera {
private:
    string marca;
    int megapixeli;
    float pret;
    bool areStabilizare;

public:
    
    Camera(string m, int mp, float p, bool stab)
        : marca(m), megapixeli(mp), pret(p), areStabilizare(stab) {
    }

    void afisare() {
        cout << "Camera " << marca << " cu " << megapixeli
            << "MP, pret: " << pret << " lei, "
            << (areStabilizare ? "cu" : "fara") << " stabilizare." << endl;
    }
};

// Clasa 2: Card
class Card {
private:
    string tip;
    int capacitateGB;
    int vitezaScriereMB; 

public:
    Card(string t, int cap, int viteza)
        : tip(t), capacitateGB(cap), vitezaScriereMB(viteza) {
    }

    void afisare() {
        cout << "Card " << tip << " de " << capacitateGB << "GB, "
            << "viteza scriere: " << vitezaScriereMB << " MB/s." << endl;
    }
};

// Clasa 3: Incarcator
class Incarcator {
private:
    string tipConector;
    float voltaj;
    bool incarcareRapida;

public:
    Incarcator(string tip, float v, bool fast)
        : tipConector(tip), voltaj(v), incarcareRapida(fast) {
    }

    void afisare() {
        cout << "Incarcator cu conector " << tipConector
            << ", " << voltaj << "V, "
            << (incarcareRapida ? "cu incarcare rapida." : "fara incarcare rapida.") << endl;
    }
};

// Program principal
int main() {
    Camera c1("Canon", 24, 2500.5, true);
    Card card1("SDXC", 128, 90);
    Incarcator inc1("USB-C", 5.0, true);

    c1.afisare();
    card1.afisare();
    inc1.afisare();

    return 0;
}

