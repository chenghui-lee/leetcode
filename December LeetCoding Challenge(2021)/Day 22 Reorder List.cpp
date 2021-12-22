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
    void reorderList(ListNode* head) {
        if(!head || !head->next || !head->next->next){
            return;
        }
        stack<ListNode*> s;
        int n = 0;
        ListNode* cur = head;
        while(cur){
            n++;
            s.push(cur);
            cur = cur->next;
        }
        cur = head;
        for(int i=0; i<n/2; i++){
            ListNode* temp = s.top(); s.pop();
            temp->next = cur->next; // last->next = second element
            cur->next = temp;
            cur = cur->next->next;
        }
        cur->next = NULL;
    }
};
