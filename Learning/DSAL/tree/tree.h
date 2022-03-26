#ifndef _TREE_H_
#define _TREE_H_

template <typename T>
class Tree{
    class Paths{
        struct PE{
            Node* ptr;
            PE* next;
            PE* prev;
            PE(): ptr{nullptr}, next{nullptr}, prev{nullptr}{
            }
            PE(Node* val, PE* pr):ptr{val}, prev{pr}, next{nullptr}{
            }
        };
        PE* pe;
        size_t sz;
        Paths():pe{new PE()}, sz{0}{
        }
        void append(Node* node){
            sz++;
            if(!(pe->prev)){
                ptr = node;
                return;
            }
            while(pe->next) pe = pe->next;
            pe->next = new PE{node, pe};
        }
    };
    struct Node{
        T elem;
        Node* up; // pointer to upward node
        // a dynamic array of pointers to Node downwards
        Paths paths;
        
        Node(const T& val): elem{val}, up{nullptr}, paths{}{
        }
        Node():elem{}, paths{}{
        }
    };
    
    Node* node;
    
    Tree(const T& val):node{new Node{val}}{
    }
    Tree():node{nullptr}{
    }
    void add(const T& val){
        if(!node){
            node = new Node{val};
            return;
        }
        node->paths.append(new Node{val})
    }
    void up(){
        
    }
    
    void down
};

#endif