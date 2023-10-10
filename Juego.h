    #include<iostream>
    using namespace std;
    #include "Software.h"
    class Juego: public Software{
        private:
        double tiempoRecord;
        string tipo;
        public:
        Juego(string _nombre, string _developer, int _clas,int _precio,string _tipo):
        Software(_nombre,_developer,_clas,_precio),tiempoRecord(100*10000),tipo(_tipo){}


        //Esto ignorelo, leí la pauta otra vez y no era necesario, era una idea :(
        void setTiempo(double record){
            if (record<tiempoRecord){
                cout<<"Nuevo tiempo registrado, superado por"<<tiempoRecord -record<<" segundos"<<endl;
                tiempoRecord=record;
            }else{
                cout<<"El tiempo ingresado no supera el registrado: "<<tiempoRecord<<endl;
            }
        }
        
    };