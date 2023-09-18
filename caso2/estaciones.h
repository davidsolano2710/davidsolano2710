#include "queue.h"
#include "List.h"
#include "stack.h"
#include "persona.h"
#include "maleta.h"

#ifndef ESTACIONES

#define ESTACIONES 1

using namespace std;

//*******************CHECK IN***********************************

class Checkin //NAME
{
public: // ATRIBUTOS
    List<Persona> *colaCheckin; //COLA
};

//*******************MANEJO DE MALETAS***********************************

class RayosX //NAME
{
public: // ATRIBUTOS
    List<Maleta> *colaRayosX; //COLA
};

class Carrito //NAME
{
public: // ATRIBUTOS
    List<Maleta> *pilaCarrito; //PILA
};

class BordajeDeMaletas //NAME
{
public: // ATRIBUTOS
    List<Carrito> *listaCarritos; //LISTA
};

//*******************ADUANAS***********************************

class Aduanas //NAME
{
public: // ATRIBUTOS
    List<Persona> *colaAduanas; //COLA
};

//*******************REVISION DE SEGURIDAD***********************************

class Revision //NAME
{
public: // ATRIBUTOS
    List<Persona> *colaRevision; //COLA
};

//*******************CUARTO OSCURO***********************************

class Inspeccion //NAME
{
public: // ATRIBUTOS
    List<Persona> *colaInspeccion; //COLA
};

//*******************ZONA LIBRE***********************************

class Baños //NAME
{
public: // ATRIBUTOS
    List<Persona> *colaBaños; //COLA
};


class DutyFree //NAME
{
public: // ATRIBUTOS
    List<Persona> *colaDutyFree; //COLA
};


class Comidas //NAME
{
public: // ATRIBUTOS
    List<Persona> *colaComidas; //COLA
};



//*******************SALA DE ESPERA***********************************

class SalaDeEspera //NAME
{
public: // ATRIBUTOS
    List<Persona> *colaSalaDeEspera; //COLA
};


//*******************BORDAJE AL AVION***********************************

class BordajeAlAvion //NAME
{
public: // ATRIBUTOS
    List<Persona> *colaPasajeros; //COLA
    List<Maleta> *pilaMaletas; //PIlA
};

//*******************CARCEL***********************************

class Carcel //NAME
{
public: // ATRIBUTOS
    List<Persona> *listaCarcel; //LISTA
};

#endif