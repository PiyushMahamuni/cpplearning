// https://leetcode.com/problems/climbing-stairs
#include<iostream>
#include<bitset>
// BEING TOO SMART CAN MAKE YOU SHOOT YOURSELF IN THE FOOT
// I FAILED TO REALIZE THAT THIS QUESTION ASKS FOR ith FIBONACCI ELEMENT IN A OBSCURE WAY
// AND EFFECTIVELY WROTE DOWN AN EVEN MORE OBSCURE SOLUTION THAT RETURNS (i-1)th FIBONACCI
// ELEMENT.

int climbStairs(int& steps){
    if(steps <=2) return steps;
    const int x0{steps / 2}, y0{steps % 2};
    int ans{1}, a, b, c, i;
    long int temp {1}; 
    std::bitset<46> flaga, flagb;
    for(int n{y0}; n < x0; n++){
        b = x0 - n;
        c = y0 + 2 * n;
        a = b + c;
        temp = 1;
        for(i = 2; i<= a; i++){
            flaga[i] = true;
        }
        for(i = 2; i<= b; i++){
            bool flag{true};
            for(int j{1}; j*i <= a; j++){
                if(flaga[j * i]){
                    flaga[j * i] = flag = false;
                    temp *= j;
                    break;
                }
            }
            if(flag){
                if((temp % i)){
                    flagb[i] = true;
                }
                else{
                    temp /= i;
                }
            }
        }
        for(i = 2; i<= c; i++){
            bool flag{true};
            for(int j{1}; j*i <= a; j++){
                if(flaga[j * i]){
                    flaga[j * i] = flag = false;
                    temp *= j;
                    break;
                }
            }
            if(flag){
                if((temp % i)){
                    flagb[i] = true;
                }
                else{
                    temp /= i;
                }
            }
        }
        for(i = 2; flaga.any(); i++){
            if(flaga[i]){
                temp *= i;
                flaga[i] = false;
            }
        }
        for(i = 2; flagb.any(); i++){
            if(flagb[i]){
                temp /= i;
                flagb[i] = false;
            }
        }
        ans += static_cast<int>(temp);
    }
    return y0? ans + x0 + 1 : ans;
}

int main(){
    int steps;
    while(std::cin >> steps){
        std::cout << climbStairs(steps) << '\n';
    }
    return 0;
}