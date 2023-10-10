#ifndef USUARIONINO_H
#define USUARIONINO_H
#include<iostream>
using namespace std;

#include "Usuario.h"
#include "Software.h"

class UsuarioNino : public Usuario {
public:
    UsuarioNino(string _usuario, string _contrasena, int _edad)
        : Usuario(_usuario, _contrasena, _edad) {
        if (_edad < 18) {
            accederLog = false;
        } else {
            cerr << "Error: UsuarioNino debe tener menos de 18 años." << endl;
        }
    }

    string obtenerTipo() override {
        return "UsuarioNino";
    }
    void agregarSoftwareABiblioteca(Software* software) override {
        if (software->getClasificacion() >= 18) {
            cout << "No puede agregar software con clasificación mayor o igual a 18." << endl;
            return;
        }

        if (dynamic_cast<Seguridad*>(software) != nullptr) {
            cout << "No puede agregar software de tipo Seguridad." << endl;
            return;
        }

        // Lógica común para agregar software a la biblioteca
        Usuario::agregarSoftwareABiblioteca(software);
    }
};
#endif