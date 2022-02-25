// https://leetcode.com/problems/add-two-numbers/ 

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
    ~ListNode(){ delete next;}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int temp{l1->val + l2->val};
    ListNode* ls{new ListNode{temp % 10}}, *res{ls};
    temp /= 10;
    while(l1->next && l2->next){
        l1 = l1->next;
        l2 = l2->next;
        temp += l1->val + l2->val;
        ls = ls->next = new ListNode{temp % 10};
        temp /= 10;
    }
    while(l1->next){
        l1 = l1->next;
        ls = ls->next = new ListNode{(temp += l1->val) % 10};
        temp /= 10;
    }
    while(l2->next){
        l2 = l2->next;
        ls = ls->next = new ListNode{(temp += l2->val) % 10};
        temp /= 10;
    }
    if(temp) ls->next = new ListNode(temp);
    return res;
}


int main(){
    int temp;
    ListNode l1, l2, *ptr {&l1};
    while(std::cin >> temp && temp >=0 && temp <= 9){
        ptr->val = temp;
        ptr->next = new ListNode();
        ptr = ptr->next;
    }
    ptr = &l2;
    while(std::cin >> temp && temp >= 0 && temp <= 9){
        ptr->val = temp;
        ptr->next = new ListNode();
        ptr = ptr->next;
    }
    ptr = addTwoNumbers(&l1, &l2);
    while(ptr){
        std::cout << ptr->val << " ";
        ptr = ptr->next;
    }
    std::cout << '\n';
    return 0;
}