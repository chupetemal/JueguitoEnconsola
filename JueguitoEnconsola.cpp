#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>


class clasePJS{
    private:
    std::string nombre;
    int salud;
    int danio;
    int armadura;

public:
    void VerInventario(); 

    void VerDatosDePersonaje();

    void EquiparObjetos();

    int estado();

    void Menu();

    void VerMapa(); 
    
    ~clasePJS();

    clasePJS(std::string,int,int,int);

};

// contrucctor con esto se inicializa las estadisticas del Pj
clasePJS::clasePJS(std::string _nombre ,int _salud,int _danio ,int _armadura){
    nombre=_nombre;
    salud=_salud;
    danio=_danio;
    armadura=_armadura;

};

void clasePJS::VerDatosDePersonaje(){
    std::cout<<"\n";
    std::cout<<"-----------------------------\n";
    std::cout<< "nombre:"  << nombre     <<"\n";
    std::cout<< "salud:"   << salud      <<"\n";
    std::cout<< "daño:"    << danio      <<"\n";
    std::cout<< "armadura:"<< armadura   <<"\n";
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
    if ( salud <= 0 ){
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

void clasePJS::VerMapa(){

};


 
// la interfaz que va a ver el usuario
void clasePJS::Menu(){
    int Op;
    while (true){
        std::cout<<"-----------------------------\n";
        std::cout<<"1. Moverse\n2. Ver Datos De Personaje\n3. Ver Inventario\n4. Descansar\n5.Ver mapa\n";
        std::cout<<"-----------------------------\n";
        std::cout<<"ingrese la opcion que quiere: ";
        std::cin>>Op;
        switch (Op)
        {
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
            VerMapa();
            break;
        default:
            std::cout<<"no existe opcion para ese numero, porfavor ingrese alguno numero que este en la lista\n";
            break;
        }
    }
};

//el madafukin destructor
clasePJS::~clasePJS(){
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

std::vector<std::vector<char>> mapa;
  

