#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream archivo("factura.txt");
    int cantidad;
    string detalle;
    float valorUnitario, total, totalFactura = 0;
    char opcion;
    const float IVA = 0.12; 

    if (!archivo) {
        cout << "Error al abrir el archivo." << endl;
        return 1;
    }

    do {
        cout << "Ingrese detalle del producto: ";
        cin >> detalle;
        cout << "Ingrese cantidad: ";
        cin >> cantidad;
        cout << "Ingrese valor unitario: ";
        cin >> valorUnitario;

        total = cantidad * valorUnitario * (1 + IVA);
        totalFactura += total;

        archivo << detalle << " " << cantidad << " "
                << valorUnitario << " " << total << endl;

        cout << "¿Desea agregar otro producto? (s/n): ";
        cin >> opcion;

    } while (opcion == 's' || opcion == 'S');

    archivo << "TOTAL A PAGAR: " << totalFactura << endl;
    archivo.close();

    cout << "Factura guardada correctamente en factura.txt" << endl;
    return 0;
}
