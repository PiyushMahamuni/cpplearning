// https://leetcode.com/problems/remove-duplicates-from-sorted-list/
#include <iostream>
#include <vector>
#include <algorithm>

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *deleteDuplicates(ListNode *head)
{
    ListNode *temp, *Head{head};
    while (head && head->next)
    {
        if (head->next->val == head->val)
        {
            temp = head->next;
            head->next = temp->next;
            delete temp;
        }
        else
            head = head->next;
    }
    return Head;
}

std::ostream &operator<<(std::ostream &os, const ListNode &list)
{
    const ListNode *ptr{&list};
    os << "[ ";
    while (ptr)
    {
        os << ptr->val << ", ";
        ptr = ptr->next;
    }
    os << " ]";
    return os;
}

int main()
{
    std::vector<int> vec;
    int val;
    while (std::cin >> val)
    {
        vec.push_back(val);
    }
    std::sort(vec.begin(), vec.end());
    ListNode head, *list{&head};
    for (const int &val : vec)
    {
        list->val = val;
        list->next = new ListNode{};
        list = list->next;
    }
    std::cout << "Before:\n"
              << head << "\nAfter:\n"
              << (*deleteDuplicates(&head)) << '\n';
    return 0;
}