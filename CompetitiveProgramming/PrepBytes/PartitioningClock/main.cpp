#include <bits/stdc++.h>
using namespace std;

int main()
{
  //write your code here
  size_t N;
  cin >> N;
  size_t count{}, p_count{};
  bool temp[N]{};
  size_t i, last{0}, first{0};
  for(i=0; i < N ; i++){
      cin >> temp[i];
      if(temp[i]) count++;
      else{
        if(count>p_count){
            p_count = count;
            if(first==0)first=p_count;
        }
        count = 0;
    }
  }
  if(temp[i] && temp[N-1] && first+count>p_count){
      p_count = first + count;
  }
  
  cout << p_count << endl;
  
  return 0;
}