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

class Solution { // Optimal Solution
public:
    void reorderList(ListNode* head) {
        // we will find mid first using slow fast
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=nullptr && fast->next!=nullptr){
            fast=fast->next->next;
            slow=slow->next;
        }

        // now slow is the middle node so reverse the linked list starting from slow
        ListNode* parent=slow->next;
        slow->next=nullptr;
        ListNode* prev=nullptr;
        while(parent!=nullptr){
            ListNode* temp=parent->next;
            parent->next=prev;
            prev=parent;
            parent=temp;
        }

        slow=prev;
        // now join them alternatively 2 linked lists starting from head and slow
        while(head!=nullptr && slow!=nullptr){
            ListNode* temphead=head->next;
            ListNode* tempslow=slow->next;

            head->next=slow;
            slow->next=temphead;

            head=temphead;
            slow=tempslow;
        }

    }
};
