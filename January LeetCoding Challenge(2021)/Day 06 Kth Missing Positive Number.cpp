class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        unordered_set<int> s;
        for(auto x : arr) s.insert(x);
        
        for(int i=1; i<INT_MAX; i++){
            if (k == 1 && !s.count(i)) return i; 
            if (!s.count(i)) k--;
        }
        return -1;
            
    }
};

// O(N) time, O(1) space
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        for(int i=1, pos=0; i<=1000; i++){
            if (pos < arr.size() && i == arr[pos]){
                pos++;
            }else if (--k == 0) return i;
        }
        return 1000 + k;    
    }
};
