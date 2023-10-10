#include <iostream>
#include <string>
#include <vector>
#include "Software.h"

using namespace std;

class Ofimatica : public Software {
private:
    vector<string> archivos;  // Vector para almacenar nombres de archivos

public:
    Ofimatica(string _nombre, string _developer, int _clas, int _precio, string _tipo) :
        Software(_nombre, _developer, _clas, _precio) {}

    void agregarArchivo(string nombreArchivo) {
        // Agregar el nombre del archivo al vector
        archivos.push_back(nombreArchivo);
    }

    void borrarUltimoArchivo() {
        // Borrar el último archivo si hay al menos uno
        if (!archivos.empty()) {
            archivos.pop_back();
        }
    }

    void imprimirArchivos() {
        cout << "Archivos en Ofimatica:" << endl;
        for (const string& archivo : archivos) {
            cout << "- " << archivo << endl;
        }
    }
    
};








    