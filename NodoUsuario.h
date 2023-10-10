#include "Usuario.h"

class NodoUsuario {
private:
    Usuario* usuario;
    NodoUsuario* siguiente;

public:
    NodoUsuario(Usuario* _usuario) : usuario(_usuario), siguiente(nullptr) {}

    Usuario* getUsuario() {
        return usuario;
    }

    void setUsuario(Usuario* _usuario) {
        usuario = _usuario;
    }

    NodoUsuario* getSiguiente() {
        return siguiente;
    }

    void setSiguiente(NodoUsuario* _siguiente) {
        siguiente = _siguiente;
    }
};
