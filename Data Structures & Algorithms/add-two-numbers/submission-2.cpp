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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      int carry=0;
      ListNode* dummy=new ListNode(0);
      ListNode* ptr=dummy;
      while(l1!=nullptr&&l2!=nullptr){
        long sum=l1->val+l2->val+carry;
        int val=sum%10;
        carry=sum/10;
        ptr->next=new ListNode(val);
        l1=l1->next;
        l2=l2->next;
        ptr=ptr->next;
      }
      while(l1!=nullptr){
        int val=(l1->val+carry)%10;
        carry=(l1->val+carry)/10;
        ptr->next=new ListNode(val);
        ptr=ptr->next;
        l1=l1->next;
      }
      while(l2!=nullptr){
        int val=(l2->val+carry)%10;
        carry=(l2->val+carry)/10;
        ptr->next=new ListNode(val);
        ptr=ptr->next;
        l2=l2->next;
      }
      while(carry!=0){
        ptr->next=new ListNode(carry);
        ptr=ptr->next;
        carry=carry/10;
      }
      return dummy->next;  
    }
};
