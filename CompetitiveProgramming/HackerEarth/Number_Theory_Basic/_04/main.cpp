// find LCM for N ints for each test case
#include<iostream>

using namespace std;

int main(){
	int primes[]{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
	int powers[15]{};
	int T, N, pw, number, temp{48};
	cin >> T;
	while(T--){
		cin >> N;
		while(N--){
			cin >> number;
//            number = temp++;
//            number = temp;
			for(int i{}; i<15 && number>=primes[i]; i++){
				pw = 0;
				while(number%primes[i]==0){
					pw++;
					number /= primes[i];
				}
				if(pw>powers[i]) powers[i] = pw;
            }
        }
        unsigned long long lcm{1};
        for(int i{}; i<15; i++){
            while((powers[i])--){
            lcm *= primes[i];
            }
        }
        cout << lcm << endl;
    }
	return 0;
}