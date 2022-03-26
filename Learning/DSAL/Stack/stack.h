#ifndef _STACK_H_
#define _STACK_H_
#include "datatypes.h"

template<typename T>
class Stack{
    template<typename U>
    struct SE{
        SE<U>* down;
        U elem;
        SE(const U& source):down{nullptr}, elem{source}{
        }
        SE(const SE<U>& source) : elem{source.elem} {
            SE<U>* ptr1{this}, ptr2{source.down};
            while(ptr2){
                ptr1->down = new SE<U>{ptr2->elem};
                ptr1 = ptr1->down;
                ptr2 = ptr2->down;
            }
        }
        SE(const SE<U>&& source) : down{elem.down}, elem{source.elem} {
            source.down = nullptr;
        }
    };
    SE<T>* TE;
    size_t sz;
    const std::string typ{"Stack("+datatype<T>()+")"};
public:
    Stack():TE{nullptr}, sz{0}{
    }
    Stack(const T& val):TE{new SE<T>{val}}, sz{1}{
    }
    Stack(const Stack<T>& source):TE{new SE<T>{*(source.TE)}}, sz{source.sz}{
    }
    void push(const T& val){
        SE<T>* temp = new SE<T>{val};
        temp->down = TE;
        TE = temp;
        sz++;
    }
    T pop(){
        T temp{ TE->elem };
        SE<T>* ptr{TE};
        TE = TE->down;
        delete ptr;
        sz--;
        return temp;
    }
    size_t size() const{
        return sz;
    }
    
    T& top() {
        return TE->elem;
    }
    
    const std::string& type(){
        return typ;
    }
    
    ~Stack(){
        SE<T>* ptr{TE};
        while(TE){
            ptr = ptr->down;
            delete TE;
            TE = ptr;
        }
    }
};
#endif