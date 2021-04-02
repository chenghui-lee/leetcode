// O(n) time space
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> v;
        while(head){
            v.push_back(head->val);
            head = head->next;
        }
        for(int i=0; i<v.size()/2; i++){
            if (v[i] != v[v.size() - i - 1]) return false;
        }
        return true;
    }
};

// O(n) time constant space
// Idea: Having 2 pointers, fast and slow.
// Reverse the second half, then comparing the val from head to middle and end to middle
class Solution {
public:
    ListNode* rev(ListNode* node){
        ListNode* prev = NULL;
        while(node){
            ListNode* nxt = node->next;
            node->next = prev;
            prev = node;
            node = nxt;
        }
        return prev;
    }
    
    bool isPalindrome(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        if (fast){ // odd
            slow = slow->next; // let the extra part on left side
        }
        slow = rev(slow);
        fast = head;
        while(slow){
            if (slow->val != fast->val) return false;
            slow = slow->next;
            fast = fast->next;
        }
        return true;
    }
};
