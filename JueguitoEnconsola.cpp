#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <conio.h>
#include "Combate.h"
#include "Jugador.h"
#include "movimiento.h"
#include "Jugador.h"



const std::vector<std::vector<char>>Pasarmapa(int TipoDeMapa){
    struct ConfigMapa {
    int filas;
    int columnas;
    };ConfigMapa MAPAD;

    switch (TipoDeMapa)
    {
    case 1:    
        MAPAD.filas=15;
        MAPAD.columnas=25;
        break;
    }
    std::vector<std::vector<char>>Mapa(MAPAD.filas, std::vector<char>(MAPAD.columnas, '.'));
    int MitadFil = MAPAD.filas / 2;
    Mapa[MitadFil][4]='@';
    Mapa[MitadFil][5]='#';
    Mapa[MitadFil][2]='E';
    return Mapa;
}

// la interfaz que va a ver el usuario


//el madafukin destructor

std::vector<std::vector<char>> mapa;

void MostrarMapa(const std::vector<std::vector<char>>& Mapa){
    for (auto it = Mapa.begin(); it != Mapa.end(); it++){
        for (auto xd = (*it).begin(); xd != (*it).end(); xd++) {
            std::cout<<*xd <<" ";
        }
        std::cout<<"\n";
    }
}

const std::vector<int> BuscarJugador(const std::vector<std::vector<char>>& Map){
    struct Pussy
    {
        int PosicionF;
        int PosicionC;
    };Pussy P;
    int Fila=-1;
    int Columna=-1;
    for(auto it = Map.begin(); it != Map.end(); it++){
        Fila++;
        Columna=-1;
        for (auto Colum = (*it).begin(); Colum != (*it).end(); Colum++){
            Columna++;
            if ((*Colum) == '@'){
                P.PosicionF=Fila;
                P.PosicionC=Columna;
            }
        }
    }
    std::vector<int> Cords={P.PosicionF,P.PosicionC};
    return Cords;
}

bool VerificarSiguienteCasilla(int PosicionFila, int PosicionColumnas, std::vector<std::vector<char>>Mapa){
    const char Casilla=Mapa[PosicionFila][PosicionColumnas];
    if (Casilla == '.'){
        return true;
    }else{
        return false;
    }
}

void clasePJS::Combate(){
    std::cout<<"no pelien";
}

void clasePJS::EncuentroConEnemigo(char caracter){
    if (caracter=='E'){
        std::cout<<"te encuentras un guardia con una poronga gigante";
        Combate();
    }
}

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
            std::vector<std::vector<char>> Mapa=Pasarmapa(1);
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
    
    clasePJS Jugador = SeleccionDePersonaje(nombre);
    
    while (true){
        bool vivo;
        vivo=Jugador.estado();
        if (vivo == false){
            break;
        }else{
            jugador.Menu();
        };
    };
    std::cout<<"\nperdiste papoi >_<";
    Jugador.~clasePJS();

};
