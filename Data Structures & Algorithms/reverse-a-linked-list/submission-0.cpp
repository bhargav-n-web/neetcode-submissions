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
        if(!head){
            return head;
        }
        ListNode* left=head;
        ListNode* right=left->next;
        while(right){
            ListNode* temp=right->next;
            if(left==head){
                left->next=NULL;
            }
            right->next=left;
            left=right;
            if(!temp){
                return right;
            }
            right=temp;
        }
        return head;
    }
};
