#include "MapSV.h"
#include <algorithm>
#include <iostream>

void MapSV::insert(const string& key, int value){
  v.push_back(make_pair(key, value));
  sort(v.begin(), v.end());
}

int MapSV::at(const string& key){
  for(vector<pair<string, int>>::iterator it = v.begin(); it != v.end(); it++){
    if(it->first == key) return it->second;
  }
  return -1;
}

void MapSV::eraseAux(const string& key, vector<pair<string,int>>& vec){
  for(vector<pair<string, int>>::iterator it = v.begin(); it != v.end(); it++){
    if(it->first == key)
      v.erase(it);
  }
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

void MapSV::print(){
  for(vector<pair<string, int>>::iterator it = v.begin(); it != v.end(); it++){
    cout<<"("<<it->first<<", "<<it->second<<")"<<endl;
  }
}
