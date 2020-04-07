class Solution {
public:
int countElements(vector<int>& arr) {
	int result = 0;
	if (arr.size() == 1){
		return result;
	}

	map<int, int> m;
	for (int i = 0; i<arr.size(); i++){
		m[arr[i]]++;
	}

	for (auto x : m){ // for every iterator in m
		if (m.find(x.first + 1) != m.end()){ // if key+1 is inside
			result += x.second;
		}
	}

    return result;
}
};
