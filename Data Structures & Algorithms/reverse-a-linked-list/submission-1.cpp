class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        return reverseList1(head, nullptr);
    }

    ListNode* reverseList1(ListNode* curr, ListNode* newHead) {
        if (curr==nullptr || curr->next==nullptr) return curr;
        newHead=curr->next;
        newHead=reverseList1(curr->next, newHead); 
        curr->next->next=curr;
        curr->next=nullptr;
        return newHead;
    }
};










