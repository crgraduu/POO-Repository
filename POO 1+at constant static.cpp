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
        numarCamere++;


    void afisare() {
        cout << "Camera #" << idCamera << " - " << marca << " cu " << megapixeli
            << "MP, pret: " << pret << " lei, "
            << (areStabilizare ? "cu" : "fara") << " stabilizare." << numarCamere << endl;
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
        numarCarduri++;
    

    void afisare() {
        cout << "Card #" << idCard << " - " << tip << " de " << capacitateGB << "GB, "
            << "viteza scriere: " << vitezaScriereMB << " MB/s." << numarCarduri <<endl;
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
        numarIncarcatoare++;
    

    void afisare() {
        cout << "Incarcator #" << idIncarcator << " - conector " << tipConector
            << ", " << voltaj << "V, "
            << (incarcareRapida ? "cu incarcare rapida." : "fara incarcare rapida.") << numarIncarcatoare << endl;
    }
};

int main() {
    Camera c1(1, "Canon", 24, 2500.5f, true);
    Card card1(2, "SDXC", 128, 90);
    Incarcator inc1(3, "USB-C", 5.0f, true);

    c1.afisare();
    card1.afisare();
    inc1.afisare();

    return 0;
}
