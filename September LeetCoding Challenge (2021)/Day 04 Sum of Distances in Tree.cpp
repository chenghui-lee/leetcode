// https://leetcode.com/problems/sum-of-distances-in-tree/discuss/130583/C%2B%2BJavaPython-Pre-order-and-Post-order-DFS-O(N)

// Credit: https://github.com/tyqi11/leetcode/blob/master/834_Sum_of_Distances_in_Tree.java
/*
1. We need to know:
1.1 For each node i, which nodes are connected to it. So we create an ArrayList tree. 
tree.get(0) is a set of all the nodes connected to node 0, and tree.get(1) is all 
nodes connected to node 1, and so on. After iterating the edges array, we can 
initialize the tree list.
1.2 How many nodes are in one subtree with root node i. So we create a count array. 
1.3 Sum of distance from node i. So we create a res array, which is the result array 
we return.
2. In postDFS, we get 
1) number of nodes of subtree root(including root), (count array)
2) the sum distances from root to all its children nodes (res array)
                       1 ---------- count: 1 + 4 + 1 = 6
                     /   \          res: 1 + 0 + 4 + 4 = 9
                    /     \
        count: 1 - 2       3 ------ count: 1 + 2 + 1 = 4
        res: 0           /   \      res: 1 + 0 + 2 + 1 = 4
                        /     \  
        count: 1 ----- 4       5 -- count: 1 + 1 = 2
        res: 0                  \   res: 1 + 0 = 1
                                 \  
                                  6 count: 1
                                    res: 0
3. In preDFS, we do res[i] = res[root] - count[i] + count.length - count[i].
After step2, the res at root 1 is correct. But at other nodes, it counts only the distance
from subtrees. Now we move the node from 1 to other nodes, for example, to 2. There is
x nodes (x is the count number at 2) which are 1 step closer to 2 than to 1, and 
N - x nodes are 1 step farther to 2 than to 1. For example, at node 5. There are 
x nodes (x is the count number at 5) which are 1 step closer to 5 than to 3, and
N - x nodes are 1 step farther to 5 than to 3. So it is:
res[i] = res[root] + (- 1 * count[i]) + (1 * count.length - count[i]).
     	                     1 ---------- count: 6
    	                   /   \          res: 9
    	                  /     \
count: 1 --------------- 2       3 ------ count: 4
res: 9 - 1 + 6 - 1 = 13         /   \      res: 9 - 4 + 6 - 4 = 7
                               /     \  
count: 1 -------------------- 4       5 -- count: 2
res: 7 - 1 + 6 - 1 = 11                \   res: 7 - 2 + 6 - 2 = 9
                                        \  
                                         6 count: 1
                                           res: 9 - 1 + 6 - 1 = 13
*/

class Solution {
public:
    vector<unordered_set<int>> tree;
    vector<int> res, count;
    
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        tree.resize(n);
        res.assign(n, 0);
        count.assign(n, 1);
        
        for(auto e : edges){
            tree[e[0]].insert(e[1]);
            tree[e[1]].insert(e[0]);     
        }
        postDFS(0, -1);
        preDFS(0, -1);
        return res;
    }
    
    void postDFS(int root, int prev){
        for(auto next : tree[root]){
            if (next != prev){
                postDFS(next, root);
                count[root] += count[next];
                res[root] += res[next] + count[next];
            }
        }
    }
    void preDFS(int root, int prev){
        for(auto next : tree[root]){
            if (next != prev){
                res[next] = res[root] - count[next] + count.size() - count[next];
                preDFS(next, root);
            }
        }
    }
};
