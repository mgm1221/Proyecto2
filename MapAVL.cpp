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
    newNode->height = 0;
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
    if(newNode != root){

        updateHeight(newNode->parent);

    }
    s++;

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

    for(int i =0; i<key.length(); i++){

        hashValue = hashValue+ (int)key[i]*33*(i+1);
        cout<< hashValue<< endl;
    }
    return hashValue;
}
void MapAVL::rightRotation(Node* r){

    Node* toReturn = r->left;
    Node* rightchild = toReturn->right;
    toReturn->right = r;
    root->left = rightchild;

}
void MapAVL::leftRotation(Node* r){
    
    Node* toReturn = r->right;
    Node* leftchild = toReturn->left;
    toReturn->left = r;
    r->left = leftchild;

}
void MapAVL::updateHeight(Node* n){
    if(n->left != NULL && n->right!=NULL){

        if(n->left->height>n->right->height){

            n->height = 1+ n->left->height;

        }else{

            n->height = 1+ n->right->height;

        }

    }else{

        if(n->left == NULL){

            n->height = n->right->height +1;

        }else{
            n->height = n->left->height +1;
        }
    }
    if(n->parent!=NULL){
        updateHeight(n->parent);
    }

}
void MapAVL::checkbalance(Node* n){
    int rigthHeight, leftHeight, balance;
    if(n->left == NULL){
        leftHeight = -1;
    }else{
        leftHeight = n->left->height;
    }
    if(n->right == NULL){
        rigthHeight = -1;
    }else{
        rigthHeight = n->right->height;
    }
    balance = leftHeight - rigthHeight;
    if(balance<1){
        //el arbol es mas pesado hacia la izquierda por lo que hay que hacer una rotacion a la derecha

    }
    if(balance>1){
        //el arbol es mas pesado hacia al derecha por lo que hay que rotar hacia la izquierda

    }

}