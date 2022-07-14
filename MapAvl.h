#ifndef MAP_AVL_H
#define MAP_AVL_H

#include "AdtMap.h"

#include <cstddef>
#include <string>

using namespace std;

struct node{
    pair<string,int> key_value;
    struct node* left;
    struct node* right;
};

class MapAvl : public AdtMap{

public:
  MapAvl(){
    root = NULL;
  }

  void insert(const string& key, int value);
  void erase(const string& key);
  int at(const string& key);
  int size();
  bool empty();
  void print();

private:
  node* root;
  int numNodes = 0;

  int height(node* aux);
  int heightDiff(node* aux);
  node* rotation_1(node* parent);
  node* rotation_2(node* parent);
  node* rotation_3(node* parent);
  node* rotation_4(node* parent);
  node* insertAux(node* root, pair<string, int> par);
  node* minNode(node* aux);
  node* deleteAux(node* root, string key);
  void inorder(node* root);

};

#endif
