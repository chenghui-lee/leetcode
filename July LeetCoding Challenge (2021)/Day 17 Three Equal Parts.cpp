// https://leetcode.com/problems/three-equal-parts/discuss/183922/C%2B%2B-O(n)-time-O(1)-space-12-ms-with-explanation-and-comments
/*
Idea:
1. Count number of 1's, if it is 0 or divisible by 3, then maybe valid. Else invalid.
2. Find the starting point for the 3 parts, the starting points will be 1.

000110 110 00110
   ^   ^     ^
   s   m     e
   
3. Compare 3 parts

*/
class Solution {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        int countOne = 0, n = arr.size();
        for(int i=0; i<n; i++){
            if (arr[i] == 1) countOne++;
        }
        if (countOne == 0) return {0, n-1};
        else if (countOne % 3 != 0) return {-1,-1};

        int k = countOne / 3;
        int start = -1, mid = -1, end = -1;
        int cur = 0;
        
      // find starting position
        for(int i=0; i<n; i++){
            if (arr[i] == 1){
                cur++;
                if (cur == 1) start = i;
                else if (cur == k+1) mid = i;
                else if (cur == 2*k+1) end = i;
            }
            
        }
        
        while(end < n && arr[start] == arr[mid] && arr[mid] == arr[end]){
            start++, mid++, end++;
        }
        if (end == n){
            return {start-1, mid};
        }else{
            return {-1,-1};
        }
    }
};
