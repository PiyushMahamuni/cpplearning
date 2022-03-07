// https://leetcode.com/problems/min-cost-climbing-stairs/
#include <iostream>
#include <vector>

int minCostClimbingStairs(std::vector<int>& cost){
    int costs[3] {cost[0], cost[1], 0};
    for(size_t ind {2}; ind < cost.size(); ind++){
        costs[ind%3] = cost[ind] + ((costs[(ind-1)%3] < costs[(ind-2)%3]) ? costs[(ind-1)%3] : costs[(ind-2)%3]);
    }
    return costs[(cost.size()-1)%3] < costs[(cost.size()-2)%3] ? costs[(cost.size()-1)%3] : costs[(cost.size()-2)%3];
}

int main(){
    std::vector<int> cost;
    int n;
    while(std::cin >> n){
        cost.push_back(n);
    }
    std::cout << minCostClimbingStairs(cost) << '\n';
    return 0;
}