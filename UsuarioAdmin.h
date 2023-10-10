#include<iostream>
using namespace std;

#include "Usuario.h"
#include "Software.h"

class UsuarioAdmin : public Usuario {
private:
    string correo;

public:
    UsuarioAdmin(string _usuario, string _contrasena, int _edad, string _correo)
        : Usuario(_usuario, _contrasena, _edad), correo(_correo) {
        accederLog = true;
    }

    string getCorreo() override {
        return correo;
    }

    string obtenerTipo() override {
        return "UsuarioAdmin";
    }

    
};