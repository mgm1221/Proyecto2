#include "MapAVL.h"

using namespace std;

void MapAVL::insert(const string &key, int value){

    

}
void MapAVL::erase(const string &key){

}
int MapAVL::at(const string &key){
    Node* helper = root;

    while(hash(key) != hash(helper->key)|| key != helper->key){

        if(hash(key) >= hash(helper->key))
        {

            helper = helper->right;

        }else{

            helper = helper->left;

        }

    }
    return helper->value;

}
int MapAVL::size(){
    return s;
}
bool MapAVL:: empty(){

    if(root == NULL){

        return true;
    }

    return false;
}
int MapAVL::hash(const string &key){

    int hashValue = 0;

    for(int i= 0;i<key.length();i++){

        hashValue += (int)key[i]*33*(i+1);

    }
    return hashValue;
}