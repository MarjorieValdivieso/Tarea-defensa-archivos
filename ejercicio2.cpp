#include <iostream>
#include <fstream>
using namespace std;

int main() {
    string materia;
    char opcion;

    ofstream archivo("materias.txt", ios::app); 

    if (!archivo) {
        cout << "Error al abrir el archivo." << endl;
        return 1;
    }

    do {
        cout << "Ingrese el nombre de la materia: ";
        cin >> materia;

        archivo << materia << endl;

        cout << "¿Desea agregar otra materia? (s/n): ";
        cin >> opcion;

    } while (opcion == 's' || opcion == 'S');

    archivo.close();

    cout << "Materias guardadas correctamente." << endl;
    return 0;
}
