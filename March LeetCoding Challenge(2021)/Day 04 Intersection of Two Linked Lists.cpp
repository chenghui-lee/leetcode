class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> s;
        while(headA){
            s.insert(headA);
            headA = headA->next;
        }
        while(headB){
            if (s.count(headB)) return headB;
            headB = headB->next;
        }
        return NULL;
    }

  
  // O(1) space https://leetcode.com/problems/intersection-of-two-linked-lists/discuss/49785/Java-solution-without-knowing-the-difference-in-len!
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
