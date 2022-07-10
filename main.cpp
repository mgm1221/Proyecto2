#include "ADTMap.h"
#include "MapSV.h"
#include <iostream>

int main(){

  MapSV* map = new MapSV();
  /*
  for(int i = 0; i < rep; i++){
    cin>>str;
    map->insert(str,i);
  }
  */
  map->insert("labar",1);
  map->insert("aoeu",2);
  map->insert("aoeuao",3);
  map->insert("ioeui",4);
  map->insert("aoeub",5);
  map->insert("euidm",6);
  map->insert("wxbmt",7);
  map->insert("hhfe",8);
  map->print();

  map->erase("hhfe");

  cout<<map->at("tioeui")<<endl;
  return 0;
}
