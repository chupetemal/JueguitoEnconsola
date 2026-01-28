#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <conio.h>

struct JugadorPosicion
{
    int Filas;
    int Columnas;
};
class clasePJS{
    private:
    std::string Nombre;
    int Salud;
    int Danio;
    int Armadura;
    int Fila;
    int Columna;
public:
    
        
    


    void VerInventario(); 

    void VerDatosDePersonaje();

    void EquiparObjetos();

    int estado();

    void Menu();

    void Movimiento(std::vector<std::vector<char>>& Mapa); 
    
    ~clasePJS();

    clasePJS(std::string,int,int,int);

    void Combate();
    void Pegar();
    
    
    void EncuentroConEnemigo(char Caracter);

    void VerAccion(char Caracter);

    void IngresoAEstructura(char caracter);

    void MoverPersonaje(int PosicionFilaDeseada, int PosicionColumnasDeseada,std::vector<std::vector<char>>&, JugadorPosicion& Personaje);

    
    void clasePJS::GenerarEnemigo();
    

};
clasePJS::~clasePJS(){
    
};

class Enemigo : private clasePJS
{
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


// contrucctor con esto se inicializa las estadisticas del Pj
clasePJS::clasePJS(std::string _Nombre ,int _Salud,int _Danio ,int _Armadura){
    Nombre=_Nombre;
    Salud=_Salud;
    Danio=_Danio;
    Armadura=_Armadura;

};

clasePJS Jugador = SeleccionDePersonaje(nombre);
    




void clasePJS::VerDatosDePersonaje(){
    std::cout<<"\n";
    std::cout<<"-----------------------------\n";
    std::cout<< "nombre:"  << Nombre     <<"\n";
    std::cout<< "salud:"   << Salud      <<"\n";
    std::cout<< "daño:"    << Danio      <<"\n";
    std::cout<< "armadura:"<< Armadura   <<"\n";
    std::cout<<"-----------------------------\n";
    std::cout<<"\n";
};

clasePJS SeleccionDePersonaje(std::string nombre){
    int op;
    int dano;
    int salud;
    int armadura;
    while (true){
        std::cout<<"-----------------------------\n";
        std::cout<<"1. Guerrero\n"<<"2. Mago\n";
        std::cout<<"-----------------------------\n";
        std::cout<<"ingrese la opcion que quiere: ";
        std::cin>>op;
        if (op<1 or op>2){
            std::cout<<"\nno existe numero para esa clase\n";
            continue;
        }else{
            break;
        }
    };
    std::cout<<"\n";
    //clase guerrero
    if (op == 1){
        std::cout<<"usted selecciono la clase guerrero\n";
        return clasePJS(nombre,100,15,25);
    //mago zaza👽
    }else{
        std::cout<<"usted selecciono la clase mago\n";
        return clasePJS(nombre,100,30,10);
    }
};

//para verificar si el jugador esta muelto
int clasePJS::estado(){
    bool vivo;
    if ( Salud <= 0 ){
        vivo=false;
    }else{
        vivo=true;
    }
    return vivo;
};

void clasePJS::EquiparObjetos(){
    std::cout<<"no esta hecho papoi\n";
};

void clasePJS::VerInventario(){
    std::cout<<"no esta hecho papoi\n";
};

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

void clasePJS::Pegar(){

}

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

void clasePJS::IngresoAEstructura(char caracter){
    std::cout<<"nashe";
}

void clasePJS::VerAccion(char Caracter){
    /*39
    # = Puertas
    E = enemigos
    */
   switch(Caracter){
       case 'E':
       EncuentroConEnemigo(Caracter); 
       break;
       case '#':
       std::cout<<"noooooo no lo puedo creer una puerta👌";
       break;
    }
}


void clasePJS::MoverPersonaje(int PosicionFilaDeseada, int PosicionColumnasDeseada,std::vector<std::vector<char>>& Mapa, JugadorPosicion& Personaje){
    char CaracterPosicionDeseada = Mapa[PosicionFilaDeseada][PosicionColumnasDeseada];
    bool TorF = VerificarSiguienteCasilla(PosicionFilaDeseada, PosicionColumnasDeseada, Mapa);
    if ( TorF == true){
        Mapa[PosicionFilaDeseada][PosicionColumnasDeseada]='@';
        Mapa[Personaje.Filas][Personaje.Columnas]='.';
        Personaje.Filas=PosicionFilaDeseada;
        Personaje.Columnas=PosicionColumnasDeseada;
    }else{
        VerAccion(CaracterPosicionDeseada);
    }
    return;
} 

void clasePJS::Movimiento(std::vector<std::vector<char>>& Mapa){
    int Tecla;    
    std::cout<<"Presione ESC para dejar de moverse"<<"\n";
    std::vector<int> Posi = BuscarJugador(Mapa);
    JugadorPosicion Posicion{Posi[0],Posi[1]};
    do{
        std::cout<<"\n";
        MostrarMapa(Mapa);
        Tecla=getch();
        if(Tecla==27){
            std::cout<<'\n';
            break;
        }
        if(Tecla==80){
            std::cout<<'\n';
            MoverPersonaje(Posicion.Filas+1,Posicion.Columnas,Mapa,Posicion);
        }
        if(Tecla==72){
            std::cout<<'\n';
            MoverPersonaje(Posicion.Filas-1,Posicion.Columnas,Mapa,Posicion);
        }
        if(Tecla==75){
            std::cout<<'\n';
            MoverPersonaje(Posicion.Filas,Posicion.Columnas-1,Mapa,Posicion);
        }
        if(Tecla==77){
            std::cout<<'\n';
            MoverPersonaje(Posicion.Filas,Posicion.Columnas+1,Mapa,Posicion);
        }
    }while(true);
}

int main(){
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
            Jugador.Menu();
        };
    };
    std::cout<<"\nperdiste papoi >_<";
    Jugador.~clasePJS();

};
