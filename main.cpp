#include <iostream>
#include "MapAVL.h"

using namespace std;

int main(){

    MapAVL* mapavl = new MapAVL();
    mapavl->insert("a", 1);
    mapavl->insert("b", 1);
    mapavl->insert("c", 1);

    return 0;
}