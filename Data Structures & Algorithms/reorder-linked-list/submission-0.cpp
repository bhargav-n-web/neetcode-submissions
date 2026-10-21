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
    ListNode* reverse(ListNode* head){
        ListNode* left=nullptr;
        ListNode* right=head;
        while(right){
            ListNode* temp=right->next;
            right->next=left;
            left=right;
            right=temp;
        }
        return left;
    }
    void reorderList(ListNode* head) {
        ListNode* fast=head;ListNode* slow=head;
        while(fast&&fast->next&&fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* l1=head;
        ListNode* l2=reverse(slow->next);
        slow->next=nullptr;
        while(l1&&l2){
           ListNode* temp1=l1->next;
           ListNode* temp2=l2->next;
           l2->next=temp1;
           l1->next=l2;
           l1=temp1;
           l2=temp2;
        }
        

    }
};
