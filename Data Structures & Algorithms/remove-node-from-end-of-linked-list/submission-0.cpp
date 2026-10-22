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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       ListNode dummy(0, head);
        ListNode* left = &dummy;
        ListNode* right = &dummy;
        
        // Move right pointer n + 1 steps ahead so left lands exactly before the target
        for (int i = 0; i <= n; i++) {
            right = right->next;
        }
        
        // Move both pointers until right reaches the end
        while (right != nullptr) {
            left = left->next;
            right = right->next;
        }
        
        // Delete the N-th node from the end
        ListNode* nodeToDelete = left->next;
        left->next = left->next->next;
        delete nodeToDelete; // Optional but good practice for memory management
        
        return dummy.next;  
    }
};
