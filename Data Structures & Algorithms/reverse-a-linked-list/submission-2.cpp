/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head) return head;
        ListNode* parent=head->next;
        ListNode* temp;
        head->next=nullptr;
        while(parent!=nullptr){
            temp=parent->next;
            parent->next=head;
            head=parent;
            parent=temp;
        }
        return head;
    }
};
