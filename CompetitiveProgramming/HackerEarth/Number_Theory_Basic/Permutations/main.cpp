#include <iostream>

using namespace std;

class Number{
    friend ostream& operator<<(ostream& os, const Number& number);
private:
    size_t size;
    char* digits;
public:
    Number(int64_t n): size{0}{
//        cout << "inside consturcotr\n";
        for(int64_t temp{n}; temp>0; temp /= 10, size++){}
        digits = new char[size]; // allocate memory
        for(size_t i{}; i<size; i++){ // digits stored in reverse
        // i.e. int 12340 is stored [0][1][2][3][4] in memory
            digits[i] = (n%10) + '0';
            n /= 10;
        }
    }
    Number(const char* str): size{0}{
        for(; str[size] != '\0'; size++){
        }
        digits = new char[size];
        for(size_t i{0}; i<size; i++){
            digits[i] = str[size-i-1];
        }
    }
    size_t get_digits(){
        return size;
    }
    ~Number(){
        delete [] digits; // release memory
    }
};

// nPr = n!/(n-r)! = n * (n-1) * ... (n-r+1)

ostream& operator<<(ostream& os, const Number& number){
    for(size_t i{number.size-1}; i>0; i--){
        os << number.digits[i];
    }
    os << number.digits[0];
    return os;
}

size_t nPr(int n, int r){
    size_t res{1};
    for(; r>0; r--) res *= static_cast<size_t>(n-r+1);
    return res;
}

int main(){
//    Number a{1230};
////    cout << "Inside main again\n";
//    cout << a.get_digits() << "\n";
//    cout << a << endl;
//    Number b{"12233344444555556666667777777888888889999999990000000000000"};
//    cout << b.get_digits() << "\n"
//         << b << endl;
    
    cout << nPr(3,2) << endl;
    cout << nPr(2,3) << endl; // will return 0 automatically
    // if r>n then in for loop inside nPr as r decrements to 0 surely
    // there will be a instant where r = n+1 and that will cause n-r+1 to
    // evalutate to 0 and res will always be zero after that
    // and that fits with theory too since there's no way to change 3 things
    // out of just 2 things
    
    return 0;
}