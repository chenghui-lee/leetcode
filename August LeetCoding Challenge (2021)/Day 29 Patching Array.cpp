class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        // missing = the current num that cant be covered
        // [1, missing)
        // [1,2,4,14], n = 20
        // when we reach 1, we can cover [1,2)
        // when we reach 2, we can cover [1,4)
        // when we reach 4, we can cover [1,8)
        // when we reach 14, it is too large, so we need to insert 8, so the range become [1,16)
        // then we proceed with 14 again, and we can cover [1,30). stop
        long missing = 1, i = 0, res = 0;
        while(missing <= n){
            if (i < nums.size() && nums[i] <= missing){
                missing += nums[i++];
            }else{
                res++;
                missing += missing;
            }
        }
        return res;
    }
};
