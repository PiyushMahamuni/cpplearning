#include<iostream>
#include<string>
#include<sstream>
#include<iomanip>

using namespace std;

struct cursor{
    static const string up;
    static const string rw_line;
    static const string bold;
    static const string reset;
};
const string cursor::up{"\033[A"};
const string cursor::rw_line{"\r"};
const string cursor::bold { "\033[1m" };
const string cursor::reset { "\033[0m" };

int main(){
    string number{"0"};
    size_t sum{}, temp{};
    size_t gap {3};
    size_t field_1 = string("Running Sum").size();
    size_t field_2 = string("Enter number").size()+gap;
    string formats { "\033[1;37;41m" };
    stringstream ssum{};
    
    cout << setw(field_1) << left << "Running Sum" << setw(field_2) << right << "Enter Number" << endl;
    
    while(stringstream(number) >> temp){
        sum += temp;
        temp = 0;
        ssum.clear();
        ssum << sum;
        temp = ssum.width();
        (field_1 < temp) ? field_1 = temp : 0;
        cout << formats << setw(field_1) << right << sum << cursor::reset << setw(gap) << "";
        start:
        getline(cin, number);
        if(number.empty()){
            cout << cursor::up << cursor::rw_line << formats << setw(field_1) << right << sum << cursor::reset << setw(gap) << "";
            goto start;
        }
        cout << cursor::up << cursor::rw_line << setw(field_1) << right << sum << "\n";
    }
    cout << cursor::up << cursor::rw_line << setw(field_1) << right << sum << setw(100) << "" << endl;
    
    cout << "Total sum is: " << cursor::bold << "\033[30;47m" << sum << cursor::reset << endl;
    return 0;
}

