class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        queue<int> q;
        unordered_set<int> st;
        
        q.push(start);
        while(!q.empty()){
            int sz = q.size();
            for(int i=0; i<sz; i++){
                int idx = q.front(); q.pop();
                if (idx < 0 || idx >= n) continue;
                if (arr[idx] == 0) return true;
                if (st.count(idx)) continue;
                st.insert(idx);
                q.push(idx + arr[idx]);
                q.push(idx - arr[idx]);
            }           
        }
        return false;
    }
};
