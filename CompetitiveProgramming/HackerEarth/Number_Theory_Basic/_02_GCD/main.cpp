#include <iostream>

using namespace std;

// Naive Approach
// taking min of A and B and decrementing it until you find a number
// that divides both A and B
// Time complexity - O(min(A,B))
int GCD(int A, int B){
    cout << "Naive Approach:" << endl;
    int m{ (A > B) ? B : A };
    for(; m > 0; m--){
        if( A % m == 0 && B % m == 0 )
            return m;
    }
}


// Euclid's Algorithm
int _Euclid_GCD(int A, int B){ // Main Driver
    if( B == 0 )
        return A;
    return _Euclid_GCD(B, A % B);
}
int Euclid_GCD(int A, int B){  // interface
    cout << "Euclid's Algorithm:" << endl;
    return ( (A > B) ? _Euclid_GCD(A, B) : _Euclid_GCD(B, A) );
}
/* Explaination - 
 * The GCD of two numbers A, B will also divide
 * A % B, A % B is the difference between highgest multiple of B which is less than A
 * let G be the GCD of A, B then because B % G = 0, (B * n) % G = 0 where n belongs to integers
 * let n be the highest multiplier where B * n < A
 * and since we also know A % G = 0, =>
 * A - (B * n) % G = 0, that is, in another words A % B is a mulitple of G
 * if the differnece A - (B * n) is not the GCD G, that is, G * 1 != A - (B * n)
 * then we know that the difference G, has to be smaller than A - (B * n) since it is
 * A multiple of G, so now we have another number who has the property that it is a multiple
 * of G, which is A % B [ i.e. A - (B * n) ] this new number is smaller that A and B
 * So we can be clever and repeat the same operation with this new number and B, the smallest
 * two of the three known numbers who are known to be multiple of G, and then we will have the similar
 * situation with now A being A = B, B = A % B and when B will become 0, A will have the same
 * value as that of the GCD
 */
 
 
void print_result( int (*gcd)(int, int) , int A, int B){  // takes function address and it's signature as parameter
    int res = (*gcd)(A,B);
    cout << "GCD(" << A << ", " << B << ") = " << res << endl << endl;
         // You can call any function like this with pointer with proper parameters
}

void take_values(int& A, int& B){
    cout << "Enter A: ";
    cin >> A;
    cout << "Enter B: ";
    cin >> B;
    cout << "------------------------------------------------------------------" << endl << endl;
}

int main(){
    int A, B;
    
    take_values(A, B);
    
    print_result(GCD, A, B);
    print_result(Euclid_GCD, A, B);
    return 0;
}