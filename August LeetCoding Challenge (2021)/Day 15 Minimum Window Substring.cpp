class Solution {
public:
string minWindow(string s, string t) {
        unordered_map<char,int> mask;
        unordered_map<char,int> window;

        for (char x : t){
                mask[x]++;
        }
        string ans = "";
        int totalMaskChar = mask.size();
        int uniqueMatchChar = 0;
        int left =0, right=0;
        int minLength = INT_MAX;
        while (right<s.length()){
                char r = s[right];
                window[r]++;
                if (mask.find(r) != mask.end()){ // if the char is inside the mask
                        if (mask[r] == window[r]){ // if they are same frequency
                                uniqueMatchChar++;
                        }
                }
                // if reached same number of uniqueMatchChar, we move left pointer+1, keep checking
                while(uniqueMatchChar==totalMaskChar && left <= right){
                        char l = s[left];
                        int windowSize = right-left+1; // the length of the substring that satisfy the condition
                        if (windowSize<minLength){
                                ans = s.substr(left, windowSize);
                                minLength = windowSize;
                        }
                        window[l]--;
                        // check if the left char is one of the requirements
                        if (mask.find(l) != mask.end()){
                                // if the count of left is lesser than requirements, we decrease the uniqueMatchChar value
                                if (window[l] < mask[l]){
                                        uniqueMatchChar--;
                                }
                        }
                        left++;
                }
                right++;
        }
        return ans;
}
};
