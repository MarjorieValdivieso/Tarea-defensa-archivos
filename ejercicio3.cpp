#include <iostream>
#include <fstream>
using namespace std;

int main() {
    int k = 5;
    int arreglo[5] = {10, 20, 30, 40, 50};
    int resultado[5];

    ofstream archivo("producto_escalar.txt");

    for (int i = 0; i < 5; i++) {
        resultado[i] = k * arreglo[i];
        archivo << resultado[i] << " ";
    }

    archivo.close();

    cout << "Producto escalar guardado en el archivo." << endl;
    return 0;
}
