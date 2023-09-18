#ifndef PERSONA

#define PERSONA 1

using namespace std;

class Persona   
{
private:
    int id;
    int vuelo;
    
public:
    Persona(){
        id = 0;
        vuelo = 0;
    }

    Persona(int pId, int pVuelo){
        id = pId;
        vuelo = pVuelo;
    }

    int getId(){
        return id;
    }

    int getVuelo(){
        return vuelo;
    }


};

#endif