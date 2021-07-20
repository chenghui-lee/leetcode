class Solution {
public:
    vector<int> ori;
    Solution(vector<int>& nums) {
        ori = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return ori;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> res = ori;
        for(int i=0; i<res.size(); i++){
            int idx = i + (rand() % (res.size()-i)); //  rand [i~n-1], inclusive
            swap(res[i], res[idx]);
        }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
