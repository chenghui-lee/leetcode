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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;
        
        ListNode* dummyhead = new ListNode(1);
        ListNode* cur = head;
        ListNode* prev = dummyhead;
        
        int duplicate = -200;
        while(cur){
            if (cur->val == duplicate || (cur->next && cur->val == cur->next->val)){
                duplicate = cur->val;
                cur = cur->next;
            }else{
                prev->next = cur;
                cur = cur->next;
                prev = prev->next;
            }
            if (cur && !cur->next) prev->next = NULL;
        }
        return dummyhead->next;
        
        
    }
};
