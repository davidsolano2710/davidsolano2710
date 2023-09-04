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

    void listar(){   // saca a consola cada uno de los elementos de la lista
        nododoble* cursor = start; // primer nodo de la lista
        int counter = 0;

        while(counter < size){
            struct TNoticia noticiaactual = ((struct TNoticia)(cursor->data));
            cout << noticiaactual.titular <<endl;
            cursor=cursor->next;
            counter++;
        }
    }

    int search(string pTitle){
        nododoble* cursor = start;

        int counter = 0;

        while(counter < size){
            struct TNoticia noticiaactual = ((struct TNoticia)(cursor->data));
            if (pTitle == noticiaactual.titular){
                return counter;
            }

            cursor=cursor->next;
            counter++;
        }
        return -1;
    }

    /*delete*/

    void deleteTitular(string pTitle){
        int pos = search(pTitle);

        nododoble* cursor = start;

        int counter = 0;

        while(cursor != nullptr){
            if((cursor->data).titular == pTitle){
                if (cursor->prev != end){
                    (cursor->prev)->next = cursor->next;
                }else{ //si entra es que se va a eliminar el start
                    start = cursor->next;
                }

                if (cursor->next != nullptr){
                    (cursor->next)->prev = cursor->prev;
                }
                size--;
                return;
            }
            cursor = cursor->next;
        }
    }

    /*reorder*/

    void reorder(struct TNoticia* pTitle, string reub, int newPos){
        nododoble* cursor = start;
        int counter = 0;
        
        int max = search(pTitle->titular);

        while(counter <= max){
            cursor=cursor->next;
            counter++;
        }

        if (reub == "+"){
            counter = (counter - newPos)-1;
        }else if( reub == "-"){
            counter = (counter + newPos)-1;
        }

        deleteTitular(pTitle->titular);
        insert(pTitle, counter);





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