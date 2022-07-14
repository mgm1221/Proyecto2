#include "AdtMap.h"
//#include "MapSV.h"
#include "MapAvl.h"
#include <iostream>

int main(){

  MapAvl* mapa = new MapAvl();
/*
  for(int i = 0; i < rep; i++){
    cin>>str;
    map->insert(str,i);
  }
  */
  mapa->insert("labar",1);
  mapa->insert("aoeu",2);
  mapa->insert("boeuao",3);
  mapa->insert("ioeui",4);
  mapa->insert("zoeub",5);
  mapa->insert("euidm",6);
  mapa->insert("wxbmt",7);
  mapa->insert("hhfe",8);

  //mapa->print();


  mapa->erase("hhfe");
  mapa->print();
  cout<<endl;
  cout<<mapa->at("aoeu")<<endl;

  mapa->erase("zoeub");
  mapa->print();
  cout<<endl;
  cout<<mapa->at("hhfe")<<endl;

  return 0;
}
