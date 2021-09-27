class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> s;
        
        for(string e : emails){
            auto it = e.find("@");
            string domain = e.substr(it);
            string user = "";
            for(int i=0; i<it; i++){
                if (e[i] == '+') break;
                else if (e[i] == '.') continue;
                else user += e[i];
            }
            s.insert(user+domain);
        }
        
        return s.size();
    }
};
