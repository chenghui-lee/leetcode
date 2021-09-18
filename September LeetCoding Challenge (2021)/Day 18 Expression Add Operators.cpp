class Solution {
public:
    void helper(vector<string>& res, string path, string num, int target, long evaluated, int pos, int multed){
        if (pos == num.size()){
            if (evaluated == target) res.push_back(path);
            return;
        }
        
        for(int i=pos; i<num.size(); i++){
            if (num[pos] == '0' && i != pos) break; // cannot zero at behind if zero infront
            long cur = stol(num.substr(pos, i-pos+1));
            string curString = num.substr(pos, i-pos+1);
            if (pos == 0){ // first position special, dont have any symbol infront of him
                helper(res, path + curString, num, target, cur, i+1, cur);
            }else{
                helper(res, path + "+" + curString, num, target, evaluated + cur, i+1, cur);
                helper(res, path + "-" + curString, num, target, evaluated - cur, i+1, -cur);
                helper(res, path + "*" + curString, num, target, evaluated - multed + multed * cur, i+1, multed * cur);
            }
            
        }
    }
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        helper(res, "", num, target, 0, 0, 0);
        return res;
    }
};
