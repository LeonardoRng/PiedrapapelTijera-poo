#include<iostream>
using namespace std;

//setter establece valores
//getter, sirve para mostrar, para dar información
class jugador {
    private: //atributos
    int jugada;
    
    public: //metodos

    jugador(){
        jugada = 0;
    }

    jugador(int op){
        if (op >=1 && op <=3 ){
        jugada = op;
    }  else {
        jugada = 0;
        cout << "Opcion invalida" << endl;
    }

}

int getJugada(){
    return jugada;
}

void setJugada(int op){
    if(op>=1 && op<=3){
        jugada=op;
    } else {
        cout << "debes poner algun numero entre 1 y 3"<< endl;
    }
}

void seleccionar(){
    int op;
    bool validar = false;

    while(!validar){
        cout << "Piedra papel o tijera!\n "<<endl;
        cout << "1 - Piedra "<< endl;
        cout << "2 - Papel "<< endl;
        cout << "3 - Tijera "<< endl;

        if (cin >> op){
            if(op >=1 && op <= 3){
                jugada= op;
                validar= true;
           } else {
            cout <<"No pusiste un numero valido"<< endl;
        } // podemos poner un clear aca con else
    }
};
}
};


class Evaluador{
    private: 
    jugador j1;
    jugador j2;

    public:
    Evaluador(jugador jugador1, jugador jugador2){
        j1= jugador1;
        j2= jugador2;
    }

    int evaluar(){
        int jugada1= j1.getJugada();
        int jugada2= j2.getJugada();


        if (jugada1==jugada2){
            return 0;
        }

        if((jugada1==1 && jugada2==3)||
        (jugada1==2 && jugada2==1)||
        (jugada1==3 && jugada2==2)){
          return 1; // si alguno de estos es true gana jugador 1
        }

        return -1; //sino gana jugador 2
  
    }
};


class Visualizador{
    private:
    jugador j1;
    jugador j2;

    public:
    Visualizador(jugador jugador1, jugador jugador2);

    void simboloJugada(int jugada){
        switch(jugada) {
            case 1:
            cout << "Piedra" <<"()";
            break;
            case 2:
            cout << "Papel" << "[]";
            break;
            case 3:
            cout << "Tijera" << "8<";
            break;
            default:
            cout <<"jugada invalida";
    }
    cout << endl;
    }


    void visualizarJuego(){
        cout << "\n-Juegos---\n" << endl;
        cout << "Jugador 1 Eligio: ";
        simboloJugada(j1.getJugada());
        
        cout << "Jugador 2 Eligio: ";
        simboloJugada(j2.getJugada());
    }

    void mostrarGanador(Evaluador& evaluador) {
        int resultado = evaluador.evaluar();
        cout<< "\n************"<< endl;

        if (resultado==1){
            cout << "*** JUGADOR 1 ES EL GANADOR! ***" <<endl;
        } else if (resultado==-1) {
            cout << "*** JUGADOR 2 ES EL GANADOR! ***" <<endl;
        } else {
            cout << "*** EMPATE! ***" <<endl;
        }
        cout << endl;      
    }




};


Visualizador::Visualizador(jugador jugador1, jugador jugador2) : j1(jugador1), j2(jugador2) {}



int main(){
    jugador jugador1;
    jugador jugador2;

    cout<< "\n*-*-*-*-*PIEDRA PAPEL O TIJERA*-*-*-*-*\n" << endl;
    cout<< "Jugador 1:"  << endl;
    jugador1.seleccionar();
    cout<< "\n\n\n"<< endl;
    cout<< "Jugador 2:"  << endl;
    jugador2.seleccionar();


    Evaluador evaluador(jugador1, jugador2);
    Visualizador visualizador(jugador1, jugador2);

    visualizador.visualizarJuego();
    visualizador.mostrarGanador(evaluador);

    return 0;


}