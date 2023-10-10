#ifndef SOFTWARE_H
#define SOFTWARE_H

#include <iostream>
#include <string>
#include <vector>  // Necesitas incluir la librería vector para usar std::vector
using namespace std;

class Software {
protected:
    string nombre;
    string developer;
    int clasificacion;
    int precio;
    vector<string> listaUsuarios;  // Nuevo atributo: lista de usuarios

public:
    // Constructor
    Software(string _nombre, string _developer, int _clasificacion, int _precio)
        : nombre(_nombre), developer(_developer), clasificacion(_clasificacion), precio(_precio) {}

    // Métodos para obtener y establecer el nombre
    string getNombre() {
        return nombre;
    }

    void setNombre(string _nombreX) {
        nombre = _nombreX;
    }

    // Métodos para obtener y establecer la lista de usuarios
    vector<string> getListaUsuarios() {
        return listaUsuarios;
    }

    void setListaUsuarios(const vector<string>& usuarios) {
        listaUsuarios = usuarios;
    }

    // Método para agregar un usuario a la lista
    void agregarUsuario(string usuario) {
        listaUsuarios.push_back(usuario);
    }
    void eliminarUsuario(const string& usuario) {
    for (size_t i = 0; i < listaUsuarios.size(); ++i) {
        if (listaUsuarios[i] == usuario) {
            listaUsuarios.erase(listaUsuarios.begin() + i);
            return;  // Salir del bucle después de eliminar el usuario 
        }
    }
}
    virtual void decirxd(){
        return;
    }
    int getClasificacion(){
        return clasificacion;
    }
    void setClasificacion(int _clasi){
        clasificacion=_clasi;
    }
};
#endif
