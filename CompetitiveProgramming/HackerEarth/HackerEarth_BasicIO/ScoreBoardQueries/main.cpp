#include <iostream>

using namespace std;

int main(){
    long int T, N, Q, player_no, score, count;
    
    cin >> T;
    while(T--){
        count = 1;
        cin >> N >> Q;
        long int *Array = new long int [N];
        bool dup, new_dup;
        for(long int j{}; j < N; j++){
            cin >> Array[j];
            if(Array[j]!=1000000000){
                dup = true;
                for(long int i{}; i<j; i++){
                    if(Array[i]==Array[j]){
                        dup = false;
                        break;
                    }
                }
                if(dup) count++;
            }
        }
        dup = new_dup = false;
        for(long int j{}; j < Q; j++){
            cin >> player_no >> score;
            player_no--;
            if(score != Array[player_no]){
                for(long int i{}; i<N; i++){
                    if(player_no == i) continue;
                    if(score == Array[i]) new_dup = true;
                    else if(Array[player_no] == Array[i]) dup = true;
                }
                if(dup && !new_dup) count++;
                else if(!dup && new_dup) count--;
            }
            cout << count << endl;
        }
        
        delete [] Array;
    }
    
    return 0;
}