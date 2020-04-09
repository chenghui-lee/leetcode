class Solution {
public:
bool backspaceCompare(string S, string T) {
	if (S==T)
		return true;
	int index1 = 0, index2 = 0;
	for (char x : S){
		if (x != '#'){
			S[index1++] = x;
		}else{
			index1 = max(index1 - 1 , 0);
		}
	}
	for (char x : T){
		if (x != '#'){
			T[index2++] = x;
		}else{
			index2 = max(index2 - 1 , 0);
		}
	}
	return S.substr(0, index1) == T.substr(0, index2);
	
	
}
};
