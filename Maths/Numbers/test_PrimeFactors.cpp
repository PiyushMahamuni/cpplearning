#include <iostream>
#include "PrimeFactors.h"

using namespace std;

void test1(); // testing constructor, int arg constructor and no arg constructor, copy constructor and move constructor
void test2(); // testing PrimeFactors::add_factors_of(int32_t) and PrimeFactors::add_factors_of(const PrimeFactors&)
void test3(); // testing Primefactors::sub_factors_of(int32_t) and PrimeFactors::sub_factors_of(const PrimeFactors&)
void test4(); // copy assignement and move assignement
void test5(); // testing PrimeFactors::add_factors(int32_t), PrimeFactors::add_factors(const PrimeFactors&) with 
// set of factors having -ve powers 
void test6(); // set addition, subtraction
void test7(); // set union, intersection

int main(){
    cout << "Testing PrimeFactors.h" << endl;
//    test1();
//    test2();
//    test3();
//    test4();
//    test5();
//    test6();
    test7();
    return 0;
}

void test1(){
    cout << "Test1 ------------------------------------------------------------------------\n\n";
    
    cout << "Testing int arg, no arg constructor and operator<<(std::ostream&, const PrimeFactors&)" << endl;
    PrimeFactors a(2), b(3), c(6), d(7), e(11), f(24), g(1), h, i(0); // h and g should be identical empty sets
    cout << a << "\n"
         << b << "\n"
         << c << "\n"
         << d << "\n"
         << e << "\n"
         << f << "\n"
         << g << "\n"
         << h << "\n"
         << i << "\n";
    // TEST OK, WORKS FINE
    cout << "Test Successful!\n" << endl;
    
    cout << "Testing copy constructor, move constructor\n";
    PrimeFactors A(a), B(b), C{ PrimeFactors(6) }, D{g}, E{i}, F{ PrimeFactors(1) }, G{ PrimeFactors(0) };
    cout << A << "\n"
         << B << "\n"
         << C << "\n"
         << D << "\n"
         << E << "\n"
         << F << "\n"
         << G << "\n";
    cout << "Test Successful\n" << endl;
    
    cout << "------------------------------------------------------------------------ Test1\n";
}


void test2(){
    cout << "Test2 ------------------------------------------------------------------------\n\n"; 
    PrimeFactors a(2), b(3), c(6), one;
    cout << "Testing PrimeFactors::add_factors_of(int32_t)" << endl;
    b.add_factors_of(6); // b should now have factors of 6*3 = 18, {2^1, 3^2}
    cout << b << "\n";
    b.add_factors_of(1); // b should remain same, addition of empty set
    cout << b << "\n";
    b.add_factors_of(0); // b should be now undefined
    cout << b << "\n";
    // TEST OK, WORKS FINE
    cout << "Test successful!\n" << endl;
    
    
    cout << "Testing PrimeFactors::add_factors_of(const PrimeFactors&)\n";
    a.add_factors_of(c); // a should now have factors of 2*6 = 12, { 2^2, 3^1 }
    cout << a << "\n";
    a.add_factors_of(one); // a should now have factors of 12*1 = 12, {2^2, 3^1 } i.e. remain as it is
    cout << a << "\n";
    a.add_factors_of(b); // a now should have factors of 12*0 = 0, { undefined }
    cout << a << "\n";
    // TEST OK, WORKS FINE
    cout << "Test Successful!\n" << endl;
    cout << "------------------------------------------------------------------------ Test2\n\n";
}


void test3(){
    cout << "Test3 ------------------------------------------------------------------------\n\n"; 
    PrimeFactors c(6);
    cout << "Testing PrimeFactors::sub_factors_of(int32_t)" << endl;
    c.sub_factors_of(2); // c should now have factors of 6/2 = 3, { 3^1 }
    cout << c << "\n";
    c.sub_factors_of(6); // c should now have factors of 3/6 = 1/2, { 2^-1 }
    cout << c << "\n";
    c.sub_factors_of(1); // c should reamin same
    cout << c << "\n";
    c.sub_factors_of(0); // c should be undefined now
    cout << c << "\n";
    // TEST OK, WORKS FINE
    cout << "Test successful!\n" << endl;
    
    cout << "Testing PrimeFactors::sub_factors_of(const PrimeFactors&)" << endl;
    PrimeFactors A(2), B(3), C(6), one, zero(0);
    C.sub_factors_of(A); // C should now have factors of 6/2 = 3, { 3^1 }
    cout << C << "\n";
    C.sub_factors_of(PrimeFactors(6)); // C should now have factors of 3/6 = 1/2, { 2^-1 }
    cout << C << "\n";
    C.sub_factors_of(one); // C should remain same
    cout << C << "\n";
    C.sub_factors_of(zero); // C should now be undefined
    cout << C << "\n";
    
    cout << "------------------------------------------------------------------------ Test3\n\n";
}


void test4(){
    cout << "Test4 ------------------------------------------------------------------------\n\n";
    PrimeFactors a{0}; // initially undefined set
    cout << a << "\n"; // { undefined }
    a = PrimeFactors{1}; // a should have empty set
    cout << a << "\n"; // { }
    PrimeFactors b{2};
    cout << b << "\n"; // { 2^1 }
    b = a; // b should now have empty set
    cout << b << "\n"; // { }
    a = PrimeFactors{3};
    cout << a << "\n"; // { 3^1 }
    b = a;
    cout << b << "\n"; // { 3^1 }
    cout << "------------------------------------------------------------------------ Test4\n\n";
}


void test5(){
    cout << "Test5 ------------------------------------------------------------------------\n\n";
    
    cout << "Testing PrimeFactors::add_factors_of with sets having -ve powers of prime factors\n";
    PrimeFactors a(5), b(6), c(3);
    cout << a << "\n"; // { 5^1 }
    a.sub_factors_of(3);
    cout << a << "\n"; // { 3^-1, 5^1 }
    a.add_factors_of(b); 
    cout << a << "\n"; // { 2^1, 5^1 }
    a.sub_factors_of(b);
    cout << a << "\n"; // { 3^-1, 5^1 }
    a.add_factors_of(6);
    cout << a << "\n"; // { 2^1, 5^1 }
    
    cout << "------------------------------------------------------------------------ Test5\n\n";
}

void test6(){
    cout << "Test6 ------------------------------------------------------------------------\n\n";
    cout << "Testing PrimeFactors::operator+(const PrimeFactors&)const; and\n"
         << "PrimeFactors::operator-(const PrimeFactors&)const;\n";
         
    cout << PrimeFactors{2} + PrimeFactors{3} + PrimeFactors{1} - PrimeFactors{7} << endl;
    
    PrimeFactors a, b{6}, c{12};
    cout << "Testing PrimeFactors::operator+=(const PrimeFactors&) and\n"
         << "Testing PrimeFactors::operator-=(const PrimeFactors&)" << endl;
    
    a += b;
    b -= c;
    cout << a << "\n" // {2^1, 3^1}
         << b << "\n"; // {2^-1}
    
    cout << "------------------------------------------------------------------------ Test6\n\n";
}

void test7(){
    cout << "Test7 ------------------------------------------------------------------------\n\n";
    
    PrimeFactors a{2}, b{3}, c{6}, e{7}, one, zero{0};
    
    cout << "Testing PrimeFactors::U(PrimeFactors& rhs)\n"
         << a.U(b) << "\n" // { 2^1, 3^1 }
         << c.U(a) << "\n" // { 2^1, 3^1 }
         << e.U(c) << "\n"; // {2^1, 3^1, 7^1 }
    e.sub_factors_of(11);
    cout << e.U(c) << "\n" // { 2^1, 3^1, 7^1}
         << a << "\n" // { 2^1 }
         << b << "\n" // { 3^1 }
         << c << "\n" // { 2^1, 3^1 }
         << e << "\n";// { 7^1 , 11^-1}
    cout << "Test Successful!\n" << endl;
    
    cout << "Testing PrimeFactors::emplace_U(const PrimeFactors&)\n";
    cout << e.emplace_U(c) << "\n"; // { 2^1, 3^1, 7^1 }
    cout << "Test Successful!\n" << endl;
    
    cout << "Testing PrimeFactors::I(PrimeFactors& rhs)\n"
         << a.I(b) << "\n"      // { }
         << c.I(b) << "\n"      // { 3^1 }
         << c.I(one) << "\n"    // { }
         << c.I(zero) << "\n";  // { 2^1, 3^1 }
    cout << "Test Successful!\n" << endl;
    cout << "------------------------------------------------------------------------ Test7\n\n";
}