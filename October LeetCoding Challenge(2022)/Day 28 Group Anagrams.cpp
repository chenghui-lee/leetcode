class Solution {
public:
vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        if (strs.size() == 0)
        	return res;

        map<string, int> dictionary;
        int index = 0;
        for (string x : strs){
        	string sorted = x;
        	sort(sorted.begin(), sorted.end());
        	if (dictionary.count(sorted)){ // if the string aldy inside the map
        		res[dictionary[sorted]].push_back(x);
        	}else{
        		res.push_back({x});
        		dictionary[sorted] = index;
        		index++;
        	}
        	
        }
    return res;
    }
};
