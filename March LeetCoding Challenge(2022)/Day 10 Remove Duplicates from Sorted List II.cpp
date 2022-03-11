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
        unordered_set<int> s;
        ListNode* cur = head;
        ListNode* prev = NULL;
        
        while(cur){
            if (cur->next && cur->val ==  cur->next->val || s.find(cur->val) != s.end()){
                s.insert(cur->val);
                if (prev == NULL){
                    head = cur->next;
                }else{
                    prev->next = cur->next;
                }
                cur = cur->next;
            }else{
                prev = cur;
                cur = cur->next;
            }
        }
        return head;
    }
};
