#include <iostream>

using namespace std;

int main(){
    int arr[]{1, 3, 5, 15, 16, 17, 18, 19, 20, 21, 25, 26, 27, 30, 50};
    // print if given value from this array is either divisible by 3 or 5 and
    // total count of such values at the end
    int count{};
    for(const int& value: arr){
        cout << ((value % 3 && value % 5)? "N" : (++count, "Y")) << endl;
    }
    cout << count << endl;
    
    return 0;
}