#ifndef  ADT_MAP_H
#define ADT_MAP_H

#include <string>

using namespace std;

class ADTMap{
public:
  virtual void insert(const string&, int)=0;
  virtual void erase(const string&)=0;
  virtual int at(const string&)=0;
  virtual int size()=0;
  virtual bool empty()=0;
  

};

#endif
