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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = 0;
        ListNode* cur = head;
        while(cur){
            cur = cur->next;
            n++;
        }
        vector<ListNode*> res(k);
        cur = head;
        ListNode* prev;
        for(int i=0; i<k && cur != NULL; i++){
            res[i] = cur;
            int target = n/k;
            if (i < n%k) target++;
            for(int j=0; j<target; j++){
                prev = cur;
                cur = cur->next;
            }
            prev->next = NULL;
        }
        
        
        
        return res;
    }
};
