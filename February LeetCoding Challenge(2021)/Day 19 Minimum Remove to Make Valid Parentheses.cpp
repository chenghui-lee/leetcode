class Solution {
public:
    string minRemoveToMakeValid(string s) {
        set<int> steps;
        set<int> toberemoved;
        for(int i=0; i<s.size(); i++){
            auto ch = s[i];
            if (ch == '(') steps.insert(i);
            else if (ch == ')'){
                if (steps.size()) steps.erase(*steps.rbegin());
                else toberemoved.insert(i);
            }
        }
        string res = "";
        for(int i=0; i<s.size(); i++){
            if (steps.count(i) !=0 || toberemoved.count(i) !=0) continue;
            res += s[i];
        }
        return res;
    }
};

// Simpler solution
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int close = count(s.begin(), s.end(), ')');
        int open = 0;
        
        string res;
        for(auto ch : s){
            if (ch == '('){
                if(open == close) continue;
                open++;
            }else if (ch == ')'){
                close--;
                if (open == 0) continue;
                open--;
            }
            res += ch;
        }        
        
        return res;
    }
};
