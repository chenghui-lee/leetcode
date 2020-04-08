/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
	if (head == NULL || head->next == NULL){
		return head;
	}
	ListNode* slow = head;
	ListNode* fast = head;
	
	while (fast != NULL && fast->next != NULL){
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
        
}
};

// we move the fast 2 places at a time, while slow 1 at a time
// by the time the fast reached the end, the slow should be in the middle
// solution by LIGHTNINGMCQUEEN
