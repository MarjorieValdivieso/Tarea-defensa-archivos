#include <iostream>
#include <fstream>
using namespace std;

struct Helado {
    int codigo;
    string sabor;
    float precio;
};

int main() {
    Helado h, menor;
    ofstream archivo("helados.txt");

    for (int i = 0; i < 10; i++) {
        cout << "Codigo: ";
        cin >> h.codigo;
        cout << "Sabor: ";
        cin >> h.sabor;
        cout << "Precio: ";
        cin >> h.precio;

        archivo << h.codigo << " " << h.sabor << " " << h.precio << endl;
    }
    archivo.close();

    ifstream leer("helados.txt");
    float suma = 0;
    int primero = 1;

    for (int i = 0; i < 10; i++) {
        leer >> h.codigo >> h.sabor >> h.precio;

        suma += h.precio;

        if (primero || h.precio < menor.precio) {
            menor = h;
            primero = 0;
        }

        if (h.sabor == "mora") {
            cout << "Helado de mora: "
                 << h.codigo << " "
                 << h.sabor << " "
                 << h.precio << endl;
        }
    }
    leer.close();

    cout << "Helado con menor precio: "
         << menor.codigo << " "
         << menor.sabor << " "
         << menor.precio << endl;

    cout << "Suma total: " << suma << endl;

    return 0;
}
