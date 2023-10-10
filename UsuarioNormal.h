#include<iostream>
using namespace std;

#include "Usuario.h"
#include "Software.h"

class UsuarioNormal : public Usuario {
private:
    string correo;

public:
    UsuarioNormal(string _usuario, string _contrasena, int _edad, string _correo)
        : Usuario(_usuario, _contrasena, _edad), correo(_correo) {
        while (true) {
            if (_edad >= 18) {
                edad = _edad;
                break;
            } else {
                cout << "Edad no válida. La edad debe ser mayor o igual a 18. Ingrese de nuevo: ";
                cin >> _edad;
            }
        }
    }
 
    string getCorreo() override {
        return correo;
    }

    string obtenerTipo() override {
        return "UsuarioNormal";
    }
    void agregarSoftwareABiblioteca(Software* software) override {
        if (dynamic_cast<Seguridad*>(software) != nullptr) {
            cout << "No puede agregar software de tipo Seguridad." << endl;
            return;
        }

        // Lógica común para agregar software a la biblioteca
        Usuario::agregarSoftwareABiblioteca(software);
    }   
};
