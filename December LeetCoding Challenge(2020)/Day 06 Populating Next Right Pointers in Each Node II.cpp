// Time: O(N)
// Space: max O(N)

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

// Time: O(N)
// Space: O(1)

class Solution {
public:
    Node* connect(Node* root) {
        Node* head; // heaf of the next level
        Node* prev; // prev node of the next level
        Node* cur = root;
        
        while(cur){
            while(cur){
                if (cur->left){
                    if (prev){
                        prev->next = cur->left;
                    }else{
                        head = cur->left;
                    }
                    prev = cur->left;
                }
                if (cur->right){
                    if(prev){
                        prev->next = cur->right;
                    }else{
                        head = cur->right;
                    }
                    prev = cur->right;
                }
               cur = cur->next;
            }
            cur = head;
            head = NULL;
            prev = NULL;
        }
        
        return root;
    }
};
