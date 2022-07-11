#ifndef MAP_AVL_H
#define MAP_AVL_H
#include "AdtMap.h"
#include <iostream>
#include <string.h>

class MapAVL: public ADTMap{
    struct Node {
        string key;
        int value;
        Node* parent;
        Node* left;
        Node* right;
        int height;
    };
    public:

        void insert(const string &,int);
        void erase(const string &);
        int at(const string &);
        int size();
        bool empty();
        int hash(const string &);
        Node leftRotation(Node*);
        Node rightRotation(Node*);
    private:
        Node* root;
        int s;
};


#endif
