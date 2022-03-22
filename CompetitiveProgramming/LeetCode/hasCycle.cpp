// https://leetcode.com/problems/linked-list-cycle

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

bool hasCycle(ListNode *head) {
    if(!head) return false;
    
    ListNode* slow{head};
    while(head && head->next){
        head = head->next->next;
        slow = slow->next;
        
        if(slow == head) return true;
    }
    return false;
}

/* EXPLAINATION
1. No loop, in that case, the fast pointer i.e. head and the slow pointer do not have
any chance of being the same at any point before the while loop terminates.
2. Suppose that there does exists a loop in the linked list, the head pointer and slow
pointer will eventually enter in it. Now they're constantly circumnavigating the same
track, figuratively speaking. They will continue to loop through the same set of pointer
values. The interseting thing to notice here is to keep track of relative distance between
the two pointers. The fast pointer is traversing the nodes at twice the rate of slow
pointer. To keep track of relative distance, you can keep the slow pointer fixed in place
and let fast pointer approach to it with 1 node per iteration. So, there will definitely
be a time, if there exists a loop that the slow pointer and faster head pointer will have
the equality check passed
*/