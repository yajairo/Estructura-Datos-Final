#include<iostream>
using namespace std;

#include "Software.h"
class Produccion: public Software{
    private:
    string tipo;
    public:
    Produccion(string _nombre, string _developer, int _clas,int _precio,string _tipo):
    Software(_nombre,_developer,_clas,_precio),tipo(_tipo){
    while (true) {
            if (_clas >= 18) {
                clasificacion = _clas;
                break;
            } else {
                cout << "Edad no válida. La edad debe ser mayor o igual a 18. Ingrese de nuevo: ";
                cin >> _clas;
            }
        }
    }
    
};