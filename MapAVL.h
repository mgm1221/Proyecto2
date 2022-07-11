#ifndef MAP_AVL_H
#define MAP_AVL_H
#include "AdtMap.h"
#include <iostream>

class MapAVL: public ADTMap{
    struct Node {
        pair<string,int> par;
        Node* parent;
        Node* left;
        Node* right;
    };
    public:

        void insert(const string &,int);
        void erase(const string &);
        int at(const string &);
        int size();
        bool empty();
    private:
        Node* root;
};


#endif
