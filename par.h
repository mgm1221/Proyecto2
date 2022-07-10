#ifndef  PAR_H_
#define PAR_H_

#include <string>

using namespace std;

class par{

public:
  string first;
  int second;

  par(string key, int value){
    first = key;
    second = value;
  }
};

#endif
