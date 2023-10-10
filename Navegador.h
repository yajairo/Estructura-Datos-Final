#include <iostream>
#include <string>
#include <vector>
#include "Software.h"

using namespace std;

class Navegador : public Software {
private:
    vector<string> paginasVisitadas;  // Vector para almacenar las páginas visitadas

public:
    Navegador(string _nombre, string _developer, int _clas, int _precio, string _tipo) :
        Software(_nombre, _developer, _clas, _precio) {}

    void agregarPaginaVisitada(string pagina) {
        // Agregar la página al historial de navegación
        paginasVisitadas.push_back(pagina);
    }
       void verPaginasVisitadas() {
        cout << "Páginas visitadas en Navegador:" << endl;
        for (const string& pagina : paginasVisitadas) {
            cout << "- " << pagina << endl;
        }
    }

    void borrarHistorialNavegacion() {
        // Borrar todo el historial de navegación
        paginasVisitadas.clear();
        cout << "Historial de navegación borrado." << endl;
    }

    void imprimirPaginasVisitadas() {
        cout << "Páginas visitadas en el Navegador:" << endl;
        for (const string& pagina : paginasVisitadas) {
            cout << "- " << pagina << endl;
        }
    }
};
