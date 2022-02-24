// top down
class Solution {
private:
    ListNode* getMid(ListNode* head){
        /*
        if 4 elements, return the 3rd
        if 5 elements, return the 3rd also
        will break the bond on the node before mid
        */
        ListNode* slow = NULL;
        ListNode* fast = head;
        while(fast && fast->next){
            slow = (slow == NULL)? head : slow->next;
            fast = fast->next->next;
        }
        ListNode* mid = slow->next;
        slow->next = NULL;
        return mid;
    }
    
    ListNode* merge(ListNode* left, ListNode* right){
        ListNode* head = new ListNode(0);
        ListNode* cur = head;
        while(left && right){
            if (left->val < right->val){
                cur->next = left;
                left = left->next;
                cur = cur->next;
            }else{
                cur->next = right;
                right = right->next;
                cur = cur->next;
            }
        }
        cur->next = (left == NULL) ? right : left;
        return head->next;
    }
    
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* mid = getMid(head);
        ListNode* left = sortList(head);
        ListNode* right = sortList(mid);
        return merge(left, right);
    }
};
