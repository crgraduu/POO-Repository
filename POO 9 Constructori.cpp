#include <iostream>
#include <string>
using namespace std;

// Clasa 1: Camera
class Camera {
private:
    const int idCamera;       //  atribut constant
    string marca;
    int megapixeli;
    float pret;
    bool areStabilizare;
    static int numarCamere;   // atribut static

public:
    Camera(int id, string m, int mp, float p, bool stab)
        : idCamera(id), marca(m), megapixeli(mp), pret(p), areStabilizare(stab)
    {
        numarCamere++;
    }

    Camera(int id, const string& m)
        : idCamera(id), megapixeli(0), pret(0), areStabilizare(false)
    {
        marca = new string(m);
        numarCamere++;
    }

    Camera()
        : idCamera(0), megapixeli(0), pret(0), areStabilizare(false)
    {
        marca = new string("Necunoscut");
        numarCamere++;
    }

    void afisare() 
    {
        cout << "Camera #" << idCamera << " - " << marca << " cu " << megapixeli
            << "MP, pret: " << pret << " lei, "
            << (areStabilizare ? "cu " : "fara ")
            << "stabilizare. Total camere: " << numarCamere << endl;
    }
};

// Clasa 2: Card
class Card {
private:
    const int idCard;         //  atribut constant
    string tip;
    int capacitateGB;
    int vitezaScriereMB;
    static int numarCarduri;  // atribut static

public:
    Card(int id, string t, int cap, int viteza)
        : idCard(id), tip(t), capacitateGB(cap), vitezaScriereMB(viteza)
    {
        numarCarduri++;
    }

    Card(int id, const string& t)
        : idCard(id), capacitateGB(0), vitezaScriereMB(0)
    {
        tip = new string(t);
        numarCarduri++;
    }

    Card()
        : idCard(0), capacitateGB(0), vitezaScriereMB(0)
    {
        tip = new string("Necunoscut");
        numarCarduri++;
    }

    void afisare() 
    {
        cout << "Card #" << idCard << " - " << tip << " de " << capacitateGB
            << "GB, viteza scriere: " << vitezaScriereMB
            << " MB/s. Total carduri: " << numarCarduri << endl;
    }
};

// Clasa 3: Incarcator
class Incarcator {
private:
    const int idIncarcator;   //  atribut constant
    string tipConector;
    float voltaj;
    bool incarcareRapida;
    static int numarIncarcatoare;  // atribut static

public:
    Incarcator(int id, string tip, float v, bool fast)
        : idIncarcator(id), tipConector(tip), voltaj(v), incarcareRapida(fast)
    {
        numarIncarcatoare++;
    }

    Incarcator(int id, const string& tip)
        : idIncarcator(id), voltaj(0), incarcareRapida(false)
    {
        tipConector = new string(tip);
        numarIncarcatoare++;
    }

    Incarcator()
        : idIncarcator(0), voltaj(0), incarcareRapida(false)
    {
        tipConector = new string("Necunoscut");
        numarIncarcatoare++;
    }

    void afisare() 
    {
        cout << "Incarcator #" << idIncarcator << " - conector " << tipConector
            << ", " << voltaj << "V, "
            << (incarcareRapida ? "cu " : "fara ")
            << "incarcare rapida. Total incarcatoare: " << numarIncarcatoare << endl;
    }
};
int Camera::numarCamere = 0;
int Card::numarCarduri = 0;
int Incarcator::numarIncarcatoare = 0;

int main() {
    Camera c1(1, "Canon", 24, 2500.5, true);
    Card card1(2, "SDXC", 128, 90);
    Incarcator inc1(3, "USB-C", 5.0, true);
    cout << "???";
    c1.afisare();
    card1.afisare();
    inc1.afisare();
    return 0;
}
