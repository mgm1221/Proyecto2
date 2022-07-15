#include <iostream>
#include "MapAVL.h"

using namespace std;

int main(){

    MapAVL* mapavl = new MapAVL();
    mapavl->insert("m", 1);
    mapavl->insert("l", 1);
    mapavl->insert("k", 1);
    mapavl->insert("j", 1);
    mapavl->insert("i", 1);
    mapavl->insert("h", 1);
    mapavl->insert("g", 1);
    mapavl->insert("f", 1);
    mapavl->insert("e", 1);
    mapavl->insert("d", 1);
    mapavl->insert("c", 1);
    mapavl->insert("b", 1);
    mapavl->insert("z", 1);
    mapavl->insert("t", 1);
    mapavl->insert("w", 1);
    mapavl->insert("a", 1);

    

    mapavl->help();

    return 0;
}