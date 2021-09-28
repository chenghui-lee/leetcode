// 232ms, 70.99%
// 66.2MB, 18.7%
/*
https://leetcode.com/problems/longest-subsequence-repeated-k-times/discuss/1471911/Java-BFS-O(n-*-2-8)-with-detailed-explanation
basically use bfs to generate all possible subsequence, start from the shortest to longest one
in bfs, will filter out those invalid one
*/
class Solution {
public:
    // check if the cur substring repeated k times in s
    bool isSub(string s, string cur, int k){
        int j = 0, count = 0;
        for(int i=0; i<s.size(); i++){
            if (s[i] == cur[j]){
                j++;
                if (j == cur.size()){
                    count++;
                    j = 0;
                }
                if (count == k) return true;
            }
        }
        return false;
    }
    
    string longestSubsequenceRepeatedK(string s, int k) {
        queue<string> q;
        map<char, int> count;
        for(int i=0; i<s.size(); i++){
            count[s[i]]++;
        }
        // optimization, we only use those char with frequency >= k
        vector<char> possibleChar;
        for(auto p : count){
            if (p.second >= k) possibleChar.push_back(p.first);
        }
        q.push("");
        string res;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                string cur = q.front(); q.pop();
                for(char ch : possibleChar){
                    string next = cur + ch;
                    if (isSub(s, next, k)){
                        res = next;
                        q.push(next);
                    }
                }
            }
        }
        return res;
    }
};
