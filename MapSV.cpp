#include "MapSV.h"
#include <algorithm>
#include <iostream>
#include <climits>

int binarySearch(vector<pair<string, int>> v, string x, int n) {
   int lower = 0;
   int upper = n - 1;
   while (lower <= upper) {
      int mid = lower + (upper - lower) / 2;
      int res;
      if (x == (v[mid].first))
         res = 0;
      if (res == 0)
         return mid;
      if (x > (v[mid].first))
         lower = mid + 1;
      else
         upper = mid - 1;
   }
   return -1;
}

void insertAux(vector<pair<string, int>>& v,const string& key, int value){
  int index = binarySearch(v, key, v.size());
  if(index == -1){
    auto it = lower_bound(v.begin(), v.end(), make_pair(key, value));
    v.insert(it, make_pair(key, value));
  }
  else{
    v.at(index).second = value;
  }
}

void MapSV::insert(const string& key, int value){
    insertAux(v, key, value);
}

int MapSV::at(const string& key){
  int index = binarySearch(v, key, v.size());

  if(index != -1)return v.at(index).second;
  return -1;
}

void MapSV::eraseAux(const string& key, vector<pair<string,int>>& vec){
  int index = binarySearch(v, key, v.size());
  if(index != -1) v.erase(v.begin() + index);
}

void MapSV::erase(const string& key){
  eraseAux(key, v);
}

int MapSV::size(){
  return v.size();
}

bool MapSV::empty(){
return v.empty();
}
