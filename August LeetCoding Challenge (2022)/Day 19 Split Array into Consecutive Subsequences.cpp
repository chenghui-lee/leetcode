class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> count, end;
        // count[i] is the balance of i
        // end[i] number of subsequence ended in i
        for(int x : nums) {
            count[x]++;
        }
        /*
        Prioritise appending a number to existing subsequence,
        because starting a new one will require 2 more element
        
        */
        for(int x : nums){
            if (count[x] == 0) continue;
            count[x]--;
            if (end[x-1] > 0){ // append to prev if possible
                end[x-1]--;
                end[x]++;
            }else if (count[x+1] > 0 && count[x+2] > 0){ // otherwise create a new sequence
                count[x+1]--;
                count[x+2]--;
                end[x+2]++;
            }else{ // cant for both, return false
                return false;
            }
        }
        return true;
    }
};
