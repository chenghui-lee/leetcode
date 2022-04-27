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
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        UnionFind uf(n);
        
        for(auto p : pairs){
            uf.unite(p[0], p[1]);    
        }
        unordered_map<int, vector<int>> m; // parent idx, {child idx}
        for(int i=0; i<n; i++){
            m[uf.root(i)].push_back(i);
        }
        
        // sort within each group
        for(auto group : m){
            auto idx = group.second;
            string tmp = "";
            for(int i : idx){
                tmp += s[i];
            }
            sort(tmp.begin(), tmp.end());
            // replace back into ori string
            for(int i=0; i<tmp.size(); i++){
                s[idx[i]] = tmp[i];
            }
        }
        return s;
        
    }
};
