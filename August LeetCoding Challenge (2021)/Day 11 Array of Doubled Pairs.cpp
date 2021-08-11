// need to check from smallest number first, check for x2 only.
class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        multiset<int> s;
        
        sort(arr.begin(), arr.end(), [](const int a, const int b){ 
            return abs(a) < abs(b);
        });  
        
        for(auto x : arr){
            if (x % 2 == 0 && s.find(x/2) != s.end()){
                s.erase(s.find(x/2));
            }else{
                s.insert(x);
            }
        }
        return s.empty();
    }
};

// if not, will wrong
class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        multiset<int> s;
        
        for(int i=0; i<arr.size(); i++){
            if (s.find(arr[i] * 2) != s.end()){
                s.erase(s.find(arr[i] * 2));
            }else if (arr[i] % 2 == 0 && s.find(arr[i] / 2) != s.end()){
                s.erase(s.find(arr[i] / 2));
            }else{
                s.insert(arr[i]);
            }
            
        }
        return s.empty();
    }
};
