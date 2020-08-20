// https://leetcode.com/problems/reorder-list/discuss/45003/A-concise-O(n)-time-O(1)-in-place-solution
class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head || !head->next){
            return;
        }
        
        ListNode* slow = head;
        ListNode* fast = head->next;
        
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* head2 = slow->next;
        slow->next = NULL;
        
        fast = head2->next;
        head2->next = NULL; // last element
        while(fast){
            slow = fast->next;
            fast->next = head2;
            head2 = fast;
            fast = slow;
        }
        
        for(slow = head, fast = head2; slow != NULL;){
            auto t = slow->next;
            slow = slow->next = fast;
            fast = t;
        }
        
    }
};
