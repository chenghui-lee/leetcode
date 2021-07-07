// sort
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int> num;
        for(auto& r : matrix){
            for(auto x : r) num.push_back(x);
        }
        --k;
        sort(num.begin(), num.end());
        return num[k];
    }
};



// binary search
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int lo = matrix[0][0], hi = matrix[matrix.size() - 1][matrix[0].size() - 1] + 1; //[lo, hi)
        while(lo < hi) {
            int mid = lo + (hi - lo) / 2;
            int count = 0,  j = matrix[0].size() - 1;
            for(int i = 0; i < matrix.size(); i++) {
                while(j >= 0 && matrix[i][j] > mid) j--;
                count += (j + 1);
            }
            if(count < k) lo = mid + 1;
            else hi = mid;
        }
        return lo;
    }
};
