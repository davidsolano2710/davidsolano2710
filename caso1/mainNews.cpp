#include "listatitulares.h"
#include "nododoble.h"

#include <stdlib.h>
#include <iostream>

using namespace std;

int main(){
    listaTitulares listatitulares;
    TNoticia n1 = {"titular1"};
    TNoticia n2 = {"titular2"};
    TNoticia n3 = {"titular3"};
    TNoticia n4 = {"titular4"};
    TNoticia n5 = {"titular5"};

    listatitulares.addAtBeginning(&n1);
    listatitulares.addAtBeginning(&n2);
    listatitulares.addAtBeginning(&n3);
    listatitulares.addAtBeginning(&n4);
    listatitulares.addAtBeginning(&n5);
    /*
    for(nododoble* cursor = listatitulares.start; cursor!=nullptr; cursor=cursor->next){
        struct TNoticia noticiaactual = ((struct TNoticia)(cursor->data));
        cout << noticiaactual.titular <<endl;
    }*/

    nododoble* cursor = listatitulares.start;
    while(cursor != nullptr){
        struct TNoticia noticiaactual = ((struct TNoticia)(cursor->data));
        cout << noticiaactual.titular <<endl;
        cursor=cursor->next;
    }

}