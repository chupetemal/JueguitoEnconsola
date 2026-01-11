#include <vector>
#include <iostream>
#include <string>
#include <conio.h>
#include <limits>

void MostrarMapa(const std::vector<std::vector<char>>& Mapa){
    for (auto it = Mapa.begin(); it != Mapa.end(); it++){
        for (auto xd = (*it).begin(); xd != (*it).end(); xd++) {
            std::cout<<*xd <<" ";
        }
        std::cout<<"\n";
    }
}

const std::vector<std::vector<char>>PasarMapa(int TipoDeMapa){
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
    Mapa[MitadFil][1]='E';
    Mapa[MitadFil][5]='#';
    return Mapa;
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
    if ( Casilla == '.'){
        return true;
    }else{
        return false;
    }
}

void VerAccion(char Simbolo){
        /*
        # = Puertas
        E = enemigos
        */
    switch(Simbolo){
        case 'E':
            std::cout<<"noooo un oso wacho";
            break;
        case '#':
            std::cout<<"noooooo no lo puedo creer una puerta👌";
            break;
    }
}

void MoverPersonaje(int PosicionFilaDeseada, int PosicionColumnasDeseada,std::vector<std::vector<char>>& Mapa/*struct nashe()*/){
    char CaracterPosicionDeseada = Mapa[PosicionFilaDeseada][PosicionColumnasDeseada];
    bool TorF = VerificarSiguienteCasilla(PosicionFilaDeseada, PosicionColumnasDeseada, Mapa);
    if ( TorF == true){
        std::vector CordJugador=BuscarJugador(Mapa);
        Mapa[PosicionFilaDeseada][PosicionColumnasDeseada]='@';
        Mapa[CordJugador[0]][CordJugador[1]]='.';
    }else{
        VerAccion(CaracterPosicionDeseada);
    }
    return;
} 

void Movimiento(std::vector<std::vector<char>>& Mapa){
    int Tecla;    
    std::cout<<"Presione ESC para dejar de moverse"<<"\n";
    do{
        std::cout<<"\n";
        auto Posi = BuscarJugador(Mapa);
        struct JugadorPosicion
        {
            int Filas;
            int Columnas;
        };JugadorPosicion Posicion;
        Posicion.Filas=Posi[0];
        Posicion.Columnas=Posi[1];
        MostrarMapa(Mapa);
        Tecla=getch();
        if(Tecla==27){
            std::cout<<'\n';
            break;
        }
        if(Tecla==80){
            std::cout<<'\n';
            MoverPersonaje(Posicion.Filas+1,Posicion.Columnas,Mapa);
        }
        if(Tecla==72){
            std::cout<<'\n';
            MoverPersonaje(Posicion.Filas-1,Posicion.Columnas,Mapa);
        }
        if(Tecla==75){
            std::cout<<'\n';
            MoverPersonaje(Posicion.Filas,Posicion.Columnas-1,Mapa);
        }
        if(Tecla==77){
            std::cout<<'\n';
            MoverPersonaje(Posicion.Filas,Posicion.Columnas+1,Mapa);
        }
    }while(true);
}

int main(){
    int Filas;
    int Columnas;
    auto Mapa= PasarMapa(1);
    Movimiento(Mapa);
    return 0;
}
