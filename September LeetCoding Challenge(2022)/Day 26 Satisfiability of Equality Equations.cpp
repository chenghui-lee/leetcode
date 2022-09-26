
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
    
    bool equationsPossible(vector<string>& equations) {
        UnionFind uf(26);
        
        vector<string> eq, ne; // equal, not equal
        for(auto e : equations){
            if (e[1] == '=') eq.push_back(e);
            else ne.push_back(e);
        }

        for(auto e : eq){
            uf.unite(e[0] - 'a', e[3] - 'a');
        }
        
        for(auto e : ne){
            int a = uf.root(e[0] - 'a'), b = uf.root(e[3] - 'a');
            if (a == b) return false;
        }
        return true;
    }
};
