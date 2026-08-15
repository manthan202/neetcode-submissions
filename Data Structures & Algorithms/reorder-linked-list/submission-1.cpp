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

class Solution { //Not optimal
public:
    void reorderList(ListNode* head) {
        vector<ListNode*> linkedList;
        while(head!=nullptr){
            linkedList.push_back(head);
            head=head->next;
        }

        int right=linkedList.size()-1, left=0;
        while(left<right){
            linkedList[right]->next=linkedList[left]->next;
            linkedList[left]->next=linkedList[right];
            left++;
            right--;
        }
        linkedList[left]->next=nullptr;
    
    }
};
