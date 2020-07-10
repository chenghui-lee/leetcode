/*
1. If the current node has no child, then move on to next node

2. Go to tail of the child and link to p.next

3. Link the original p.next prev to the tail

4. Change p.next to p.child
p.child.prev = p
p.child = null

*/

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
        if (!head) return head;
        Node* cur = head;
        while(cur != NULL){
            if(!cur->child){
                cur = cur->next;
                continue;
            }
            Node* tail = cur->child;
            while(tail->next) tail = tail->next;
            tail->next = cur->next;
            if (cur->next) cur->next->prev = tail;
            cur->next = cur->child;
            cur->child->prev = cur;
            cur->child = NULL;
        }
        return head;
    }
};
