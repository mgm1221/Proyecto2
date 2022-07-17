#ifndef  MAP_HASH_H
#define MAP_HASH_H

#include "AdtMap.h"
#include "par.h"

using namespace std;

class mapGG : public AdtMap{

public:
  mapGG(int size){
    max_size = size;
    arr = new par * [max_size];

    for (int i = 0; i < max_size; i++){
      arr[i] = NULL;
    }
  }

  void insert(const string& str, int num);
  void erase(const string& str);
  int at(const string& str);
  int size();
  bool empty();

private:

  int parCount = 0;
  int max_size;
  par* marca = new par("marca",-1);
  par** arr;
  int hash(string key);
  int hash2(int hash);
  void reSize();

};


#endif
