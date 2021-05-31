class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        vector<vector<string>> res;
        
        string cur = "";
        for(auto& ch : searchWord){
            cur += ch;
            vector<string> temp;
            auto it = lower_bound(begin(products), end(products), cur);
            for(int i=0; i<3 && it != products.end(); i++, it++){
                string& s = *it;
                if (s.find(cur)) break; // string s doesn't contain cur (find return the index)
                temp.push_back(*it);
            }
            res.push_back(temp);
        }
        
        return res;
    }
};
