#ifndef LISTA_USUARIOS_H
#define LISTA_USUARIOS_H

#include<iostream>
using namespace std;
#include <cstdlib>  
#include <ctime>    
#include "Usuario.h"
#include "UsuarioNino.h"
#include "NodoUsuario.h"

class ListaUsuarios {
private:
    NodoUsuario* inicio;

public:
    ListaUsuarios() : inicio(nullptr) {}

    void agregarUsuario(Usuario* nuevoUsuario) {
        NodoUsuario* nuevoNodo = new NodoUsuario(nuevoUsuario);
        nuevoNodo->setSiguiente(inicio);
        inicio = nuevoNodo;
    }

    // Función para buscar un usuario por nombre de usuario y contraseña
    Usuario* buscarUsuario(string usuario, string contrasena) {
        NodoUsuario* temp = inicio;

        while (temp != nullptr) {
            Usuario* usuarioActual = temp->getUsuario();

            if (usuarioActual->getUsuario() == usuario && usuarioActual->getContrasena() == contrasena) {
                return usuarioActual;
            }

            temp = temp->getSiguiente();
        }

        // Si no se encuentra el usuario, devolver nullptr
        return nullptr;
    }

    void mostrarUsuarios() {
        NodoUsuario* temp = inicio;
        while (temp != nullptr) {
            cout << "Usuario: " << temp->getUsuario()->getUsuario();
            cout << ", Edad: " << temp->getUsuario()->getEdad();

            // Verificar si el usuario es un niño y evitar imprimir el correo si es el caso
            if (dynamic_cast<UsuarioNino*>(temp->getUsuario()) == nullptr) {
                cout << ", Correo: " << temp->getUsuario()->getCorreo();
            }

            cout << endl;
            temp = temp->getSiguiente();
        }
    }
    NodoUsuario* obtenerInicio() const {
    return inicio;
}
    Usuario* buscarUsuario(string nombreUsuario) {
        NodoUsuario* temp = inicio;

        while (temp != nullptr) {
            Usuario* usuarioActual = temp->getUsuario();

            if (usuarioActual->getUsuario() == nombreUsuario) {
                return usuarioActual;
            }

            temp = temp->getSiguiente();
        }

        // Si no se encuentra el usuario, devolver nullptr
        return nullptr;
    }
    Usuario* obtenerUsuarioAleatorioMayorDeEdad() {
        std::vector<Usuario*> candidatos;

        NodoUsuario* temp = inicio;

        // Recorrer la lista de usuarios y seleccionar aquellos mayores de edad
        while (temp != nullptr) {
            Usuario* usuario = temp->getUsuario();
            if (usuario->getEdad() >= 18) {
                candidatos.push_back(usuario);
            }

            temp = temp->getSiguiente();
        }

        // Verificar si hay usuarios disponibles
        if (candidatos.empty()) {
            return nullptr;  // No hay usuarios mayores de edad disponibles
        }

        // Generar un índice aleatorio
        int indiceAleatorio = rand() % candidatos.size();

        // Devolver el usuario seleccionado aleatoriamente
        return candidatos[indiceAleatorio];
    }

    // Método para obtener un usuario aleatorio menor de edad
    Usuario* obtenerUsuarioAleatorioMenorDeEdad() {
        std::vector<Usuario*> candidatos;

        NodoUsuario* temp = inicio;

        // Recorrer la lista de usuarios y seleccionar aquellos menores de edad
        while (temp != nullptr) {
            Usuario* usuario = temp->getUsuario();
            if (usuario->getEdad() < 18) {
                candidatos.push_back(usuario);
            }

            temp = temp->getSiguiente();
        }

        // Verificar si hay usuarios disponibles
        if (candidatos.empty()) {
            return nullptr;  // No hay usuarios menores de edad disponibles
        }

        // Generar un índice aleatorio
        int indiceAleatorio = rand() % candidatos.size();

        // Devolver el usuario seleccionado aleatoriamente
        return candidatos[indiceAleatorio];
    }

};
#endif // LISTA_USUARIOS_H
