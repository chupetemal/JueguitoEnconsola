#include <iostream>
#include <string>

class Enemigo{
    private:
        std::string EnemigoNombre;
        int EnemigoSalud;
        int EnemigoDanio;
        int EnemigoArmadura;
    public:
        Enemigo(std::string,int,int,int);
        void PegarAlJugador();
};

Enemigo::Enemigo(std::string _EnemigoNombre ,int _EnemigoSalud,int _EnemigoDanio ,int _EnemigoArmadura){
    EnemigoNombre=_EnemigoNombre;
    EnemigoSalud=_EnemigoSalud;
    EnemigoDanio=_EnemigoDanio;
    EnemigoArmadura=_EnemigoArmadura;
}

Enemigo::PegarAlJugador(){
    std::cout<<"nashe";
}