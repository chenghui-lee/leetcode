// https://leetcode.com/problems/pancake-sorting/discuss/214213/JavaC%2B%2BPython-Straight-Forward
class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) {
        vector<int> res;
        
        int i, index;
        for(int i=A.size(); i>0; i--){
            for(index = 0; A[index] != i; index++){} // find the next max num index
            reverse(A.begin(), A.begin() + index + 1); // move to 1st element
            res.push_back(index + 1);
            reverse(A.begin(), A.begin() + i); // move to right place (back)
            res.push_back(i);
        }
        return res;
    }
};
