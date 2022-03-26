#include <iostream>
#include <math.h>
using namespace std;

int main(){
    unsigned int N, count{};
    cin >> N;
//    cout << "Debugging" << endl;
    unsigned int i { (N%2)?1:2 };
//    cout << "i: " << i << endl;
    unsigned int UpperLimit { static_cast<unsigned int>(sqrt(N)) };
    for(; i <= UpperLimit; i+=2){
        if(N%i == 0 && (N/i - 2 - i) % 2 == 0 ){
            count++;
            cout << "size: " << i <<  " count: " << count << endl;
            unsigned int n{ (N / i - 2 + i) / 2 };
            unsigned int temp{};
            for(unsigned int j{1}; j<=i; j++){
                cout << n*2 + 1 << ((j==i)?" = ": " + ");
                temp += n*2 + 1;
                n--;
            }
            cout << temp << endl << endl;
        }
    }
    cout << "Result :";
    cout << count << endl;
    
    return 0;
}

/*
 * Let n,m belong to Z with m > n
 * 2n+1, 2m+1 will be odd numbers with later being bigger
 * Q. what will be the sum of all the odd numbers from 2n+1 t0 2m+1
 * -> let's figure out what will be the sum of all odd numbers from 1 to 2n+1
 * that's 2*0+1 + 2*1+1 + 2*2+1 + ... + 2*n+1 ( note, 1st odd is 1=2*0+1, (n+1)th odd is 2*(n+1-1)+1=2*n+1 )
 * which is same as 2*(0+1+2+...+n) + n + 1 = 2 * ( n * [ n + 1 ] ) / 2 + n + 1
 * which is n^2 + 2n + 1
 * therefore, the sum of consecutive odd numbers from (n+1)th to (m+1)th odd number is
 * m^2-n^2 + 2 (m - n)
 * this above equation where both m,n > 0 has to equal to N, the given value
 * various combination of solution of m and n to the equation
 * m^2-n^2 + 2 (m - n) = N is the solution to the challenge
 * (m-n)(m+n) + 2 (m-n) = N
 * (m-n)(m+n+2) = N
 * therfore, m-n i.e. `i` has upper limit of sqrt(N)
 * to see if the current i is a valid solution, we need to check n>0 and n is an integer
 * */