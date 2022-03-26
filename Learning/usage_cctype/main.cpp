#include <iostream>
#include <cctype>  // contains functions for c type characters
#include <stdlib.h>
using namespace std;

int main(){
    char c;
    while(true){
        cout << "Enter a character: ";
        c = getchar();
        if(isalpha(c)) cout << c << " is a alphabet" << endl;
        if(isdigit(c)) cout << c << " is a digit" << endl;
        if(isalnum(c)) cout << c << " is a alphabet or digit" << endl;
        if(islower(c)) cout << c << " is a lower alphabet."
                            << " converting to upper: " << (char)toupper(c) << endl;
        if(isupper(c)) cout << c << " is an upper alphabet."
                            << " converting to lower: " << (char)tolower(c) << endl;        
        if(ispunct(c)) cout << c << " is a punctuation character" << endl;
        if(isspace(c)) cout << c << " is a whitespace character" << endl;
        if(isprint(c)) cout << c << " is a pritnable character" << endl;
        
        cout << "Want to check another character ? (y/n): ";
        cin >> c;
        system("clear");
        if(c == 'n' || c== 'N')
            break;
        getchar();  // catch any unwanted char from buffer.
    }
    
    return 0;
}