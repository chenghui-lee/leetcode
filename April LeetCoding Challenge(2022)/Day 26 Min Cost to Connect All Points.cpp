// official sol
class UnionFind {
public:
    vector<int> group;
    vector<int> rank;

    UnionFind(int size) {
        group = vector<int>(size);
        rank = vector<int>(size);
        for (int i = 0; i < size; ++i) {
            group[i] = i;
        }
    }

    int find(int node) {
        if (group[node] != node) {
            group[node] = find(group[node]);
        }
        return group[node];
    }

    bool join(int node1, int node2) {
        int group1 = find(node1);
        int group2 = find(node2);
        
        // node1 and node2 already belong to same group.
        if (group1 == group2) {
            return false;
        }

        if (rank[group1] > rank[group2]) {
            group[group2] = group1;
        } else if (rank[group1] < rank[group2]) {
            group[group1] = group2;
        } else {
            group[group1] = group2;
            rank[group2] += 1;
        }

        return true;
    }
};


class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<pair<int, pair<int, int>>> allEdges;
        
        // Storing all edges of our complete graph.
        for (int currNode = 0; currNode < n; ++currNode) {
            for (int nextNode = currNode + 1; nextNode < n; ++nextNode) {
                int weight = abs(points[currNode][0] - points[nextNode][0]) + 
                             abs(points[currNode][1] - points[nextNode][1]);
                
                allEdges.push_back({ weight, { currNode, nextNode }});
            }
        }
        
        // Sort all edges in increasing order.
        sort(allEdges.begin(), allEdges.end());
        
        UnionFind uf(n);
        int mstCost = 0;
        int edgesUsed = 0;
        
        for (int i = 0; i < allEdges.size() && edgesUsed < n - 1; ++i) {
            int node1 = allEdges[i].second.first;
            int node2 = allEdges[i].second.second;
            int weight = allEdges[i].first;
            
            if (uf.join(node1, node2)) {
                mstCost += weight;
                edgesUsed++;
            }
        }
        
        return mstCost;
    }
};

// my sol, passed all test cases but too slow
struct UnionFind{
    vector<int> parent;
    
    UnionFind(int N){
        parent = vector<int>(N, -1);
    }
    int root(int x){
        if (parent[x] < 0) return x;
        return parent[x] = root(parent[x]);
    }
    bool unite(int x, int y){
        int parentA = root(x), parentB = root(y);
        if (parentA == parentB) return false;
        
        if (parent[parentA] > parent[parentB]) swap(parentA, parentB);
        parent[parentA] += parent[parentB];
        parent[parentB] = parentA;
        return true;
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        
        vector<vector<int>> q; // (weight, u, v)
        // find the distance to all the other points
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int w = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                q.push_back({w, i, j});
            }
        }
        sort(q.begin(), q.end());
        
        UnionFind uf(n);
        int cost = 0;
        int edgeUsed = 0;
        
        for(int i=0; i<q.size() && edgeUsed < n-1; i++){
            int w = q[i][0], u = q[i][1], v = q[i][2];
            if (uf.unite(u, v)){
                cost += w;
                edgeUsed++;
            }
        }
            
            
        return cost;
        
    }
};
