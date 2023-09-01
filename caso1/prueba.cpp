#include <iostream>
#include <string>

using namespace std;

typedef struct TNoticia {
	string Titulo;
    int Pos;
	TNoticia* Siguiente;
    TNoticia* Anterior;
}*PtrTNoticia;

void InicializarListaNoticias(PtrTNoticia& Lista) {
	Lista = nullptr;
}

PtrTNoticia CrearNoticia(string pTitulo, int pPos){
	PtrTNoticia Noticia = new(TNoticia);
	
	Noticia->Titulo = pTitulo;
    Noticia->Pos = pPos,

	Noticia->Siguiente = nullptr;
    Noticia->Anterior = nullptr;
	return Noticia;
}

void AddToBeggining(PtrTNoticia& Lista, PtrTNoticia& Nuevo) {
	if(Nuevo->Anterior == nullptr){
        Nuevo->Siguiente = Lista;
	    Lista = Nuevo;
    }
    
}

void Add(PtrTNoticia& Lista, PtrTNoticia& Nuevo){
	PtrTNoticia Aux;
	Aux = Lista;
	if (Aux != nullptr)
	{
		while (Aux->Siguiente != nullptr)
		{
			Aux = Aux->Siguiente;
		}

		Aux->Siguiente = Nuevo;
	}
	else
	{
		Lista = Nuevo;
	}


}

PtrTNoticia SearchNoticia(PtrTNoticia& Lista, int cual) {
	bool encontro = false;

	PtrTNoticia Aux;

	Aux = Lista;

	while (!encontro == true && Aux != nullptr)

	{
		if (Aux->Pos == cual)

			encontro = true;

		else

			Aux = Aux->Siguiente;

	}

	return Aux;

}

void Delete(PtrTNoticia& Lista){
	PtrTNoticia Aux;
	Aux = Lista;
	while (Aux != NULL)
	{
		Lista = Lista->Siguiente;
		delete(Aux);
		Aux = Lista;
	}
}

void ListNoticias(PtrTNoticia& Lista){
	int Contador = 1;
	PtrTNoticia Aux;
	Aux = Lista;
	while (Aux != NULL)
	{
		cout<<"Noticia "<< Contador <<endl;
        cout<<Aux ->Titulo<<endl;
		Aux = Aux->Siguiente;
		Contador++;
	}
}

int main(){

    PtrTNoticia lista;

    PtrTNoticia noticia1;
    PtrTNoticia noticia2;
    PtrTNoticia noticia3;
    PtrTNoticia noticia4;
    PtrTNoticia noticia5;

    InicializarListaNoticias(lista);

    noticia1 = CrearNoticia("Noticia1", 1);
    noticia2 = CrearNoticia("Noticia2", 2);
    noticia3 = CrearNoticia("Noticia3", 3);
    noticia4 = CrearNoticia("Noticia4", 4);
    noticia5 = CrearNoticia("Noticia5", 5);

    Add(lista, noticia1);
    Add(lista, noticia2);
    Add(lista, noticia3);
    Add(lista, noticia4);
    Add(lista, noticia5);

    ListNoticias(lista);

    Delete(lista);
    
}