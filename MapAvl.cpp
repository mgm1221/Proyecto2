#include "MapAvl.h"
#include <cstring>
#include <iostream>

int MapAvl::height(node* aux){
  int h = 0;
  if(aux != NULL){
    int left_Height = height(aux->left);
    int right_Height = height(aux->right);
    int maxHeight = max(left_Height, right_Height);
    h = maxHeight++;
  }
  return h;
}

int MapAvl::heightDiff(node* aux){
  int left_Height = height(aux->left);
  int right_Height = height(aux->right);
  int diff = left_Height - right_Height;

  return diff;
}

node* MapAvl::rotation_1(node* parent){
  node* aux;
  aux = parent->right;
  parent->right = aux->left;
  aux->left = parent;

  return aux;
}

node* MapAvl::rotation_2(node* parent){
  node* aux;
  aux = parent->left;
  parent->left = aux->right;
  aux->right = parent;

  return aux;
}

node* MapAvl::rotation_3(node* parent){
  node* aux;
  aux = parent->left;
  parent->left == rotation_1(aux);

  return rotation_2(parent);
}

node* MapAvl::rotation_4(node* parent){
  node* aux;
  aux = parent->right;
  parent->right = rotation_2(aux);

  return rotation_1(parent);
}

node* MapAvl::insertAux(node* aux, pair<string, int> par){
  if (aux == NULL){
    aux = new node;
    aux->key_value = par;
    aux->left = NULL;
    aux->right = NULL;

    return aux;
  }

  if( par.first < (aux->key_value).first){
    aux->left = insertAux(aux->left, par);
  }
  else if ( par.first > (aux->key_value).first){
    aux->right = insertAux(aux->right, par);
  }
  else if (par.first == (aux->key_value).first)
    aux->key_value = par;


  int diff = heightDiff(aux);

  if(diff > 1){
    if(par.first < aux->left->key_value.first){
      aux = rotation_2(aux);
    }
    else if(par.first > aux->left->key_value.first){
      aux = rotation_3(aux);
    }
    else if(diff < -1){
      if(par.first > aux->left->key_value.first){
        aux = rotation_1(aux);
      }
      else if(par.first < aux->left->key_value.first){
        aux = rotation_4(aux);
      }
    }
  }

  return aux;
}

node* MapAvl::minNode(node* node){
  struct node* aux = node;

  while(!aux->left){
    aux = aux->left;
  }
  return aux;
}

node* MapAvl::deleteAux(node* root, string key){
  if(root == NULL) return root;

  if(key < (root->key_value).first)
    root->left = deleteAux(root->left, key);
  else if (key > (root->key_value).first)
    root->right = deleteAux(root->right, key);

    else{
      if (root->left == NULL || root->right == NULL){
        struct node* aux;
        if (root->left)
          aux = root->left;
        else
          aux = root->right;

        if(aux == NULL){
          aux = root;
          root = NULL;
        }
        else
          *root = *aux;

        free(aux);
      }
      else{
        node* aux = minNode(root->right);
        root->key_value = aux->key_value;

        root->right = deleteAux(root->right,aux->key_value.first);
      }
    }

  if (root == NULL) return root;

  int diff = heightDiff(root);

  if(diff > 1){
    if(heightDiff(root->left) >= 0){
      root = rotation_2(root);
    }
    else{
      root = rotation_3(root);
    }
  }
  else if(diff < -1){
    if (heightDiff(root->right) > 0){
      root = rotation_4(root);
    }
    else{
      root = rotation_1(root);
    }
  }

  return root;
}

void MapAvl::inorder(node* root){
  if(root == NULL) return;

  inorder(root->left);
  cout<<"key: "<<root->key_value.first<<", value: "<<root->key_value.second<<endl;
  inorder(root->right);
}

void MapAvl::print(){
  inorder(root);
}

void MapAvl::insert(const string& key, int value){
  pair<string,int> par = make_pair(key,value);
  numNodes++;
  root = insertAux(root, par);

}
void MapAvl::erase(const string& key){
  numNodes--;
  deleteAux(root, key);
}

int MapAvl::at(const string& key){
  node* aux = root;

  if(aux == NULL) return -1;

  while(aux != NULL){
    if( key < (aux->key_value).first){
      aux = aux->left;
    }
    else if ( key > (aux->key_value).first){
      aux = aux->right;
    }
    else if (key == (aux->key_value).first)
      return aux->key_value.second;
  }

  return -1;
}
int MapAvl::size(){
  return numNodes;
}
bool MapAvl::empty(){
  return !root;
}
