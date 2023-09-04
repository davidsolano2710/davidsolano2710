#include "listatitulares.h"
#include "nododoble.h"

#include <stdlib.h>
#include <iostream>

using namespace std;

int main(){
    system("clear");
    int continua = 1;

    listaTitulares listatitulares;
    TNoticia n1 = {"titular1"};
    TNoticia n2 = {"titular2"};
    TNoticia n3 = {"titular3"};
    TNoticia n4 = {"titular4"};
    TNoticia n5 = {"titular5"};

    listatitulares.add(&n1);
    listatitulares.add(&n2);
    listatitulares.add(&n3);
    listatitulares.add(&n4);
    listatitulares.add(&n5);

    

    while (continua == 1)
    {   
        // cout de menu
        //**********************************************
        cout << "1: Mostrar titulares"<< endl;              
        cout << "2: Buscar titular"<< endl;
        cout << "3: Eliminar titular"<< endl;
        cout << "4: Reorganizar titular"<< endl;
        cout << "99: Salir"<< endl; 

        cout << "Opcion: ";

        int optn; 
        string title;
        string tituABorrar;
        char salir = '0';
        string mOm;
        int updtPos;

        cin >> optn;

        //**********************************************

        switch (optn)
        {
        case 1: // agregar titulares
            system("clear");
            listatitulares.listar();

            break;

        case 2: 
            system("clear");
            cout << "Nombre del titular: "; 

            cin >> title;
            cout << "Posicion: "<< listatitulares.search(title) << endl;

            break;
        case 3:
            cout << "Titular a borrar: ";
            cin>> tituABorrar;

            listatitulares.deleteTitular(tituABorrar);
            cout << tituABorrar << " eliminado"<<endl;

            break;
        case 4:
            cout << "Subir(+) o Bajar(-):";
            cin>>mOm;

            cout << "Posiciones: ";
            cin>>updtPos;

            listatitulares.reorder(&n2, mOm, updtPos); // buscar la forma de pasar el titular al parametro
            break;

        case 99 : 
            continua = 0;
            break;


        default:
            cout << "opcion no disponible"<<endl;

            break;
        }
    }
    
    
    
}