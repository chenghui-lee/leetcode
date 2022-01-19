/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next || !head->next->next) return NULL;
        
        ListNode* fast = head->next->next;
        ListNode* slow = head->next;
        while(fast != slow){
            if (!slow || !fast || !fast->next) return NULL;
            fast = fast->next->next;
            slow = slow->next;
        }
        slow = head;
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};
