#include<iostream>
#include <vector>
using namespace std;

#include "NodoSoftware.h"
#include "Usuario.h"
#include "ListaUsuarios.h"

class Biblioteca {
private:
    NodoSoftware* inicio;

public:
    Biblioteca() : inicio(nullptr) {}

    void agregarSoftware(Software* nuevoSoftware) {
        NodoSoftware* nuevoNodo = new NodoSoftware(nuevoSoftware);
        nuevoNodo->setSiguiente(inicio);
        inicio = nuevoNodo;
    }

    void mostrarSoftware() {
        if (inicio == nullptr) {
            cout << "No hay softwares en la biblioteca" << endl;
        } else {
            NodoSoftware* temp = inicio;
            while (temp != nullptr) {
                cout << temp->getSoftware()->getNombre() << endl;
                temp = temp->getSiguiente();
            }
        }
    }

    Software* buscarSoftware(const string& nombreSoftware) {
        NodoSoftware* temp = inicio;

        while (temp != nullptr) {
            Software* softwareActual = temp->getSoftware();

            if (softwareActual->getNombre() == nombreSoftware) {
                return softwareActual;
            }

            temp = temp->getSiguiente();
        }

        // Si no se encuentra el software, devolver nullptr
        return nullptr;
    }
    void eliminarSoftware(const string& nombreSoftware) {
        NodoSoftware* anterior = nullptr;
        NodoSoftware* actual = inicio;

        while (actual != nullptr) {
            Software* softwareActual = actual->getSoftware();

            if (softwareActual->getNombre() == nombreSoftware) {
                if (anterior != nullptr) {
                    anterior->setSiguiente(actual->getSiguiente());
                } else {
                    inicio = actual->getSiguiente();
                }

                delete actual;
                cout << "Software eliminado de la biblioteca." << endl;
                return;
            }

            anterior = actual;
            actual = actual->getSiguiente();
        }

        cout << "No se encontró el software: " << nombreSoftware << endl;
    }

    // Método para eliminar software con confirmación de usuarios
    void eliminarSoftwareConConfirmacion(const string& nombreSoftware, ListaUsuarios listaUsuarios) {
    cout << "¿Está seguro de eliminar el software '" << nombreSoftware << "'? (Sí/No): ";
    string respuesta;
    cin >> respuesta;

    if (respuesta == "Sí" || respuesta == "Si" || respuesta == "sí" || respuesta == "si") {
        bool todosAceptan = true;

        NodoUsuario* temp = listaUsuarios.obtenerInicio();

        while (temp != nullptr) {
            Usuario* usuario = temp->getUsuario();

            cout << "¿" << usuario->getUsuario() << ", acepta eliminar el software? (Sí/No): ";
            cin >> respuesta;

            if (!(respuesta == "Sí" || respuesta == "Si" || respuesta == "sí" || respuesta == "si")) {
                todosAceptan = false;
                break;
            }

            temp = temp->getSiguiente();
        }

        if (todosAceptan) {
            // Eliminar software de la biblioteca y de los usuarios
            eliminarSoftware(nombreSoftware);

            NodoUsuario* tempUsuario = listaUsuarios.obtenerInicio();
            while (tempUsuario != nullptr) {
                Usuario* usuario = tempUsuario->getUsuario();
                if (usuario->tieneSoftware(nombreSoftware)) {
                    usuario->eliminarSoftware(nombreSoftware);
                }
                tempUsuario = tempUsuario->getSiguiente();
            }

            cout << "El software ha sido eliminado de la biblioteca y de todos los usuarios." << endl;
        } else {
            cout << "No se eliminó el software. Algunos usuarios no dieron permiso." << endl;
        }
    } else {
        cout << "No se eliminó el software. Confirmación cancelada." << endl;
    }
}
void verUsuariosDelSoftware(string nombreSoftware, ListaUsuarios listaUsuarios) {
    NodoSoftware* temp = inicio;
    bool encontrado = false;

    while (temp != nullptr) {
        Software* softwareActual = temp->getSoftware();

        if (softwareActual->getNombre() == nombreSoftware) {
            encontrado = true;
            break;
        }

        temp = temp->getSiguiente();
    }

    if (encontrado) {
        cout << "Usuarios que usan el software '" << nombreSoftware << "':" << endl;

        // Recorrer la lista de usuarios y verificar quiénes tienen el software
        NodoUsuario* nodoUsuario = listaUsuarios.obtenerInicio();

        while (nodoUsuario != nullptr) {
            Usuario* usuario = nodoUsuario->getUsuario();

            if (usuario->tieneSoftware(nombreSoftware)) {
                cout << "- " << usuario->getUsuario() << endl;
            }

            nodoUsuario = nodoUsuario->getSiguiente();
        }
    } else {
        cout << "No se encontró el software '" << nombreSoftware << "' en la biblioteca." << endl;
    }
}
};

