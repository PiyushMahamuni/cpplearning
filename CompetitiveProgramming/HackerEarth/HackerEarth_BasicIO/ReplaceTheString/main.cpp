#include <iostream>

using namespace std;

size_t str1[128], str2[128];

bool is_sol();

int main(){
    size_t TC;
    cin >> TC;
    size_t length;
    char temp;

    size_t i;
    for(i=0; i<128; i++){
        str1[i] = 0;
        str2[i] = 0;
    }
    while(TC--){
        cin >> length;
        
        for(i=0; i<length; i++){
            cin >> temp;
            str1[temp]++;
        }
        for(i=0; i<length; i++){
            cin >> temp;
            str2[temp]++;
        }
        cout << (is_sol()? "YES" : "NO") << endl;
        
    }
    
    return 0;
}

bool is_sol(){
    size_t diff{};
    for(int i{}; i<128; i++){
        if(str1[i]>str2[i]){
            diff += (str1[i]-str2[i]);
        }else{
            diff += (str2[i]-str1[i]);
        }
        str1[i] = 0;
        str2[i] = 0;
    }
    cout << diff << endl;
    if (diff < 3){
        return true;
    } else{
        return false;
    }
}