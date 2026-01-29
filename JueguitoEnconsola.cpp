#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include "Combate.h"
#include "Jugador.h"
#include "movimiento.h"


const std::vector<std::vector<char>>CrearMapa(){
    struct ConfigMapa {
    int filas;
    int columnas;
    };ConfigMapa MAPAD;

    MAPAD.filas=15;
    MAPAD.columnas=25;
    
    std::vector<std::vector<char>>Mapa(MAPAD.filas, std::vector<char>(MAPAD.columnas, '.'));
    int MitadFil = MAPAD.filas / 2;
    Mapa[MitadFil][4]='@';
    Mapa[MitadFil][1]='E';
    Mapa[MitadFil][5]='#';
    return Mapa;
}

void clasePJS::Menu(){
    std::vector<std::vector<char>>MapaInicial = CrearMapa();
int Op;
        std::cout<<"-----------------------------\n";
        std::cout<<"1. Moverse\n2. Ver Datos De Personaje\n3. Ver Inventario\n4. Descansar\n5.Ver mapa\n";
        std::cout<<"-----------------------------\n";
        std::cout<<"ingrese la opcion que quiere: ";
        std::cin>>Op;
        switch (Op){
        case 1:
            Movimiento(MapaInicial);
            break;
        case 2:
            VerDatosDePersonaje();
            break;
        case 3:
            VerInventario();
            break;
        case 4:
            //descanzar()
            break;
        case 5:
            MostrarMapa(MapaInicial);
            break;
        }         
}        

int main(){
    int OpPArt;
    do{
        std::cout<<"1. Cargar Partida\n2. Nueva Partida\n";
        std::cout<<"ingrese la opcion que quiere seleccionar:";
        std::cin>>OpPArt;
        if (OpPArt == 1 or OpPArt ==2){
            break;
        }
    }while(true);

    std::string nombre;
    std::cout<<"ingrese su nombre: ";
    std::cin>>nombre;    
    
    clasePJS Jugador = clasePJS::SeleccionDePersonaje(nombre);
    
    while (true){
        bool vivo;
        vivo=Jugador.estado();
        if (vivo == false){
            break;
        }else{
            Jugador.Menu();
        };
    };
    std::cout<<"\nperdiste papoi >_<";
    Jugador.~clasePJS();
};
