class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* start = new ListNode(-1);
        start->next = head;
        ListNode* slow = start;
        ListNode* fast = start;
        
       //Move fast in front so that the gap between slow and fast becomes n
        for(int i=1; i<=n+1; i++){
            fast = fast->next;
        }
        while(fast){
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return start->next;
    }
};
