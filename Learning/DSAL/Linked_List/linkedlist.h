#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_
#include <iostream>
#include <exception>
#include <string>
#include "datatypes.h"

template <typename T>
class List{
    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, const List<U>& list);
    bool empty;
    T data;
    List<T>* next;
    List<T>* prev;
    int* size;
    std::string type{ "list(" + datatype<T>() + ")" };
    
public:
    List();
    List(const T& val); // T arg constructor
    List(const List<T>& list); // deep copy constructor
    void append(const T& val);
    void extend(const List<T>& list); // deep copy semantics
    T pop();
    bool is_empty()const;
    int getsize()const;
    
    T& operator[](int ind);
    
    ~List();
};

class IndexErrorException{
    const char* what() const;
};

const char* IndexErrorException::what() const{
    std::cerr << "Error: The index is out of range!";
    return "Error: The index is out of range!";
}


template <typename U>
std::ostream& operator<<(std::ostream& os, const List<U>& list){
    os << list.type;
    if(list.empty) return os << "[]";
    os << "[ ";
    const List<U>* ptr {&list};
    while(ptr){
        os << (ptr->data) << ((ptr->next)?", ":" ]");
        ptr = ptr->next;
    }
    return os;
}

template<typename T>
List<T>::List():empty{true}, data{}, next{nullptr}, prev{nullptr}, size{ new int{0}}{
}

template <typename T>
List<T>::List(const T& val): empty{false}, data{val}, next{nullptr}, prev{nullptr}, size{ new int{1}}{    
}

template <typename T>
List<T>::List(const List<T>& list) : empty{list.empty}, data{list.data}, prev{nullptr}, size{ new int{*(list.size)}} {
    List<T>* ptr{this};
    for(List<T>* nx{list.next}; nx!=nullptr; nx = nx->next){
        ptr->next = new List<T>{nx->data};
        
        ptr->next->prev = ptr;
        ptr = ptr->next;
    }
}

template <typename T>
void List<T>::append(const T& val){
    (*size)++;
    if(empty){
        data = val;
        empty = false;
        return;
    }
    List<T>* ptr{this};
    while(ptr->next) ptr = ptr->next;
    ptr->next = new List<T>{val};
    ptr->next->prev = ptr;
}

template <typename T>
void List<T>::extend(const List<T>& list){
    List<T>* ptr{this};
    while(ptr->next){
        ptr = ptr->next;
    }
    ptr->next = new List<T>{list};
    ptr->next->prev = ptr;
    (*size) += *(list.size);
    delete ptr->size;
    while(ptr){
        ptr->size = size;
        ptr = ptr->next;
    }
}


template <typename T>
T List<T>::pop(){
    while(next) this = next;
    T temp{data};
    delete this;
    return temp;
}

template <typename T>
bool List<T>::is_empty()const{
    return empty;
}

template <typename T>
T& List<T>::operator [](int ind){
    List<T>* ptr{this};
    if(ind>=0){
        for( ; ind>0 && ptr; ind--){
            ptr = ptr->next;
        }
        if(ptr) return ptr->data;
        else throw IndexErrorException();
    }
    if(ind<0){
        while(ptr->next) ptr = ptr->next;
        for( ; ind<-1; ind++){
            ptr = ptr->prev;
        }
        if(ptr) return ptr->data;
        else throw IndexErrorException();
    }
}


template <typename T>
int List<T>::getsize()const{
    return *size;
}

template <typename T>
List<T>::~List(){
    if(next) delete next;
    
}
#endif