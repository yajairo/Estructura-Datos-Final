#include<iostream>
using namespace std;
#include "Software.h"
class Seguridad: public Software{
    private:
    bool activo;
    string tipo;

    public:
    Seguridad(string _nombre, string _developer, int _clas,int _precio,string _tipo):
    Software(_nombre,_developer,_clas,_precio),activo(true),tipo(_tipo){}
    

    //Esto igual lo agregue como extra porque pensaba hacer métodos extras, pero había leído mal el word
    void desactivar(){
        activo=false;
    }
    void decirxd() override{
        return;
    }
};