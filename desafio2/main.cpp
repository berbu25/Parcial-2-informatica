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
        // Verificar si la línea ya existe
        for (int i = 0; i < numLineas; ++i) {
            if (lineas[i]->getNombre() == linea->getNombre()) {
                cout << "Error: La línea '" << linea->getNombre() << "' ya existe en la red." << endl;
                delete linea; // Liberar la memoria de la línea que no se va a agregar
                return;
            }
        }

        // Si no existe, agregar la línea
        if (numLineas < capacidad) {
            lineas[numLineas++] = linea;
        } else {
            cout << "Error: No se pueden agregar más líneas a la red." << endl;
            delete linea; // Liberar la memoria de la línea que no se va a agregar
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

    Red metro;
    int opcion;

    cout << "RED DE METRO" << endl;
    while (true) {
        cout << endl << "Seleccione una opcion:" << endl;
        cout << "1. Agregar Linea" << endl;
        cout << "2. Agregar Estacion" << endl;
        cout << "3. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        if (opcion == 1) {
            string nombre, tipoTransporte;
            cout << "Ingrese el nombre de la linea: ";
            cin >> nombre;
            cout << "Ingrese el tipo de transporte (tren/tranvia): ";
            cin >> tipoTransporte;

            Linea* nuevaLinea = new Linea(nombre, tipoTransporte);
            metro.agregarLinea(nuevaLinea);
        } else if (opcion == 2) {
            string nombreLinea, nombreEstacion;
            cout << "Ingrese el nombre de la linea: ";
            cin >> nombreLinea;
            Linea* linea = metro.obtenerLineaPorNombre(nombreLinea);
            if (linea == nullptr) {
                cout << "La linea especificada no existe." << endl;
                continue; // Volver al inicio del bucle
            }
            cout << "Ingrese el nombre de la estacion: ";
            cin >> nombreEstacion;

            Estacion* nuevaEstacion = new Estacion(nombreEstacion, false); // Por defecto no es de transferencia
            linea->agregarEstacion(nuevaEstacion);
        } else if (opcion == 3) {
            break;
        } else {
            cout << "Opcion invalida. Por favor ingrese 1, 2 o 3." << endl;
        }
    }

    // Imprimir las líneas en la red y las estaciones en cada línea
    cout << endl << "Lineas en la red:" << endl;
    for (int i = 0; i < metro.numeroLineas(); ++i) {
        Linea* linea = metro[i];
        cout << "Nombre: " << linea->getNombre() << ", Tipo: " << linea->getTransporte() << endl;
        cout << "Estaciones:" << endl;
        for (int j = 0; j < linea->cantidadEstaciones(); ++j) {
            Estacion* estacion = linea->obtenerEstacion(j);
            cout << " - " << estacion->getNombre() << endl;
        }
        cout << endl;
    }

    cout << "Numero de lineas en la red: " << metro.numeroLineas() << endl;
    cout << "Numero de estaciones en la red: " << metro.cantidadEstaciones() << endl;

    return 0;
}
