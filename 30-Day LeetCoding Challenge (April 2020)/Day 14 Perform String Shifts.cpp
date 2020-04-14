class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
	int sum = 0;
	string res = "";
	for (int i = 0; i<shift.size(); i++){
		if (shift[i][0] == 0){ // left
			sum -= shift[i][1];
		}else if (shift[i][0] == 1){ // right
			sum += shift[i][1];
		}
	}
	if (sum > 0 && sum < s.length()){ // if right
		res.append(s.substr(s.length()-sum, s.length()));
		res.append(s.substr(0,s.length()-sum));

	}else if (sum < 0 && abs(sum) < s.length()){ // if left
		sum = - sum;
		res.append(s.substr(sum,s.length()));
		res.append(s.substr(0,sum));

	}else if (sum > 0 && sum >= s.length()){ // if right, larger than size
		sum %= s.length();
		res.append(s.substr(s.length()-sum, s.length()));
		res.append(s.substr(0,s.length()-sum));

	}else if (sum < 0 && abs(sum) >= s.length()){ // if left, larger than size
		sum = - sum;
		sum %= s.length();
		res.append(s.substr(sum,s.length()));
		res.append(s.substr(0,sum));
	}
	return res;

}
};

// this solution is step by step, using substring to complete the rotation
// we can also use the build in fucntion rotate() to complete the rotation
// usage : 
// Rotate left by 5 times : rotate(s.begin(), s.begin()+5, s.end())
// Rotate right by 5 times : rotate(s.begin(), s.begin()+s.length()-5, s.end())
