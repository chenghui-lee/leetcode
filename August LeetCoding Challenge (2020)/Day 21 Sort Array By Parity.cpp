// Place holder
// Will update with more efficient way

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        vector<int> res;
        for(int& x : A){
            if(x%2) res.push_back(x);
            else res.insert(res.begin(), x);
        }
        return res;
    }
};
