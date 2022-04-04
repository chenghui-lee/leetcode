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
    ListNode* swapNodes(ListNode* head, int k) {
        vector<int> num;
        ListNode* cur = head;
        while(cur){
            num.push_back(cur->val);
            cur = cur->next;
        }
        int n = num.size();
        swap(num[k-1], num[n - k]);
        ListNode* newHead = new ListNode(-1);
        cur = newHead;
        for(auto x : num){
            cur->next = new ListNode(x);
            cur = cur->next;
        }
        return newHead->next;
    }
};
