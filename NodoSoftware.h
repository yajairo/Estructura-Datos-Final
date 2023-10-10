#ifndef NODOSOFTWARE_H
#define NODOSOFTWARE_H
#include <iostream>
#include "Software.h"
using namespace std;

class NodoSoftware {
private:
    Software* software;
    NodoSoftware* siguiente;

public:
    NodoSoftware(Software* _software) : software(_software), siguiente(nullptr) {}

    Software* getSoftware() {
        return software;
    }

    void setSoftware(Software* _software) {
        software = _software;
    }

    NodoSoftware* getSiguiente() {
        return siguiente;
    }

    void setSiguiente(NodoSoftware* _siguiente) {
        siguiente = _siguiente;
    }
};
#endif
