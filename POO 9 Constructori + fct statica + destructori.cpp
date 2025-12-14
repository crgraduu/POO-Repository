#include <iostream>
#include <string>
using namespace std;

class Camera {
public:
    const int idCamera;      // atribut constant
    string* marca;           // pointer heap
    int megapixeli;
    float pret;
    bool areStabilizare;
    static int numarCamere;  // atribut static

    // Constructor 1: toate atributele
    Camera(int id, const string& m, int mp, float p, bool stab)
        : idCamera(id), megapixeli(mp), pret(p), areStabilizare(stab)
    {
        marca = new string(m);
        numarCamere++;
    }

    // Constructor 2: doar id si marca
    Camera(int id, const string& m)
        : idCamera(id), megapixeli(0), pret(0), areStabilizare(false)
    {
        marca = new string(m);
        numarCamere++;
    }

    // Constructor 3: fara parametri
    Camera()
        : idCamera(0), megapixeli(0), pret(0), areStabilizare(false)
    {
        marca = new string("Necunoscut");
        numarCamere++;
    }

    ~Camera() 
    {
        delete marca;
        numarCamere--;
    }

    void afisare()
    {
        cout << "Camera #" << idCamera
            << " - " << *marca
            << " cu " << megapixeli
            << "MP, pret: " << pret << " lei, "
            << (areStabilizare ? "cu " : "fara ")
            << "stabilizare. Total camere: " << numarCamere
            << endl;
    }
    static int getNumarCamere() 
    {
        return numarCamere;
    }
};

int Camera::numarCamere = 0;

class Card {
public:
    const int idCard;       // atribut constant
    string* tip;            // pointer heap
    int capacitateGB;
    int vitezaScriereMB;
    static int numarCarduri; // atribut static

    // Constructor 1
    Card(int id, const string& t, int cap, int viteza)
        : idCard(id), capacitateGB(cap), vitezaScriereMB(viteza)
    {
        tip = new string(t);
        numarCarduri++;
    }

    // Constructor 2
    Card(int id, const string& t)
        : idCard(id), capacitateGB(0), vitezaScriereMB(0)
    {
        tip = new string(t);
        numarCarduri++;
    }

    // Constructor 3
    Card()
        : idCard(0), capacitateGB(0), vitezaScriereMB(0)
    {
        tip = new string("Necunoscut");
        numarCarduri++;
    }

    ~Card() 
    {
        delete tip;
        numarCarduri--;
    }

    void afisare()
    {
        cout << "Card #" << idCard
            << " - " << *tip
            << " de " << capacitateGB
            << "GB, viteza scriere: " << vitezaScriereMB
            << " MB/s. Total carduri: " << numarCarduri
            << endl;
    }
    static int getNumarCarduri() 
    {
        return numarCarduri;
    }
};

int Card::numarCarduri = 0;

class Incarcator {
public:
    const int idIncarcator;  // atribut constant
    string* tipConector;      // pointer heap
    float voltaj;
    bool incarcareRapida;
    static int numarIncarcatoare; // atribut static

    // Constructor 1
    Incarcator(int id, const string& tip, float v, bool fast)
        : idIncarcator(id), voltaj(v), incarcareRapida(fast)
    {
        tipConector = new string(tip);
        numarIncarcatoare++;
    }

    // Constructor 2
    Incarcator(int id, const string& tip)
        : idIncarcator(id), voltaj(0), incarcareRapida(false)
    {
        tipConector = new string(tip);
        numarIncarcatoare++;
    }

    // Constructor 3
    Incarcator()
        : idIncarcator(0), voltaj(0), incarcareRapida(false)
    {
        tipConector = new string("Necunoscut");
        numarIncarcatoare++;
    }

    ~Incarcator() 
    {
        delete tipConector;
        numarIncarcatoare--;
    }

    void afisare()
    {
        cout << "Incarcator #" << idIncarcator
            << " - conector " << *tipConector
            << ", " << voltaj << "V, "
            << (incarcareRapida ? "cu " : "fara ")
            << "incarcare rapida. Total incarcatoare: "
            << numarIncarcatoare << endl;
    }
    static int getNumarIncarcatoare() {
        return numarIncarcatoare;
    }
};

int Incarcator::numarIncarcatoare = 0;

int main() {
    Camera camera1(1, "Canon", 24, 2500.5, true);
    Camera camera2(2, "Nikon");
    Camera camera3;

    Card card1(1, "SDXC", 128, 90);
    Card card2(2, "MicroSD");
    Card card3;

    Incarcator inc1(1, "USB-C", 5.0, true);
    Incarcator inc2(2, "Lightning");
    Incarcator inc3;

    camera1.afisare();
    camera2.afisare();
    camera3.afisare();

    card1.afisare();
    card2.afisare();
    card3.afisare();

    inc1.afisare();
    inc2.afisare();
    inc3.afisare();

    cout << "Total iteme: " << Camera::getNumarCamere()+Card::getNumarCarduri()+Incarcator::getNumarIncarcatoare() << endl;

    return 0;
}
