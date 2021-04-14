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
    ListNode* partition(ListNode* head, int x) {
        ListNode* head1 = new ListNode(-1);
        ListNode* head2 = new ListNode(-1);
        ListNode* cur = head;
        ListNode* cur1 = head1;
        ListNode* cur2 = head2;
        while(cur != NULL){
            if (cur->val < x){
                cur1->next = new ListNode(cur->val);
                cur1 = cur1->next;
            }else{
                cur2->next = new ListNode(cur->val);
                cur2 = cur2->next;
            }
            cur = cur->next;
        }
        cur1->next = head2->next;
        return head1->next;
    }
};
