#include "List.h"
#include <iostream>

using namespace std;

void ordenar(int * values, int pSize) {
    List<int>  *aux = new List<int>();
    List<int> *stack = new List<int>();
    List<int> *stack2 = new List<int>();

    for(int i=0; i < pSize; i++){
        stack->push(&values[i]);
    }

    while(!stack->isEmpty()){
        stack2->push(stack->pop());

        while(!aux->isEmpty() && *aux->getFirst()->getData() < *stack2->getFirst()->getData()){
            int x = *aux->pop();
            stack->push(&x);
        }
        aux->push(stack2->pop());

        
    }

    for(int i=0; i < aux->getSize(); i++){
        cout<<*aux->find(i)<<",";
    }
}

int main() {
int values[5] = {2,4,5,1,6};
int size = *(&values + 1) - values;
ordenar(values,size);

}