#include <iostream>
#include <string>

using namespace std;

class Estacion {
private:
    string nombre;
    bool transferencia;

public:
    Estacion(string _nombre, bool _transferencia) : nombre(_nombre), transferencia(_transferencia) {}

    string getNombre() const {
        return nombre;
    }

    bool esTransferencia() const {
        return transferencia;
    }
};

// Función para agregar un dato al final de un arreglo
Estacion** agregarEstacion(Estacion* estacion, Estacion** arreglo, int longitud) {
    Estacion** nuevoArreglo = new Estacion*[longitud + 1];
    for (int i = 0; i < longitud; i++) {
        nuevoArreglo[i] = arreglo[i];
    }
    nuevoArreglo[longitud] = estacion;
    delete[] arreglo;
    return nuevoArreglo;
}

class Linea {
private:
    string nombre;
    string transporte;
    Estacion** estaciones;
    int capacidad;
    int numEstaciones;

public:
    Linea(string _nombre, string _transporte) : nombre(_nombre), transporte(_transporte), capacidad(10), numEstaciones(0) {
        estaciones = new Estacion*[capacidad];
    }

    ~Linea() {
        for (int i = 0; i < numEstaciones; ++i) {
            delete estaciones[i];
        }
        delete[] estaciones;
    }

    string getNombre() const {
        return nombre;
    }

    string getTransporte() const {
        return transporte;
    }

    int cantidadEstaciones() const {
        return numEstaciones;
    }

    void agregarEstacion(Estacion* estacion) {
        if (numEstaciones >= capacidad) {
            // Si se alcanza la capacidad actual, duplicar la capacidad
            capacidad *= 2;
            Estacion** nuevoArreglo = new Estacion*[capacidad];
            for (int i = 0; i < numEstaciones; ++i) {
                nuevoArreglo[i] = estaciones[i];
            }
            nuevoArreglo[numEstaciones] = estacion;
            delete[] estaciones;
            estaciones = nuevoArreglo;
        } else {
            estaciones[numEstaciones] = estacion;
        }
        numEstaciones++;
    }

    bool eliminarEstacion(Estacion* estacion) {
        for (int i = 0; i < numEstaciones; ++i) {
            if (estaciones[i] == estacion) {
                // Liberar memoria de la estación antes de eliminarla
                delete estaciones[i];
                // Eliminar estacion moviendo las siguientes una posición atrás
                for (int j = i; j < numEstaciones - 1; ++j) {
                    estaciones[j] = estaciones[j + 1];
                }
                numEstaciones--;
                return true;
            }
        }
        return false;
    }

    bool tieneEstacion(Estacion* estacion) const {
        for (int i = 0; i < numEstaciones; ++i) {
            if (estaciones[i] == estacion) {
                return true;
            }
        }
        return false;
    }

    Estacion* obtenerEstacion(int indice) const {
        if (indice >= 0 && indice < numEstaciones) {
            return estaciones[indice];
        }
        return nullptr;
    }
};

class Red {
private:
    Linea** lineas;
    int capacidad;
    int numLineas;

public:
    Red(int _capacidad = 5) : capacidad(_capacidad), numLineas(0) {
        lineas = new Linea*[capacidad];
    }

    ~Red() {
        for (int i = 0; i < numLineas; ++i) {
            delete lineas[i];
        }
        delete[] lineas;
    }

    int numeroLineas() const {
        return numLineas;
    }

    void agregarLinea(Linea* linea) {
        if (numLineas < capacidad) {
            lineas[numLineas++] = linea;
        } else {
            cout << "Error: No se pueden agregar más líneas a la red." << endl;
        }
    }

    Linea* obtenerLineaPorNombre(const string& nombre) const {
        for (int i = 0; i < numLineas; ++i) {
            if (lineas[i]->getNombre() == nombre) {
                return lineas[i];
            }
        }
        return nullptr;
    }

    int cantidadEstaciones() const {
        int count = 0;
        for (int i = 0; i < numLineas; ++i) {
            count += lineas[i]->cantidadEstaciones();
        }
        return count;
    }

    Linea* operator[](int indice) const {
        if (indice >= 0 && indice < numLineas) {
            return lineas[indice];
        }
        return nullptr;
    }
};


int main() {


    return 0;
}
