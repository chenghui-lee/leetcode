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
    ListNode* removeElements(ListNode* head, int val) {
        if (!head) return NULL;
        while (head->val == val){
            if (!head->next) return NULL;
            head = head->next;
        }
        ListNode* cur = head;
        ListNode* prev = head;
        
        while(cur != NULL){
            if(cur->val != val){
                prev = cur;
                cur = cur->next;
            }else{
                prev->next = cur->next;
                cur = cur->next;
            }
        }
        return head;
    }
};
