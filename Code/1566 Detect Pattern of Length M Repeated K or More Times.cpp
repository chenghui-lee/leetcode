class Solution {
public:
    bool containsPattern(vector<int>& arr, int m, int k) {
        int n = arr.size();
        if (m > n || m*k > n) return false;
        
        int count = 0;
        for(int i=0; i+m<n; i++){
            if (arr[i] != arr[i+m]){
                count = 0;
            }else{
                count++;
                if (count == (k-1)*m) return true;
            }
        }
        return false;
    }
};
/*
m = 3   k = 3

... 1 2 3 1 2 3 1 2 3 ...
    i --- j
count = 1

... 1 2 3 1 2 3 1 2 3 ...
      i --- j
count = 2

... 1 2 3 1 2 3 1 2 3 ...
        i --- j
count = 3

... 1 2 3 1 2 3 1 2 3 ...
          i --- j
count = 4

... 1 2 3 1 2 3 1 2 3 ...
            i --- j
count = 5

... 1 2 3 1 2 3 1 2 3 ...
              i --- j
count = 6  ->  (k - 1) * m
*/
