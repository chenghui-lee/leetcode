class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m1, m2;
        
        for(auto x : nums1) m1[x]++;
        for(auto x : nums2) m2[x]++;
        
        vector<int> res;
        for(auto p : m1){
            if (m2.find(p.first) != m2.end()){
                for(int i =0; i<min(m1[p.first], m2[p.first]); i++){
                    res.push_back(p.first);
                }
            }
        }
        return res;
    }
};
