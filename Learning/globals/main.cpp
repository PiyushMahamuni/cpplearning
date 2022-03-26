#include <iostream>

using namespace std;

// ALl global variables when they are declared without initalization info
// will always be initialized to their default values even if they are
// of primitive type.

int num;  // will always be initialized to 0

int main(){
    int num2;  // will contain garbage value.
    cout << "num from global scope: " << num << endl
         << "num2 from local scope: " << num2 << endl;
    
    return 0;
}