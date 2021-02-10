/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return head;
        map<Node*, Node*> m;
        
        Node* cur = head;
        Node* newCur = new Node(head->val);
        Node* res = newCur;
        while(cur){
            if (cur->next){
                newCur->next = new Node(cur->next->val);
            }
            m[cur] = newCur;
            cur = cur->next;
            newCur = newCur->next;
        }
        while(head){
            m[head]->random = m[head->random];
            head = head->next;
        }
        return res;
    }
};
