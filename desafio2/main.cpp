#include <iostream>
#include <string>

using namespace std;

class Linea; // Declaración adelantada de la clase Linea

class Estacion {
private:
    string nombre;
    Linea** lineas; // Arreglo de punteros a Linea
    int capacidadLineas; // Capacidad del arreglo
    int numLineas; // Número actual de líneas

    // Métodos privados para el manejo de memoria
    void expandirCapacidad() {
        int nuevaCapacidad = capacidadLineas * 2; // Duplicar la capacidad
        Linea** temp = new Linea*[nuevaCapacidad]; // Crear un nuevo arreglo con la nueva capacidad
        for (int i = 0; i < numLineas; ++i) {
            temp[i] = lineas[i]; // Copiar los punteros de las líneas al nuevo arreglo
        }
        delete[] lineas; // Liberar la memoria del arreglo anterior
        lineas = temp; // Actualizar el puntero al nuevo arreglo
        capacidadLineas = nuevaCapacidad; // Actualizar la capacidad del arreglo
    }

public:
    Estacion(string _nombre) : nombre(_nombre), lineas(nullptr), capacidadLineas(5), numLineas(0) {
        lineas = new Linea*[capacidadLineas]; // Inicializar el arreglo de punteros a Linea con una capacidad inicial
    }

    ~Estacion() {
        delete[] lineas; // Liberar la memoria del arreglo de punteros
    }

    string getNombre() const {
        return nombre;
    }

    void setAnterior(Estacion* estacion) {
        // Implementar
    }

    Estacion* getAnterior() const {
        // Implementar
        return nullptr;
    }

    void setSiguiente(Estacion* estacion) {
        // Implementar
    }

    Estacion* getSiguiente() const {
        // Implementar
        return nullptr;
    }

    void agregarLinea(Linea* linea) {
        if (numLineas == capacidadLineas) {
            expandirCapacidad(); // Expandir el arreglo si se alcanza la capacidad máxima
        }
        lineas[numLineas++] = linea; // Agregar el puntero a la línea al arreglo
    }

    bool tieneLinea(Linea* linea) const {
        for (int i = 0; i < numLineas; ++i) {
            if (lineas[i] == linea) {
                return true;
            }
        }
        return false;
    }
};

class Linea {
private:
    string nombre;
    string transporte;
    Estacion* primeraEstacion;
    Estacion* ultimaEstacion;
    Linea* siguiente;
    int capacidad;
    int numEstaciones;

public:
    Linea(string _nombre, string _transporte, int _capacidad = 10) : nombre(_nombre), transporte(_transporte), capacidad(_capacidad), numEstaciones(0), primeraEstacion(nullptr), ultimaEstacion(nullptr), siguiente(nullptr) {}

    ~Linea() {}

    string getNombre() const {
        return nombre;
    }

    int numeroEstaciones() const {
        return numEstaciones;
    }

    void agregarEstacion(Estacion* estacion) {
        if (!primeraEstacion) {
            primeraEstacion = estacion;
            ultimaEstacion = estacion;
        } else {
            ultimaEstacion->setSiguiente(estacion);
            estacion->setAnterior(ultimaEstacion);
            ultimaEstacion = estacion;
        }
        numEstaciones++;
    }

    bool eliminarEstacion(Estacion* estacion) {
        // Implementar la lógica para eliminar una estación de la línea
    }

    int tiempoDeViaje(Estacion* origen, Estacion* destino) const {
        // Implementar la lógica para calcular el tiempo de viaje entre dos estaciones
    }

    Linea* getSiguiente() const {
        return siguiente;
    }

    void setSiguiente(Linea* _siguiente) {
        siguiente = _siguiente;
    }
};

class Red {
private:
    Linea* primeraLinea;
    Linea* ultimaLinea;

public:
    Red() : primeraLinea(nullptr), ultimaLinea(nullptr) {}

    ~Red() {}

    void agregarLinea(Linea* linea) {
        if (!primeraLinea) {
            primeraLinea = linea;
            ultimaLinea = linea;
        } else {
            ultimaLinea->setSiguiente(linea);
            ultimaLinea = linea;
        }
    }

    bool eliminarLinea(Linea* linea) {
        // Implementar la lógica para eliminar una línea de la red
    }

    // Método para encontrar la ruta más corta entre dos estaciones en toda la red
    //vector<Estacion*> encontrarRutaCorta(Estacion* origen, Estacion* destino) const {
    // Implementar la lógica para encontrar la ruta más corta
    //}
};

int main()
    return 0;
}
