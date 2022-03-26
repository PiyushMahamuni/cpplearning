#ifndef _BST_H_
#define _BST_H_

#include<iostream>
#include<string>
#include "datatype.h"

template<typename T>
class BST{
    T data;
    BST<T>* left;
    BST<T>* right;
    std::string type { "BST("+datatype(T)+")" };
public:
    BST(const T& val);
    T getdata();
    void insert(const T& val);
    void inorder();
    ~BST();
};

template<typename T>
BST<T>::BST(const T& val) : data{val}, left{nullptr}, right{nullptr}{
    
}

template<typename T>
T BST<T>::getdata(){
    return data;
}

template<typename T>
void BST<T>::insert(const T& val){
    if(val == data) return;
    if(val < data) {
        if(left) left->insert(val);
        else left = new BST<T>{val};
    }
    if(val > data) {
        if(right) right->insert(val);
        else right = new BST<T>{val};
    }
}

template<typename T>
void BST<T>::inorder(){
    if(left) left->inorder();
    std::cout << data << " ";
    if(right) right->inorder();
}

template<typename T>
BST<T>::~BST(){
    if(left) delete left;
    if(right) delete right;
}

#endif