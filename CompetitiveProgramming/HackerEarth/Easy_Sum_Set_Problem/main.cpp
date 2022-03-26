#include<iostream>
#include<map>

using std::cin;
using std::cout;

int main(){
    std::map<unsigned int, unsigned int> B;
    size_t m, n, i, j;
    
    cin >> n;
    // create an array of size n
    unsigned int a[n];
    for(i=0; i<n; i++){
        cin >> a[i];
    }
    
    cin >> m;
    // create another array of size m
    unsigned int c[m];
    for(i=0; i<m; i++){
        cin >> c[i];
    }
    
    for(i = 0; i<m; i++){
        for(j=0; j<n; j++){
            auto diff = c[i] - a[j];
            B[diff] += 1;
        }
    }
    
    m--;
    for(const auto& elem: B){
        if(elem.second == m){
            cout << elem.first << " ";
        }
    }
    
    return 0;
}