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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1){return list2;}
        if(!list2) {return list1;}
        ListNode* head=nullptr;ListNode* cur=nullptr;
        while(list1&&list2){
            ListNode* rep;
            if(list1->val<=list2->val){
                rep=list1;
                list1=list1->next;}
            else{
                rep=list2;
                list2=list2->next;}
            if(!head&&!cur){
                cur=rep;
                head=rep;}
            else{
                cur->next=rep;
                cur=cur->next;}        
        }
        ListNode* temp=head;
        if(!list1&&list2){
            cur->next=list2;}
        else if(!list2&&list1){
            cur->next=list1;}
        return head;
    }
};
