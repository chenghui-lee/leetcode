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
    /*
    Assuming length of A = a + c,
    Assuming length of B = b + c,
    
    During the second iteration,
    A will go through a + c + b,
    B will go through b + c + a
    
    So eventually they will meet each other.
    
    If they have no intersection (c = 0), then both of them will reach null
    A = a + b
    B = b + a
    
    
    */
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return NULL;
        
        ListNode* curA = headA;
        ListNode* curB = headB;
        
        while(curA != curB){
            if (curA) curA = curA->next;
            else curA = headB;
            
            if (curB) curB = curB->next;
            else curB = headA;
        }
        return curA;
    }
};
