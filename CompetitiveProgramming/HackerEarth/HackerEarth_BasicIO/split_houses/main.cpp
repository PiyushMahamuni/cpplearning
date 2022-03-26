#include <iostream>

using namespace std;
class grids{
private:

public:
    long int grid_size;
    bool houses[grid_size]{}, spaces[grid_size]{};
    void grid(long int size){
        grid_size = size;
        for(long int i{}; i<grid_size; i++){
            char temp;
            cin >> temp;
            if(temp=='H')
                houses[i] = true;
            else
                spaces[i] = true;
        }

    }
    void print(){
        for(long int i{}; i<grid_size; i++){
            if(houses[i]) cout << 'H';
            else if(spaces[i]) cout << '.';
            else cout << 'B';
        }
    }
}

int main(){
    long int grid_size;
    cin >> grid_size;
    grids grid(grid_size);
    
    
    
    return 0;
}