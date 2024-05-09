#include <iostream>
#include <string>

using namespace std;

// Definición adelantada de la clase Estacion
class Estacion;

// Definición completa de la clase Linea
class Linea {
private:
    string nombre;
    string transporte;
    Estacion* primeraEstacion;
    Estacion* ultimaEstacion;
    Linea* siguiente;
    int numEstaciones;

public:
    Linea(string _nombre) : nombre(_nombre), primeraEstacion(nullptr), ultimaEstacion(nullptr), siguiente(nullptr), numEstaciones(0) {}

    string getNombre() const {
        return nombre;
    }

    int numeroEstaciones() const {
        return numEstaciones;
    }

    void agregarEstacion(Estacion* estacion);

    bool eliminarEstacion(Estacion* estacion) {
        // Implementa la lógica para eliminar una estación de la línea
        return false;
    }

    int tiempoDeViaje(Estacion* origen, Estacion* destino) const {
        // Implementa la lógica para calcular el tiempo de viaje entre dos estaciones en la línea
        return 0;
    }

    Linea* getSiguiente() const {
        return siguiente;
    }

    void setSiguiente(Linea* _siguiente) {
        siguiente = _siguiente;
    }

    Estacion* obtenerPrimeraEstacion() const {
        return primeraEstacion;
    }
};

// Definición completa de la clase Estacion
class Estacion {
private:
    string nombre;
    Linea** lineas;
    int capacidadLineas;
    int numLineas;
    Estacion* anterior;
    Estacion* siguiente;

    // Métodos privados para el manejo de memoria
    void expandirCapacidad() {
        int nuevaCapacidad = capacidadLineas * 2;
        Linea** temp = new Linea*[nuevaCapacidad];
        for (int i = 0; i < numLineas; ++i) {
            temp[i] = lineas[i];
        }
        delete[] lineas;
        lineas = temp;
        capacidadLineas = nuevaCapacidad;
    }

public:
    Estacion(string _nombre) : nombre(_nombre), lineas(nullptr), capacidadLineas(5), numLineas(0), anterior(nullptr), siguiente(nullptr) {
        lineas = new Linea*[capacidadLineas];
    }

    ~Estacion() {
        delete[] lineas;
    }

    string getNombre() const {
        return nombre;
    }

    void setAnterior(Estacion* estacion) {
        anterior = estacion;
    }

    Estacion* getAnterior() const {
        return anterior;
    }

    void setSiguiente(Estacion* estacion) {
        siguiente = estacion;
    }

    Estacion* getSiguiente() const {
        return siguiente;
    }

    void agregarLinea(Linea* linea) {
        if (numLineas == capacidadLineas) {
            expandirCapacidad();
        }
        lineas[numLineas++] = linea;
    }

    bool tieneLinea(Linea* linea) const {
        for (int i = 0; i < numLineas; ++i) {
            if (lineas[i] == linea) {
                return true;
            }
        }
        return false;
    }

    bool eliminarEstacion(Estacion* estacion) {
        // Implementa la lógica para eliminar una estación
        return false;
    }

    int tiempoDeViaje(Estacion* origen, Estacion* destino) const {
        // Implementa la lógica para calcular el tiempo de viaje entre dos estaciones
        return 0;
    }
};

// Definición del método agregarEstacion de la clase Linea
void Linea::agregarEstacion(Estacion* estacion) {
    if (!primeraEstacion) {
        primeraEstacion = estacion;
        ultimaEstacion = estacion;
    } else {
        ultimaEstacion->setSiguiente(estacion);
        ultimaEstacion = estacion;
    }
    numEstaciones++;
}

class Red {
private:
    Linea* primeraLinea;
    Linea* ultimaLinea;
    int numLineas;

public:
    Red() : primeraLinea(nullptr), ultimaLinea(nullptr), numLineas(0) {}

    void agregarLinea(Linea* linea) {
        if (!primeraLinea) {
            primeraLinea = linea;
            ultimaLinea = linea;
        } else {
            ultimaLinea->setSiguiente(linea);
            ultimaLinea = linea;
        }
        numLineas++;
        mostrarEstructura();
    }

    void mostrarEstructura() const {
        Linea* tempLinea = primeraLinea;
        while (tempLinea) {
            cout << "Línea: " << tempLinea->getNombre() << endl;
            Estacion* tempEstacion = tempLinea->obtenerPrimeraEstacion(); // Usar el nuevo método
            while (tempEstacion) {
                cout << "- Estación: " << tempEstacion->getNombre() << endl;
                tempEstacion = tempEstacion->getSiguiente();
            }
            tempLinea = tempLinea->getSiguiente();
        }
    }

    void eliminarLinea(Linea* linea) {
        // Implementa la lógica para eliminar una línea de la red
    }

    int contarLineas() const {
        return numLineas;
    }

    void mostrarMenu() {
        cout << "Menú de opciones:" << endl;
        cout << "1. Crear estacion" << endl;
        cout << "2. Eliminar estacion" << endl;
        cout << "3. Crear linea" << endl;
        cout << "4. Eliminar linea" << endl;
        cout << "5. Calcular tiempo de desplazamiento entre estaciones" << endl;
        cout << "6. Salir" << endl;
        cout << "7. Mostrar lineas" << endl;
        cout << "Seleccione una opcion: ";
    }

    // Método para crear una línea en la red
    void crearLinea() {
        string nombreLinea;
        cout << "Ingrese el nombre de la linea: ";
        cin >> nombreLinea;

        Linea* nuevaLinea = new Linea(nombreLinea);
        agregarLinea(nuevaLinea);

        cout << "Linea creada exitosamente.\n" << endl;
    }
};

int calcularTiempoDeLlegada(Estacion* origen, Estacion* destino) {
    // Implementa la lógica para calcular el tiempo de llegada
    return 0;
}

int main() {
    Red red;
    int opcion;
    cout << "Bienvenido al sistema de gestion de la red de metro.\n" << endl;
    do {
        red.mostrarMenu();
        cin >> opcion;
        cout << endl;

        switch (opcion) {
        case 1:
            // Implementa la lógica para crear una estación
            break;
        case 2:
            // Implementa la lógica para eliminar una estación
            break;
        case 3:
            red.crearLinea(); // Crear línea en la red
            break;
        case 4:
            // Implementa la lógica para eliminar una línea
            break;
        case 5:
            // Implementa la lógica para calcular el tiempo de desplazamiento entre estaciones
            break;
        case 6:
            cout << "¡Hasta luego!" << endl;
            break;
        case 7:
            red.mostrarEstructura();
            cout << endl;
            break;
        default:
            cout << "Opcion no valida. Por favor, seleccione una opcion valida." << endl;
            break;
        }
    } while (opcion != 6);

    return 0;
}
