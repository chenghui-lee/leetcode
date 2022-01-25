class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size();
        if (n < 3) return false;
        
        int i = 1, j = n-2;
        while(i < n-1 && arr[i] > arr[i-1]){
            i++;
        }
        while(j >= 0 && arr[j+1] < arr[j]){
            j--;
        }
        i--, j++;
        if (i == 0 || j == n-1) return false;
        return i == j;
    }
};
