#include <iostream>
#include <string>

using namespace std;

bool is_lovely(string const &str){
//	cout << endl
//         << "size of string: " << str.size() << endl
//         << "Iterating throught string-" << endl
//         << "----------------------------" << endl;
    
    bool lower[5]{}, upper[5]{};
    for(auto const &ch: str){
        switch(ch){
            case 'a':
//                cout << "found a, setting lower[0]=true" << endl;
                lower[0] = true;
                break;
            case 'e':
//                cout << "found e, setting lower[1]=true" << endl;
                lower[1] = true;
                break;
            case 'i':
//                cout << "found i, setting lower[2]=true" << endl;
                lower[2] = true;
                break;
            case 'o':
//                cout << "found o, setting lower[3]=true" << endl;
                lower[3] = true;
                break;
            case 'u':
//                cout << "found u, setting lower[4]=true" << endl;
                lower[4] = true;
                break;
            case 'A':
//                cout << "found A, setting upper[0]=true" << endl;
                upper[0] = true;
                break;
            case 'E':
//                cout << "found E, setting upper[1]=true" << endl;
                upper[1] = true;
                break;
            case 'I':
//                cout << "found I, setting upper[2]=true" << endl;
                upper[2] = true;
                break;
            case 'O':
//                cout << "found O, setting upper[3]=true" << endl;
                upper[3] = true;
                break;
            case 'U':
//                cout << "found U, setting upper[4]=true" << endl;
                upper[4] = true;
                break;
        }
    }
    int i,j;
    for(i=0; i<5; i++){
        if(!lower[i])break;
    }
    for(j=0; j<5; j++){
        if(!upper[i])break;
    }
    if(i==5 || j==5) return true;
    return false;
}

int main(){
	size_t T;
	cin >> T;
	for(size_t i{}; i<T; i++){
		string str;
        getchar();
		getline(cin,str);
        cout << str;
		if(is_lovely(str)) cout << "lovely string" << endl;
		else cout << "ugly string" << endl;
	}

	return 0;
}