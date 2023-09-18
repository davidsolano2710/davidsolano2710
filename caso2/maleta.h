#ifndef MALETA

#define MALETA 1

using namespace std;

class Maleta
{
private:
    int idPersona; 
    

public:

    Maleta(){
        idPersona = 0;
    }
    
    Maleta(int pId){
        idPersona = pId;
    }

    int getIdPersona(){
        return idPersona;
    }

};

#endif