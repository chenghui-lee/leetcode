/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if (!head) return NULL;
        Node* cur = head;
        
        while(cur != NULL){
            if (!cur->child){
                cur = cur->next;
                continue;
            }
            Node* tail = cur->child;
            while(tail->next){
                tail = tail->next;
            }
            tail->next = cur->next;
            if (cur->next) cur->next->prev = tail;
            cur->next = cur->child;
            cur->child->prev = cur;
            cur->child = NULL;
        }
        return head;
    }
};
