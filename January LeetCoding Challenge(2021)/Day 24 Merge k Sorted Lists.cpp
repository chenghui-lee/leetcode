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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return NULL;
        priority_queue<int> pq;
        for(auto l : lists){
            while(l){
                pq.push(-l->val);
                l = l->next;
            }
        }
        if (pq.empty()) return NULL;
        ListNode* res = new ListNode(-pq.top());
        ListNode* head = res;
        pq.pop();
        while(!pq.empty()){
            res->next = new ListNode(-pq.top());
            pq.pop();
            res = res->next;
        }
        return head;
    }
};
