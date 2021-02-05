class Solution {
public:
    string simplifyPath(string path) {
        vector<string> dir;
        string res = "", cur;
        stringstream ss(path);
        
        while(getline(ss, cur, '/')){
            if (cur == "" || cur == ".") continue;
            if (cur != "..") dir.push_back(cur);
            else if (!dir.empty()) dir.pop_back();
        }
        
        for(auto& x : dir){
            res += "/" + x;
        }
        return (res=="")?"/":res;
    }
};
