#ifndef _LISTATITULARES_
#define _LISTATITULARES_ 0

#include <stdlib.h>
#include <iostream>
#include "nododoble.h"


#define POSITION_BEGINNING 0
#define POSITION_END 99999999

struct listaTitulares {
    int size = 0;
    nododoble* start = nullptr;
    nododoble* end = nullptr;

    void add(struct TNoticia* pTitle){
        insert(pTitle, POSITION_END);
    } 

    void addAtBeginning(struct TNoticia* pTitle){
        insert(pTitle,POSITION_BEGINNING);
    }

    int insert(struct TNoticia* pValue, int pPosition) {
        int result = 0;

        nododoble* newNodo = (nododoble*)malloc(sizeof(struct nododoble));
        newNodo->data = *pValue; 

        if (size==0) {
            start = newNodo;
            end = newNodo;
            newNodo->next = start;
            newNodo->prev = end;
        } else {
            if (pPosition==0) {
                newNodo->next =  start;
                newNodo->prev = end;
                start->prev = newNodo;
                end->next = newNodo;
                start = newNodo;    
            } else {
                int currentPosition = 0;
                nododoble* cursor = start;

                while (cursor!=end && currentPosition<pPosition) {
                    cursor = cursor->next;
                    currentPosition++;
                }

                newNodo->next = cursor->next;
                newNodo->prev = cursor;
                cursor->next = newNodo;
                if (cursor==end) {
                    end = newNodo;
                    start->prev = newNodo;
                }

            }
        }
        size++;
        return result;
    }
};



/*
void insertar(Titular pTitular);// insertar en la lista de titulares

void delete(Titular pTitular);// borrar lista de titulares

Titular *listar();// imprimir lista de titulares

Titular *buscar(string palabraDeBusqueda);// imprimir los titulares

Titular *eliminar(string palabraDebusqueda);// eliminar titular con cierta palabra

Titular *cambiarPosicion(Titular pTitular);//cambiar de relevancia un titular
*/

#endif