// DSU
// Union find
class Solution {
public:
    struct UnionFind {
	vector<int> parent;
	
	UnionFind(int N){
		parent = vector<int> (N, -1);
	}
	int root(int x){
		if (parent[x] < 0) return x;
		return parent[x] = root(parent[x]);
	}
	bool unite(int x, int y){
		int parentA = root(x);
		int parentB = root(y);
		if (parentA == parentB) return false;
		if (parent[parentA] > parent[parentB]) swap(parentA, parentB);
		
		parent[parentA] += parent[parentB];
		parent[parentB] = parentA;
		return true;
		
	}
	int size(int x){
		return -parent[root(x)];
	}
    };
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int res = -1, n = edges.size();
        
        UnionFind uf(n);
        for(int i=0; i<edges.size(); i++){
            if (!uf.unite(edges[i][0]-1, edges[i][1]-1)) res = i;
        }
        
        return edges[res];
    }
};
