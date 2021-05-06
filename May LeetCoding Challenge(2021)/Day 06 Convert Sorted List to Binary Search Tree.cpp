class Solution {
public:
    TreeNode* help(ListNode* head, ListNode* tail){
        if (head == tail) return NULL;
        
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != tail && fast->next != tail){
            slow = slow->next;
            fast = fast->next->next;
        }
        TreeNode* root = new TreeNode(slow->val);
        root->left = help(head, slow);
        root->right = help(slow->next, tail);
        return root;
    }
  
    TreeNode* sortedListToBST(ListNode* head) {
        return help(head, NULL);
    }
};
