class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> m;
        for (int x : nums){
            m[x]++;
        }
        for (auto it=m.begin(); it!=m.end(); it++){
            if (it->second > nums.size()/2){
                return it->first;
            }
        }
        return NULL;
    }
};

// another solution
int majorityElement(vector<int>& nums) {
        int ans = 0, count = 0;
        for(auto& num : nums){
            if(count == 0){
                ans = num;
                count = 1;
            }else{
                count += (ans == num) ? 1 : -1;
            }
        }
        return ans;
    }
