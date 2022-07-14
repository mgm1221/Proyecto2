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
        checkbalance(newNode->parent);

    }
    s++;

}
void MapAVL::erase(const string &key){
    int hashValue = hash(key);
    Node* helper = root;
    bool erase;
    while(root != NULL ||helper->key != key){
        //buscamos si la key esta en el AVL
        if(hashValue> hash(helper->key)){

            helper = helper->right;

        }else{
            helper = helper->left;
        }
        if(helper-> key == key){
            erase = true;
        }
    }
    if(erase){
        if(helper != root){
            Node* parent = helper->parent;
            bool left;
            if(parent->left == helper){
                left = true;
            }

            if(helper->right != NULL && helper->left!= NULL){
                //los dos hijos son distintos de NULL
                Node* succesor = helper->right;

                while(succesor->left != NULL){

                    succesor = succesor->left;
                
                }
                string newKey = succesor->key;
                int newValue = succesor->value;

                erase(succesor);
                helper->key = newKey;
                helper->value = newValue; 

            }else{
                if(helper->right != NULL){
                    //el hijo derecho es distinto de NULL
                    Node* replacement = helper->right;
                    free(helper);
                    if(left){
                        parent->left = replacement;
                    }else{
                        parent->right = replacement;
                    }
                    
                }else{

                    if(helper->left!= NULL){
                        Node* replacement = helper->left;
                        free(helper);
                        if(left){
                            parent->left = replacement;
                        }else{
                            parent->right = replacement;
                        }

                    }else{
                        //los dos hijos son NULL
                        if(left){
                            parent->left = NULL;
                        }else{
                            parent->right = NULL;
                        }

                    }

                }
                
            }
            updateHeight(helper->parent);
            checkbalance(helper->parent);
        }else{
            free(root);
            root = NULL;
        }
    
    }

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

    }
    return hashValue;
}
void MapAVL::rightRotation(Node* r){
    Node* parent;
    bool left = false;
    if(r != root){
        
        parent = r->parent;
        if(r == parent->left){
            left == true;
        }

    }
    Node* son = r->left;
    Node* sonSRight = son->right;
    son->right = r;
    
    r->parent = son;
    r->left = sonSRight;

    if(r != root){

        if(left){
            parent->left = son;
        }else{
            parent->right = son;
        }

    }else{
        son->parent = NULL;
        root = son;
    }

}
void MapAVL::leftRotation(Node* r){
    //ocupamos parent por si no estamos en la raiz para volver a asignar el nodo
    //en la posicion que corresponde
    Node* parent = NULL;
    //este booleano nos dice si estamos a la izquierda del parent
    bool left = false;
    if(r!= root){

        parent = r->parent;
        if(r == parent->left){
            left == true;
        }
    }
    //reasignamos los nodos en el orden que corresponde
    Node* son = r->right;
    Node* sonSLeft= son->left;
    son->left = r;

    r->parent = son;
    r->right = sonSLeft;

    if(r != root){

        if(left){
            parent->left = son;
        }else{
            parent->right = son;
        }

    }else{
        son->parent = NULL;
        root = son;
    }

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
    int rigthHeight, leftHeight;

    //calculamos el balance
    //en caso de que uno de los nodos sea nulo se considera con altura menos 1
    //ya que los nodos sin hijos tienen altura 0

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
    //asignamos el balance a cada nodo
    n->balance = leftHeight - rigthHeight;

    if(n->balance>1 ||n->balance<-1){

        if(n->balance>1){
            //el arbol es mas pesado hacia la izquierda por lo que hay que hacer una rotacion a la derecha
            
            //si el subarbol es mas pesado hacia la derecha rotamos el subarbol hacia la izquierda
            if(n->left->balance<0){
                leftRotation(n->left);
            }
            rightRotation(n);
        }
        if(n->balance<-1){
            //el arbol es mas pesado hacia al derecha por lo que hay que rotar hacia la izquierda
            
            //si el subarbol es mas pesado hacia la izquierda rotamos el subarbol
            if(n->right->balance>0){

                rightRotation(n->right);
            
            }
            leftRotation(n);
        }

    }else{
        if(n->parent !=NULL){
            checkbalance(n->parent);
        }
        
    }

}