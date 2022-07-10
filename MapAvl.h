#ifndef MAPAVL_H
#define MAPAVL_H
#include <string>

class MapAVL{
    struct Nodo
    {

        pair<string, int> par;
        Node* right;
        Node* left;

    };
    private:

        Nodo raiz;

    public:
        void insert(const string &, int);
        void erase(const string &);
        int at(const string &);
        int size();
        bool empty();

};

#endif