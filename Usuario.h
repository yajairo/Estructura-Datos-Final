#ifndef USUARIO_H
#define USUARIO_H

#include <iostream>
#include <vector>
#include "Software.h"

using namespace std;

class Usuario {
protected:
    string usuario;
    string contrasena; // Agregado: Contraseña del usuario
    int edad;
    bool accederLog;
    vector<Software*> listaSoftware;  // Lista de software del usuario

public:
    Usuario(string _usuario, string _contrasena, int _edad)
        : usuario(_usuario), contrasena(_contrasena), edad(_edad), accederLog(false) {}

    virtual string obtenerTipo() {
        return "Usuario";
    }

    virtual string getCorreo() {
        return ""; // Implementación predeterminada para Usuario
    }

    string getUsuario() {
        return usuario;
    }

    void setUsuario(string _usuario) {
        usuario = _usuario;
    }

    string getContrasena() { // Getter para la contraseña
        return contrasena;
    }

    void setContrasena(string _contrasena) { // Setter para la contraseña
        contrasena = _contrasena;
    }

    int getEdad() {
        return edad;
    }

    void setEdad(int _edad) {
        edad = _edad;
    }

    // Método para imprimir la lista de software del usuario
    void imprimirListaSoftware() {
        cout << "Software del usuario " << usuario << ":" << endl;
        for (const auto& software : listaSoftware) {
            cout << "- " << software->getNombre() << endl;
        }
    }

    // Agrega un Software* a la biblioteca del usuario
    virtual void agregarSoftwareABiblioteca(Software* software) {
        // Verifica si el software ya existe en la biblioteca del usuario
        for (const auto& softwareEnBiblioteca : listaSoftware) {
            if (softwareEnBiblioteca->getNombre() == software->getNombre()) {
                cout << "El software ya está en su biblioteca." << endl;
                return; // Sal del método si el software ya está en la biblioteca
            }
        }

        // Agrega el software a la biblioteca del usuario
        listaSoftware.push_back(software);
        cout << "Software agregado a su biblioteca." << endl;

        software->agregarUsuario(usuario);
    }

    void eliminarSoftware(const std::string& nombreSoftware) {
        for (size_t i = 0; i < listaSoftware.size(); ++i) {
            if (listaSoftware[i]->getNombre() == nombreSoftware) {
                listaSoftware[i]->eliminarUsuario(usuario);

                listaSoftware.erase(listaSoftware.begin() + i);
                cout << "Se ha eliminado el software: " << nombreSoftware << endl;
                return;  // Salir del bucle después de eliminar el software
            }
        }
        cout << "No se encontró el software: " << nombreSoftware << endl;
    }

    bool softwareEnBiblioteca(Software* software) {
        // Verifica si el software ya existe en la biblioteca del usuario
        for (const auto& softwareEnBiblioteca : listaSoftware) {
            if (softwareEnBiblioteca == software) {
                return true;
            }
        }
        return false;
    }

    bool tieneSoftware(const string& nombreSoftware) {
        for (const auto& software : listaSoftware) {
            if (software->getNombre() == nombreSoftware) {
                return true;
            }
        }
        return false;
    }
    vector<Software*> getListaSoftware(){
        return listaSoftware;
    }
    Software* buscarSoftwareEnBiblioteca(const string& nombreSoftware) {
    for (Software* software : listaSoftware) {
        if (software->getNombre() == nombreSoftware) {
            return software;
        }
    }
    return nullptr; // El software no se encontró en la biblioteca del usuario
}

};

#endif
