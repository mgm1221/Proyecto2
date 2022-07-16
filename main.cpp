#include <iostream>
#include "MapAVL.h"

using namespace std;

int main(){

    MapAVL* mapavl = new MapAVL();
    string s;
    mapavl->insert("c",1);
    mapavl->insert("a",1);
    mapavl->insert("b",1);
    //mapavl->insert("e",1);
    //mapavl->insert("d",1);

    mapavl->help();

    return 0;
}