class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n = shifts.size();
        vector<long long> sum(shifts.begin(), shifts.end());
        
        for(int i=1; i<n; i++){
            sum[i] = (sum[i] + sum[i-1]);
        }
        int shift = sum[n-1] % 26;
        s[0] = (s[0] - 'a' + shift) % 26 + 'a';
        
        for(int i=1; i<n; i++){
            shift = (sum[n-1] - sum[i-1]) % 26;
            s[i] = (s[i] - 'a' + shift) % 26 + 'a';
        }
        return s;
       
    }
};

// shorter & cleaner ver.
class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        for(int i = shifts.size() - 2; i >= 0; i --) {
            shifts[i] = (shifts[i] + shifts[i+1]) % 26;
        }
        
        for(int i = 0; i < s.size(); i ++) {
            s[i] = (s[i] - 'a' + shifts[i]) % 26 +'a';
        }
        
        return s;
    }
};
