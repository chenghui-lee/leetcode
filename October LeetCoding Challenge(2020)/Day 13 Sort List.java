/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode sortList(ListNode head) {
        if (head == null || head.next == null) return head;
        ListNode mid = getMid(head);
        ListNode left = sortList(head);
        ListNode right = sortList(mid);
        return merge(left, right);
    }
    public ListNode getMid(ListNode head){
        ListNode prev = null;
        while(head != null && head.next != null){
            prev = (prev == null)? head:prev.next;
            head = head.next.next;
        }
        ListNode mid = prev.next;
        prev.next = null;
        return mid;
    }
    public ListNode merge(ListNode a, ListNode b){
        ListNode head = new ListNode();
        ListNode cur = head;
        
        while(a != null && b != null){
            if (a.val < b.val){
                cur.next = a;
                a = a.next;
                cur = cur.next;
            }else{
                cur.next = b;
                b = b.next;
                cur = cur.next;
            }
        }
        cur.next = (a==null)?b:a;
        return head.next;
    }
}
