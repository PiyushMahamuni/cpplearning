#include <bits/stdc++.h>
using namespace std;

int main()
{
  //write your code here
  unsigned int T;
  cin >> T;
  char temp;
  
  while(T--){
    long int N, max_count{}, Q{}, X, count;
    cin >> N;
    bool seq[N] {};
    long int i;
    for(i = 0; i<N; i++){
        cin >> temp;
        if(temp == 'p'){
            seq[i] = true;
            max_count++;
        }
    }
    cin >> Q;
    while(Q--){
        cin >> X;
        if(X<=max_count){
            for(i = 0, count = 0; count<X; i++){
                if(seq[i]) count++;
            }
            cout << i << endl;
        }
        else cout << "-1" << endl;
    }
    
  }
  
  
  return 0;
}