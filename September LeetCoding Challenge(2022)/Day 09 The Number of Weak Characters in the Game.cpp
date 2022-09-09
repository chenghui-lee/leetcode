// similar with https://leetcode.com/problems/russian-doll-envelopes/
class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b){
        if (a[0] == b[0]) return a[1] < b[1]; // asc
        return a[0] > b[0]; // desc by default
    }
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(), properties.end(), comp);
        
        int res = 0;
        int mx = INT_MIN;
        for(int i=0; i<properties.size(); i++){
            if (properties[i][1] < mx){
                res++;
            }
            mx = max(mx, properties[i][1]);
        }
        return res;
    }
};
