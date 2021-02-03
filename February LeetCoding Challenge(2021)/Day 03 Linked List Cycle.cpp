class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head) return false;
        ListNode* slow = head;
        ListNode* fast = head->next;
        
        while(slow != fast){
            if (!fast || !fast->next) return false;
            fast = fast->next->next;
            slow = slow->next;
        }
        return true;
    }
};

// another similiar solution, using while true
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head) return false;
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(true){
            if (!fast || !fast->next) return false;
            fast = fast->next->next;
            slow = slow->next;
            if (slow==fast) return true;
        }
    }
};
