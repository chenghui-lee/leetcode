// https://en.wikipedia.org/wiki/Reservoir_sampling
class Solution {
private:
    ListNode* head;
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        this->head = head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        ListNode* cur = head;
        int n = 1, chosen = 0;
        while(cur){
            double prob = (double) rand() / RAND_MAX; // generate double 0 - 1
            if (prob < 1.0/n){
                chosen = cur->val;
            }
            n++;
            cur = cur->next;
        }
        return chosen;
        
        
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
