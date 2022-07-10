#ifndef ADTMAP_H
#define ADTMAP_H
#include <string>

using namespace std;

class AdtMap{

    //key = string, value = int
    virtual void insert(const string &,int) = 0;// insertar par
    virtual void erase(const string &) = 0; //borrar un par clave valor
    virtual int at(const string &) = 0; // encontrar el valor asociado a una clave
    virtual int size() = 0; //devuelve el tamano
    virtual bool empty() = 0;// verifica si esta vacio

};


#endif