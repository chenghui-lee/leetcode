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
 
 // https://leetcode.com/problems/swap-nodes-in-pairs/discuss/344445/C%2B%2B-Recursive-Solution-faster-than-100-of-solutions
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* temp;
        temp = head->next;
        head->next = swapPairs(head->next->next);
        temp->next = head;
        return temp;
    }
};
