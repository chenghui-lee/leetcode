class Solution {
public:
    string simplifyPath(string path) {
        vector<string> dir;
        stringstream ss(path);
        
        string cur, res = "";
        /* 
        getline(istream& is, string& str, char delim);
        getline() function extracts characters from the input stream and appends it to the string object until the delimiting character is encountered. 
        */
        while(getline(ss, cur, '/')){
            if (cur == "" || cur == ".") continue;
            if (cur != "..") dir.push_back(cur);
            else if (!dir.empty()) dir.pop_back();
        }
        for(string s : dir){
            res += "/" + s;
        }
        return res == "" ? "/" : res;
    }
};
