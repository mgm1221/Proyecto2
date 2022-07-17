#include "MapAVL.h"

using namespace std;

void MapAVL::insert(const string &key, int value){
    //creacion de nodo basico
    Node* n = new Node();
    n->key = key;
    n->value = value;
    n->parent = NULL;
    n->left = NULL;
    n->right = NULL;
    n->height = 0;

    //vemos si la raiz es nula
    if(root == NULL){
        root = n;

    }else{
        int hashValue = hash(key);
        Node* helper = root;
        bool inserted = false;
        bool newInsertion = false;

        while(!inserted){

            if(hashValue == hash(helper->key)){
                helper->value = value;
                inserted = true;

            }else if(hashValue > hash(helper->key)){

                if(helper->right == NULL){

                    helper->right = n;
                    n->parent = helper;
                    inserted = true;
                    newInsertion = true;

                }else{
                    helper = helper->right;
                }

            }else{

                if(helper->left == NULL){
                    helper->left = n;
                    n->parent = helper;
                    inserted = true;
                    newInsertion = true;
                }else{
                    helper = helper->left;
                }

            }

        }
        if(newInsertion){

            s++;

            if(n!= root){
                cout<< "check"<< endl;
                updateHeight(n->parent);
                checkbalance(n->parent);
            
            }

        }

    }

}
void MapAVL::erase(const string &key){
    int hashValue = hash(key);
    Node* helper = root;
    bool erase;
    while(helper->key != key){
        //buscamos si la key esta en el AVL
        if(hashValue> hash(helper->key)){

            helper = helper->right;

        }else{
            helper = helper->left;
        }
        if(helper->key == key){
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

                this->erase(succesor->key);
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
            updateHeight(parent);
            checkbalance(parent);
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
void MapAVL::rightRotation(Node* n){
    Node* ancestor = NULL;
    bool isLeft = false;
    bool isRoot = true;
    cout<<endl<<"Right rotation"<< endl;
    if(n != root){

        ancestor = n->parent;
        isRoot = false;
        cout<< "ancestor: "<< ancestor->key<< endl;
        if(ancestor->left == n){

            isLeft = true;
        
        }
    }
    Node* nSon = n->left;
    Node* x = nSon->right;

    n->left = x;
    n->parent = nSon;
    nSon->right = n;
    if(x!=NULL){
        x->parent = n;
    }
    if(isRoot){
        cout<< "isRoot"<< endl;
        nSon->parent = NULL;
        root = nSon;
    
    }else{
        nSon->parent = ancestor;
        if(isLeft){

            ancestor->left = nSon;

        }else{
            ancestor->right = nSon;
        }

    }
    updateHeight(n);
    
}
void MapAVL::leftRotation(Node* n){
    //ocupamos parent por si no estamos en la raiz para volver a asignar el nodo
    //en la posicion que corresponde
    Node* ancestor = NULL;
    //este booleano nos dice si estamos a la izquierda del parent
    bool isLeft = false;
    bool isRoot = true;
    cout<< "left rotation"<< endl;
    if(n != root){

        ancestor = n->parent;
        isRoot = false;

        if(ancestor->left == n){

            isLeft = true;
        
        }

    }
    Node* nSon = n->right;
    Node* x = nSon->left;
    cout<< 1<< endl;
    cout<< "n es : "<< n->key<< endl;
    cout<< "nSon es: "<< nSon->key<< endl;
    if(x!= NULL){
        cout<< "x es: " << x->key;
    }else{
        cout<< "x es null"<< endl;
    }
    //basic movement
    nSon->left = n;
    n->parent = nSon;
    n->right = x;
    if(x != NULL){
        x->parent = n;
    }
    if(isRoot){
        cout<< "isRoot"<< endl;
        nSon->parent = NULL;
        root = nSon;
    
    }else{
        nSon->parent = ancestor;
        if(isLeft){

            ancestor->left = nSon;

        }else{
            ancestor->right = nSon;
        }

    }
    cout<< "ended rotation"<< endl;
    updateHeight(n);

}
void MapAVL::updateHeight(Node* n){
    if(n->left == NULL && n->right == NULL){

        n->height = 0;
    
    }else if(n->left != NULL && n->right == NULL){

        n->height = n->left->height +1;
    
    }else if(n->right != NULL && n->left== NULL){

        n->height = n->right->height +1;
    }
    else{
        if(n->left->height > n->right->height){
            
            n->height = n->left->height+1;

        }else{
            n->height = n->right->height +1;
        }
    }
    
    if(n->parent!=NULL){

        updateHeight(n->parent);
    
    }

}
void MapAVL::checkbalance(Node* n){
    int rigthHeight, leftHeight;
    bool rotation = false;
    //calculamos el balance
    //en caso de que uno de los nodos sea nulo se considera con altura menos 1
    //ya que los nodos sin hijos tienen altura 0

    if(n->right != NULL){
        
        rigthHeight = n->right->height;

    }else{

        rigthHeight = -1;
    
    }
    if(n->left != NULL){

        leftHeight = n->left->height;

    }else{

        leftHeight = -1;

    }
    n ->balance = leftHeight - rigthHeight;
    cout<< n->key << n->balance<< endl;
    if(n->balance>1){
        cout<< "balance"<< endl;
        if(n->left->balance<0){

            leftRotation(n->left);
        
        }
        rightRotation(n);
        rotation = true;
    }
    if(n->balance<-1){

        if(n->right->balance>0){

            rightRotation(n->right);
        
        }
        leftRotation(n);
        rotation = true;
    }
    if(n->parent != NULL && !rotation){
        checkbalance(n->parent);
    }
}
void MapAVL::help(){
    cout<<"root key "<< root->key<< endl;

    this->indegree(root);
}
void MapAVL::indegree(Node* n){
    if(n->left!= NULL){
        indegree(n->left);
    }
    cout<< n->key<< endl;
    cout<< "height: " << n->height<<endl;
    if(n->right!= NULL){
        indegree(n->right);
    }
}