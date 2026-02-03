#include <iostream>
#include <fstream>
using namespace std;


class Publicacion {
protected:
    int codigo;
    string titulo;
    int anio;
    bool prestado;

public:
    Publicacion(int c, string t, int a) {
        codigo = c;
        titulo = t;
        anio = a;
        prestado = false; 
    }

    void prestar() {
        prestado = true;
    }

    void devolver() {
        prestado = false;
    }

    bool estaPrestado() {
        return prestado;
    }

    string obtenerInformacion() {
        string estado = prestado ? "Prestado" : "No Prestado";
        return "Codigo: " + to_string(codigo) +
               " | Titulo: " + titulo +
               " | Año: " + to_string(anio) +
               " | Estado: " + estado;
    }
};

class Libro : public Publicacion {
public:
    Libro(int c, string t, int a) : Publicacion(c, t, a) {}
};


class Revista : public Publicacion {
public:
    Revista(int c, string t, int a) : Publicacion(c, t, a) {}
};

int main() {
    Libro l1(101, "EL principito", 2020);
    Libro l2(102, "Orgullo y Perjuicio", 2022);
    Revista r1(201, "Metamorfosis", 2023);


    l1.prestar();
    r1.prestar();

    ofstream prestados("LibrosPrestados.txt");
    ofstream stock("LibrosEnStock.txt");

    if (l1.estaPrestado())
        prestados << l1.obtenerInformacion() << endl;
    else
        stock << l1.obtenerInformacion() << endl;

    if (l2.estaPrestado())
        prestados << l2.obtenerInformacion() << endl;
    else
        stock << l2.obtenerInformacion() << endl;

    if (r1.estaPrestado())
        prestados << r1.obtenerInformacion() << endl;
    else
        stock << r1.obtenerInformacion() << endl;

    prestados.close();
    stock.close();

    cout << "Archivos generados correctamente." << endl;

    return 0;
}
