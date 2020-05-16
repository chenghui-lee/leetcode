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
        ListNode* oddNode = head;
        ListNode* evenNode = head->next;
        ListNode* evenHead = evenNode;
        while (evenNode != NULL && evenNode->next != NULL){
            oddNode->next = evenNode->next;
            oddNode = oddNode->next;
            evenNode->next = oddNode->next;
            evenNode = evenNode->next;
        }
        oddNode->next = evenHead;
        return head;
    }
};
