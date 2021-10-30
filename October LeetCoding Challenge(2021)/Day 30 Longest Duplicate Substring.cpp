/*
Idea: Use binary search to find the length, then for each length, use rabin karp to match
*/
class Solution {
public:
    string longestDupSubstring(string s) {
        int n = s.size();
        power = vector<long long>(n, 1);
        for(int i=1; i<n; i++){
            power[i] = power[i-1] * 26 % MOD;
        }
        int low = 0, high = n;
        while(low <= high){
            int mid = low + (high - low) / 2;
            string temp = roll(mid, s);
            if (temp.size() == 0) high = mid -1;
            else{
                if (temp.size() > res.size()){
                    res = temp;
                }
                low = mid + 1;
            }
        }
        return res;
    }

private:
    int MOD = 19260817;
    string res;
    vector<long long> power;
    
    string roll(int len, string& s){
        if (len == 0) return "";
        unordered_map<long long, vector<int>> m; // hash, list of starting index
        long long cur = 0;
        
        for(int i=0; i<len; i++){
            cur = ((cur * 26) % MOD + (s[i] - 'a')) % MOD;
        }
        m[cur].push_back(0);
        for(int i=len; i<s.size(); i++){
            cur = ((cur - (long long) power[len - 1] * (s[i - len] - 'a')) % MOD + MOD) % MOD;
            /*
            Take care of the hashing function, the following is wrong
            cur = (cur - ((long long) power[len - 1] * (s[i - len] - 'a')) + MOD) % MOD;
            */
            cur = ((cur * 26) % MOD + (s[i] - 'a')) % MOD;
            
            for(int startIdx : m[cur]){
                if (s.substr(startIdx, len) == s.substr(i - len + 1, len)){
                    return s.substr(startIdx, len);
                }
            }
            m[cur].push_back(i - len + 1);
        }
        return "";
    }
};
