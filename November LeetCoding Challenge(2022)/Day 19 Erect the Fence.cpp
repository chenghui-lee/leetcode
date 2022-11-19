class Solution {
public:
    int orientation(vector<int>& p, vector<int>& q, vector<int>& r){
        // 0 = colinear
        // positive = clockwise
        // neg = counter-clockwise
        // return (q.y-p.y) * (r.x-q.x) - (q.x-p.x) * (r.y-q.y);
        return (q[1]-p[1]) * (r[0]-q[0]) - (q[0]-p[0]) * (r[1]-q[1]);
    }
    
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        if (trees.size() <= 3) return trees;
        int n = trees.size();
        
        sort(trees.begin(), trees.end());
        
        vector<vector<int>> st; // stack
        // lower hull
        for(int i=0; i<n; i++){
            while(st.size() >= 2 && orientation(st[st.size()-2], st[st.size()-1], trees[i]) > 0){
                st.pop_back();
            }
            st.push_back(trees[i]);
        }
        
        // upper hull
        for(int i=n-1; i>=0; i--){
            while(st.size() >= 2 && orientation(st[st.size()-2], st[st.size()-1], trees[i]) > 0){
                st.pop_back();
            }
            st.push_back(trees[i]);
        }
        set<vector<int>> s(st.begin(), st.end());
        return vector<vector<int>>(s.begin(), s.end());
    }
};
