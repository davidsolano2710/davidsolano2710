#ifndef _NODODOBLE_
#define _NODODOBLE_ 0

#include <iostream>
#include <string>

using namespace std;

struct TNoticia {
    string titular;
};

struct nododoble {
    struct TNoticia data;
    struct nododoble* next = nullptr; 
    struct nododoble* prev = nullptr;
};

#endif