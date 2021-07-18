/**
https://leetcode.com/problems/reverse-nodes-in-k-group/discuss/11440/Non-recursive-Java-solution-and-idea
* Reverse a link list between begin and end exclusively
     * an example:
     * a linked list:
     * 0->1->2->3->4->5->6
     * |           |   
     * begin       end
     * after call begin = reverse(begin, end)
     * 
     * 0->3->2->1->4->5->6
     *          |  |
     *      begin end
     * @return the reversed list's 'begin' node, which is the precedence of node end
 */
class Solution {
private:
    ListNode* rev(ListNode* begin, ListNode* end){
        ListNode* cur = begin->next;
        ListNode* first = cur;
        ListNode* prev = begin;
        
        while(cur != end){
            auto next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        begin->next = prev;
        first->next = cur;
        return first;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || !head->next || k == 1) return head;
        ListNode dummy(-1);
        dummy.next = head;
        
        ListNode* begin = &dummy;
        int i = 0;
        while(head){
            i++;
            if (i % k == 0){
                begin = rev(begin, head->next);
                head = begin->next;
            }else{
                head = head->next;
            }
        }
        return dummy.next;
    }
};
