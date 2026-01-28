#include<iostream>
#include<string>
#include<vector>

class clasePJS{
    private:
    std::string Nombre;
    int Salud;
    int Danio;
    int Armadura;
    int Fila;
    int Columna;
    public:
    ~clasePJS();
    clasePJS(std::string,int,int,int);
    void Menu();
    auto SeleccionDePersonaje(std::string);
        void VerInventario(); 
        void VerDatosDePersonaje();
        void EquiparObjetos();
        int estado();
        void pegar();

    };

void clasePJS::Pegar(){

}

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
clasePJS::~clasePJS(){ 
};

// contrucctor con esto se inicializa las estadisticas del Pj
clasePJS::clasePJS(std::string _Nombre ,int _Salud,int _Danio ,int _Armadura){
    Nombre=_Nombre;
    Salud=_Salud;
    Danio=_Danio;
    Armadura=_Armadura;
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


clasePJS::SeleccionDePersonaje(std::string nombre){
    int op;
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





void clasePJS::EncuentroConEnemigo(char caracter){
    if (caracter=='E'){
        std::cout<<"te encuentras un guardia con una poronga gigante";
        Combate();
    }
}
