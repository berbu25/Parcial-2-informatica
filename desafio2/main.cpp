#include <iostream>
#include <string>

using namespace std;

// Declaración adelantada de la clase Estacion
class Estacion;

class Linea {
private:
    string nombre;
    string transporte;
    Estacion** estaciones;
    int capacidad;
    int numEstaciones;

public:
    Linea(string _nombre, string _transporte, int _capacidad = 10) : nombre(_nombre), transporte(_transporte), capacidad(_capacidad), numEstaciones(0) {}

    ~Linea() {}

    string getNombre() const {}

    int numeroEstaciones() const {}

    void agregarEstacion(Estacion* estacion) {}

    bool eliminarEstacion(Estacion* estacion) {}

    bool tieneEstacion(Estacion* estacion) const {}
};

// Declaración adelantada de la clase Linea
class Linea;

class Estacion {
private:
    string nombre;
    int tiempoAnterior;
    int tiempoSiguiente;
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

class Red {
private:
    Linea** lineas;
    int capacidad;
    int numLineas;

public:
    Red(int _capacidad = 5) : capacidad(_capacidad), numLineas(0) {}

    ~Red() {}

    int numeroLineas() const {}

    void agregarLinea(Linea* linea) {}

    bool eliminarLinea(Linea* linea) {}

    int numeroEstaciones() const {}
};

int main() {
    return 0;
}
