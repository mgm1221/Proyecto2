#include <iostream>
#include "MapAVL.h"

using namespace std;

int main(){

    MapAVL* mapavl = new MapAVL();
    string s;
    for (int i = 0; i < 10000; i++)
    {
        cin>>s;
        mapavl->insert(s,i);
    }
    
    mapavl->help();
    mapavl->erase("ad");
    return 0;
}