#include <iostream>

using namespace std;

void swap(long int &a, long int &b){
    if(a<b){
        long int temp;
        temp = a;
        a = b;
        b = temp;
    }
}

int main(){
    int T;
    cin >> T;
    for(int i{}; i<T; i++){
        long int cost_green, cost_purple;
        cin >> cost_green >> cost_purple;
        long int participants;
        cin >> participants;
        long int first_prb{}, second_prb{};
        while(participants){
            bool temp;
            cin >> temp;
            if(temp) first_prb++;
            cin >> temp;
            if(temp) second_prb++;
            participants--;
        }
        swap(first_prb, second_prb);
        swap(cost_green, cost_purple);
        cout << first_prb * cost_purple + second_prb * cost_green << endl;
        
    }
    
    return 0;
}