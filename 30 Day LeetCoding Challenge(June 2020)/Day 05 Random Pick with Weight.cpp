// This question is confusing and instructions given are not clear
// Given an array of weight, w
// The higher the value of w[i], the higher possibilites that the number is selected, we need to return the selected index
// For example, [1,3] , the chances of getting index 0 is (1+3)/4 = 25%, while index 1 is 75%.

class Solution {
public:
    vector<int> v;
    int sum =0;
    Solution(vector<int>& w) {
        for (int x : w){
            sum += x;
            v.push_back(sum);
        }
        
    }
    
    int pickIndex() {
        int ran = rand()%sum;
        auto it=upper_bound(v.begin(), v.end(), ran) - v.begin();
        return it;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
