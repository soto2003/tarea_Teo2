
#include <iostream>
#include <string>
using namespace std;

// Tablero de ajedrez con herencia
class Pieza {
private:
    short fila;
    short columna;
public:
    Pieza() {
        fila = 1;
        columna = 1;
    }

    Pieza(short fi, short co) {
        if (validarPosicion(fi, co)) {
            fila = fi;
            columna = co;
        }
        else {
            fila = 1;
            columna = 1;
        }
    }

    // Getters y setters
    short getFila() {
        return fila;
    }

    short getColumna() {
        return columna;
    }

    void setFila(short f) {
        fila = f;
    }

    void setColumna(short c) {
        columna = c;
    }

    void verInfo() {
        cout << "Fila -> " << fila << " Columna -> " << columna << endl;
    }

    // Método que valida la posición de la pieza
    bool validarPosicion(short f, short c) {
		if (f >= 1 && f <= 8 && c >= 1 && c <= 8) {
			return true;
		}
		else {
			return false;
		}
        
    }
};

class Peon : public Pieza {
public:
    short direccion; 
    Peon() {
		direccion = 1;
	}

    void Avanzar() {

        // Avanzar una casilla
        if (direccion == 1) {
			setFila(getFila() + 1);
		}
		else {
			setFila(getFila() - 1);
		}
    }

    bool puedoIrA(short f, short c) {
        // Implementar lógica para verificar si el peón puede ir a la posición (f, c)
        // Validar 
        return validarPosicion(f, c);

    }
};
class Torre : public Pieza {

    public:
	short nroCuadrados;
	short direccion;
    Torre() {
		nroCuadrados = 1;
		direccion = 1;
	}

	void Avanzar() {
		// Avanzar una casilla
        if (direccion == 1) {
			setFila(getFila() + nroCuadrados);
		}
		else {
			setFila(getFila() - nroCuadrados);
		}
	}

	bool puedoIrA(short f, short c) {
		// Implementar lógica para verificar si el peón puede ir a la posición (f, c)
        return validarPosicion(f, c);
	}

};
int main() {
    Pieza p1;
    Peon peon;
    Torre torre;
    short f, c;
    //Ingrese datos de Peon
    cout << "Ingrese la fila del peon "<<endl;
    cin >> f;
    cout << "Ingrese la columna del peon "<<endl;
    cin >> c;
    peon.setFila(f);
    peon.setColumna(c);
    peon.Avanzar();
    //Ingrese datos de Torre
    cout << "Ingrese la fila de la torre "<<endl;
    cin >> f;
    cout << "Ingrese la columna de la torre "<<endl;
    cin >> c;
    torre.setFila(f);
    torre.setColumna(c);
    torre.Avanzar();


    

  
    return 0;
}


