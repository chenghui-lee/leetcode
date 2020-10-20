/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void dfs(Node* ori, Node* copy, vector<Node*>& visited){
        visited[ori->val] = copy;
        for(auto curr : ori->neighbors){
            if (!visited[curr->val]){
                Node* newNode = new Node(curr->val);
                (copy->neighbors).push_back(newNode);
                dfs(curr, newNode, visited);
            }else{
                (copy->neighbors).push_back(visited[curr->val]);
            }
        }
    }
    
    Node* cloneGraph(Node* node) {
        if (node == NULL) return NULL;
        vector<Node*> visited(101, NULL);
        Node* copy = new Node(node->val);
        visited[node->val] = copy;
        
        
        for(auto curr : node->neighbors){
            if (!visited[curr->val]){
                Node* newNode = new Node(curr->val);
                (copy->neighbors).push_back(newNode);
                dfs(curr, newNode, visited);
            }else{
                (copy->neighbors).push_back(visited[curr->val]);
            }
        }
        return copy;
    }
};

// Another solution, similar approach but faster
class Solution {
public:
    unordered_map<int, Node*> visited;
    Node* clone(Node* node){
        if (!node) return NULL;
        if (visited[node->val]) return visited[node->val];
        
        Node* newNode = new Node(node->val);
        visited[newNode->val] = newNode;
        
        for(auto next : node->neighbors){
            (newNode->neighbors).push_back(clone(next));
        }
        return newNode;
    }
    
    Node* cloneGraph(Node* node) {
        return clone(node);
    }
};
