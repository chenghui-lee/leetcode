/*

1. Find the number of unique characters in the string s and store the count in variable maxUnique.
2. Iterate over the string s with the value of currUnique ranging from 1 to maxUnique.
In each iteration, currUnique is the maximum number of unique characters that must be present in the sliding window.
3. If the number of unique character in the sliding window is less than or equal to currUnique, expand the window 
4. else shirnk
5. Keep track of the number of unique characters in the current sliding window having at least k frequency given by countK.
Update the result if all the characters in the window have at least k frequency.

*/

class Solution {
public:
    int longestSubstring(string s, int k) {
        
        unordered_set<char> set;
        for(auto& x : s) set.insert(x);
        int maxUnique = set.size();
        
        int res = 0;
        
        for(int i=1; i<=maxUnique; i++){
            unordered_map<char, int> m;
            int start = 0, end = 0, unique = 0, countK = 0;
            
            while(end < s.size()){
                if (unique <= i){
                    if (m[s[end]] == 0){
                        unique++;
                    }
                    m[s[end]]++;
                    if (m[s[end]] == k) countK++;
                    end++;                    
                }else{
                    if (m[s[start]] == k) countK--;
                    m[s[start]]--;
                    if (m[s[start]] == 0) unique--;
                    start++;
                }
                if (unique == i && unique == countK){
                    res = max(res, end - start);
                }
            }
        }
        return res;
    }
};
