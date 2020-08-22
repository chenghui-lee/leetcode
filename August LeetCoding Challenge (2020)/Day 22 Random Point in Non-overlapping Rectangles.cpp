class Solution {
private:
    map<int,int> m;
    vector<vector<int>> arr;
    int sum = 0;
    
public:
    Solution(vector<vector<int>>& rects) {
        arr = rects;
        int i = 0;
        for(auto x : rects){
            sum += (x[2] - x[0] + 1)*(x[3] - x[1] + 1); // (x2-x1 +1)*(y2-y1 +1)
            m[sum] = i++;
        }
    }
    
    vector<int> pick() {
        auto it = m.upper_bound(rand() % (sum+1)); // to get the rect
        vector<int> rectangle = arr[it->second]; // which rect
        int left = rectangle[0], right = rectangle[2], bot = rectangle[1], top = rectangle[3];
        return {left + rand()%(right-left+1), bot + rand()%(top-bot+1)};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */