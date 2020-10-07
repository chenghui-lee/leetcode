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
        if (!head || k==0 || !head->next) return head;
        int length = 1;
        ListNode* cur = head;
        while(cur->next){
            cur = cur->next;
            length++;
        }
        cur->next = head;
        k %= length;
        if(k) {
            for(int i=0; i<length-k; i++){
                cur = cur->next;
            } 
        }
        ListNode* newHead = cur->next;
        cur->next = NULL;
        return newHead;
        
    }
};
