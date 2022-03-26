#include <iostream>

using namespace std;

void swap(int &a, int &b){
    if(a>b){
        int temp {a};
        a = b;
        b = temp;
    }
}

int main(){
    int x1,y1,x2,y2;
    size_t T;
    cin >> T;
    while(T--){
        cin >> x1 >> y1 >> x2 >> y2;
        int dist{};
        swap(x1,x2);
        swap(y1,y2);
        dist = (x2-x1 < y2 - y1)? (y2 - y1) : (x2 - x1);
        switch(dist){
            case 0:
                cout << "Second" << endl;
                break;
            case 1:
                cout << "First" << endl;
                break;
            default:
                cout << "Draw" << endl;
        }
    }
    
    
    return 0;
}