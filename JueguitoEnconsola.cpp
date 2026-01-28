#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <conio.h>
#include "Combate.h"
#include "Jugador.h"
#include "movimiento.h"
#include "Jugador.h"

void clasePJS::Menu(){
int Op;
    while (true){
        std::cout<<"-----------------------------\n";
        std::cout<<"1. Moverse\n2. Ver Datos De Personaje\n3. Ver Inventario\n4. Descansar\n5.Ver mapa\n";
        std::cout<<"-----------------------------\n";
        std::cout<<"ingrese la opcion que quiere: ";
        std::cin>>Op;
        switch (Op){
        case 1:
            /* lo de moverse con la flechitas*/
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
            std::vector<std::vector<char>> Mapa=PasarMapa(1);
            Movimiento(Mapa);
            break;
        }    
    }        
}        

int main(){
    int OpPArt;
    do{
        std::cout<<"1. Cargar Partida\n2. Nueva Partda";
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
