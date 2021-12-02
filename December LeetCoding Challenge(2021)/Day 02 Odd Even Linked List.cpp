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
    ListNode* oddEvenList(ListNode* head) {
        if (!head) return NULL;
        ListNode* oddnode = head;
        ListNode* evennode = head->next;
        ListNode* evenhead = head->next;
        while(evennode && evennode->next){
            oddnode->next = evennode->next;
            oddnode = oddnode->next;
            evennode->next = oddnode->next;
            evennode = evennode->next;
        }
        oddnode->next = evenhead;
        return head;
    }
};
