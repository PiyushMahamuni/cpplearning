#include <bits/stdc++.h>
using namespace std;

int main()
{
  //write your code here
  size_t T;
  cin >> T;
  
  while(T--){
    size_t M, N, n{}, pow_2{1}, op{};
    cin >> M >> N;
    if(M==N){
        cout << "0" << endl;
        continue;
    }
    while(pow_2<N){
        pow_2 *= 2;
        n++;
    }
    if(pow_2 > N) n--;
    while(((M>>n)&1) && ((N>>n)&1)) n--;
    n++;
    pow_2 = 1;
    while(n--){
        op += pow_2;
        pow_2 *= 2;
    }
    cout << op << endl;
  }
  
  return 0;
}