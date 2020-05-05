class Solution {
public:
int firstUniqChar(string s) {
        queue<int> q;
        unordered_map<char,int> m;
        for (int i = 0; i<s.length(); i++){
            m[s[i]]++;
            if (m[s[i]] == 1){
              q.push(i);
            }
        }

        while (!q.empty() && m[s[q.front()]] > 1){
          q.pop();
        }
        if (q.empty()){
          return -1;
        }
        return q.front();
        
}
};

// another solution, which is much simpler
int firstUniqChar(string s) {
        int arr[26] = {0};
        for (int i = 0; i<s.length(); i++){
            arr[s[i] - 'a'] ++;
        }
        for (int i = 0; i<26; i++){
            if (arr[i] == 1)
              return i;
        }
        return -1;        
}
