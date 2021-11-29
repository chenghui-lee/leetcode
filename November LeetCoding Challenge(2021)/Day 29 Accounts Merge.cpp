// union find
class Solution {
public:
    int find(vector<int>& uf, int idx){
        while(uf[idx] != idx) idx = uf[idx];
        return idx;
    }
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        unordered_map<string, int> m; // email, owner id
        vector<int> uf(n, 0); // union find array, storing parent id for each of the person
        unordered_map<int, vector<string>> res_map; // owner id, list of emails
        
        for(int i=0; i<n; i++){
            uf[i] = i;
            for(int j=1; j<accounts[i].size(); j++){
                if (m.find(accounts[i][j]) != m.end()){
                    int root1 = find(uf, i);
                    int root2 = find(uf, m[accounts[i][j]]);
                    uf[root1] = root2;
                }else{
                    m[accounts[i][j]] = i;
                }
            }
        }
        // for each email
        for(auto it : m){
            int owner = find(uf, it.second);
            res_map[owner].push_back(it.first);
        }
        vector<vector<string>> res;
        for(auto it : res_map){
            vector<string> ownedEmails = it.second;
            sort(ownedEmails.begin(), ownedEmails.end());
            ownedEmails.insert(ownedEmails.begin(), accounts[it.first][0]); // insert owner name
            res.push_back(ownedEmails);
        }
        return res;
    }
};
