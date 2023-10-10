#include <iostream>
#include  "Software.h"
#include <vector>
using namespace std;

class Social: public Software{

    private:
    vector<string*> listaNombres;

    public:
    Social(string _nombre, string _developer, int _clasificacion, int _precio)
        : Software(_nombre, _developer, _clasificacion, _precio) {}

    // Método para agregar un nombre a la lista
    void agregarNombreAmigo(string nombre) {
    // Verificar si el nombre ya está en la lista
    for (string* nombrePtr : listaNombres) {
        if (nombrePtr != nullptr && *nombrePtr == nombre) {
            cout << "El amigo " << nombre << " ya está en la lista." << endl;
            return;
        }
    }

    // Agregar el nombre a la lista de amigos
    string* nuevoNombre = new string(nombre);
    listaNombres.push_back(nuevoNombre);
    cout << "Amigo " << nombre << " agregado." << endl;
}


    // Método para "borrar" un nombre de la lista
    void invalidarNombre(string nombre) {
        for (string* nombrePtr : listaNombres) {
            if (*nombrePtr == nombre) {
                // "Invalidar" el nombre asignando nullptr
                nombrePtr = nullptr;
                break;  // Terminar el bucle, ya que encontramos el nombre
            }
        }
    }

    // Método para imprimir la lista de nombres
    void imprimirNombres() {
        cout << "Nombres en Social:" << endl;
        for (string* nombrePtr : listaNombres) {
            if (nombrePtr != nullptr) {
                cout << "- " << *nombrePtr << endl;
            }
        }
    }
    
    // Función para verificar si un amigo ya está en la lista
    bool esAmigoRepetido(const string& nombreAmigo) {
        for (const string* amigo : listaNombres) {
            if (amigo != nullptr && *amigo == nombreAmigo) {
                return true;
            }
        }
        return false;
    }
    

    // Método para eliminar un nombre de la lista de amigos
    void eliminarNombreAmigo(string nombre) {
        for (size_t i = 0; i < listaNombres.size(); ++i) {
            if (*listaNombres[i] == nombre) {
                delete listaNombres[i]; // Liberar memoria
                listaNombres.erase(listaNombres.begin() + i);
                cout << "Amigo " << nombre << " eliminado." << endl;
                return; // Salir del bucle después de eliminar el amigo
            }
        }
        cout << "Amigo " << nombre << " no encontrado en la lista." << endl;
    }
    // Método para imprimir la lista de amigos

    void verListaAmigos() const {
        cout << "Lista de amigos en el software:" << endl;
        for (const string* nombrePtr : listaNombres) {
            cout << "- " << *nombrePtr << endl;
        }
    }

};