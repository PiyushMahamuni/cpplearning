#include <iostream>
#include "BST.h"

using namespace std;

int main(){
    
    BST<int> integer{5};
    integer.insert(6);
    integer.insert(4);
    integer.insert(3);
    integer.insert(7);
    integer.inorder();
    
    return 0;
}