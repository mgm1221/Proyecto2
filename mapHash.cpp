#include "mapHash.h"
#include <iostream>
#include <cstring>
#include <math.h>

void mapGG::insert(const string& str, int num){
  par* aux = new par(str, num);

  int hashIndex = hash(str);
  int step = hash2(str[0]);

  while (arr[hashIndex] != NULL && arr[hashIndex]->first != "marca"){

    if(arr[hashIndex]->first == str){
      arr[hashIndex] = aux;
      parCount++;
      if(parCount >= max_size/2) reSize();
      return;
    }

    hashIndex = hashIndex + step;
    hashIndex = hashIndex % max_size;
  }

  arr[hashIndex] = aux;
  parCount++;
  if(parCount >= max_size/2) reSize();

}

void mapGG::reSize(){
  int newSize = max_size * 2;
  par** newArr = new par * [newSize];

  memcpy(newArr, arr, max_size * sizeof(par*));

  max_size = newSize;
  delete [] arr;
  arr = newArr;

}

void mapGG::erase(const string& str){
  int hashIndex = hash(str);
  int step = hash2(str[0]);

  while (arr[hashIndex] != NULL){
    if(arr[hashIndex]->first == str){
      arr[hashIndex] = marca;
      parCount--;
      return;
    }

    hashIndex = hashIndex + step;
    hashIndex = hashIndex % max_size;
  }

  return;
}

int mapGG::at(const string& str){
  int hashIndex = hash(str);
  int step = hash2(str[0]);

  while(arr[hashIndex] != NULL){
    if(arr[hashIndex]->first == str){
      return arr[hashIndex]->second;
    }
    hashIndex = hashIndex + step;
    hashIndex = hashIndex % max_size;
  }
  return -1;

}

int mapGG::size(){
  return parCount;
}

bool mapGG::empty(){
  if(parCount == 0) return false;
  return true;
}

void mapGG::display() {
   int i = 0;

   for(i = 0; i<max_size; i++) {

      if(arr[i] != NULL)
         cout<<"("<<arr[i]->first<<" "<<arr[i]->second<<")";
      else
         printf(" ~~ ");
   }

   printf("\n");
}

int mapGG::hash(string key){
  size_t sum = 0;
  for(int i = 0; i < key.length(); i++) {
    sum = sum + (key[i] * (int)pow(31, i)) % max_size;
  }
  return sum % max_size;
}

int mapGG::hash2(int hash){

  return 67 - (hash % 67);
}
