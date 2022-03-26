#include <iostream>

using namespace std;

int main(){
    size_t T;
    cin >> T;
    for(size_t i{}; i<T; i++){
        int seat_no;
        cin >> seat_no;
        int cmp_no { (seat_no - 1) / 12  }; //compartment no, starts from 0
        int facing_seat { (2*cmp_no+1) * 12 + 1 - seat_no };
        cout << facing_seat << ' ';
        if(facing_seat%3<=1){
            if((facing_seat/3)%2) cout << "AS" << endl;
            else cout << "WS" << endl;
        }
        else{
            cout << "MS" << endl;
        }
    }
    
    return 0;
}