#include <iostream>
int global{400};
using namespace std;

int main(){
    cout << global << endl; //400
    {
        int global{-10};
        cout << global << endl; //-10
        {
            int global{200};
            cout << global << endl; //200
            {
                cout << global << endl; //200
            }
            {
                extern int global;
                // it is the exact same as `global variable`
                cout << global << endl; // 400
            }
        }
    }
    
    return 0;
}