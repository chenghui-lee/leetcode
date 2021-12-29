/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return root;
        queue<Node*> q;
        q.push(root);
        int n = q.size();
        
        while(!q.empty()){
            n = q.size();
            Node* prev = NULL;
            for(int i=0; i<n; i++){
                Node* temp = q.front();
                q.pop();
                if (temp->left){
                    q.push(temp->left);
                }
                if (temp->right){
                    q.push(temp->right);
                }
                if (prev){
                    prev->next = temp;                    
                }
                prev = temp;
                
            }
        }
        return root;
    }
};

// another solution, using recursion
class Solution {
public:
    void dfs(Node* cur, Node* next){
        if (!cur) return;
        cur->next = next;
        dfs(cur->left, cur->right);
        dfs(cur->right, cur->next ? cur->next->left : NULL);
    }
    Node* connect(Node* root) {
        dfs(root, NULL);
        return root;
    }
};
