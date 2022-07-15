#include <iostream>
#include "MapAVL.h"

using namespace std;

int main(){

    MapAVL* mapavl = new MapAVL();
    string s;
    for (int i = 0; i < 70; i++)
    {
        cin>>s;
        mapavl->insert(s,i);
    }
    

    mapavl->help();

    return 0;
}