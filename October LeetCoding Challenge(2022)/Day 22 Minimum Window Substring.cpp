class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mask, windows;
        int n = s.size();

        for(char ch : t){
            mask[ch]++;
        } 
        int totalMaskUnique = mask.size();
        int totalUnique = 0, resLength = INT_MAX;
        string res = "";
        int left = 0, right = 0;
        
        while(right < n){
            char r = s[right];
            windows[r]++;
            if (windows[r] == mask[r]){
                totalUnique++;
            }

            while(totalMaskUnique == totalUnique && left <= right){
                char l = s[left];
                int size = right - left + 1;
                if (size < resLength){
                    resLength = size;
                    res = s.substr(left, size);
                }
                windows[l]--;
                if (windows[l] < mask[l]){
                    totalUnique--;
                }
                left++;
            }
            right++;
        }

        return res;
    }
};
