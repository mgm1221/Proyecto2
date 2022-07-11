#include "MapAVL.h"

using namespace std;

void MapAVL::insert(const string &key, int value){
    //creating new node with initial values
    Node* newNode = new Node();
    newNode->key = key;
    newNode->value = value;
    newNode->parent = NULL;
    newNode->right = NULL;
    newNode->left = NULL;


    if(root == NULL){

        root = newNode;
    
    }else{
        Node* helper = root;
        while(1){
            if(hash(key)>hash(helper->key)){

                if(helper->right == NULL){
                    helper->right = newNode;
                    newNode->parent = helper;
                    break;
                }else{
                    helper = helper->right;                
                }
            }else{
                if(hash(key)<hash(helper->key)){
                    if(helper->left == NULL){
                        helper->left = newNode;
                        newNode->parent = helper;
                        break;
                    }else{
                        helper = helper->left;
                    }
                }else{
                    break;
                }

            }

        }

    }
    

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
Node* MapAVL::rightRotation(Node* r){

    Node* toReturn = r->left;
    Node* rightchild = toReturn->right;
    toReturn->right = r;
    root->left = rightchild;

    return toReturn
}
Node* MapAVL::leftRotation(Node* r){
    
    Node* toReturn = r->right;
    Node* leftchild = toReturn->left;
    toReturn->left = r;
    r->left = leftchild;

    return toReturn;
}