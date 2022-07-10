#ifndef MAP_SV_
#define MAP_SV_

#include "AdtMap.h"
#include <vector>

using namespace std;

class MapSV : public AdtMap{
public:
  MapSV(){};
  void insert(const string& key, int value);
  void eraseAux(const string& key, vector<pair<string, int>>& vec);
  void erase(const string& key);
  int at(const string& key);
  int size();
  bool empty();
  void print();

private:
  vector<pair<string, int>> v;
};


#endif
