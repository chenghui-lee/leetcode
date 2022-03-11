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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;
        ListNode* cur = head;
        int len = 1;
        
        // stop at last node
        while(cur->next){
            cur = cur->next;
            len++;
        }
        k %= len;
        cur->next = head; // connect the final node to head
        if (k > 0){
            for(int i=0; i<len-k; i++){
                cur = cur->next;
            }
        }
        ListNode* newhead = cur->next;
        cur->next = NULL;
        return newhead;
    }
};
