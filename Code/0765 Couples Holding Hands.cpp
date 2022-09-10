/*
Got 2 methods to solve this problem:

**1. Greedy**
Just like how we would do it in real life, go from the left to the rightmost, if we encounter mismatch, swap them and keep going.

**2. DSU**



*/
class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        unordered_map<int, int> m; // num, index
        int n = row.size();
        
        for(int i=0; i<n; i++){
            m[row[i]] = i;
        }
        int swaps = 0;
        for(int i=0; i<n; i+=2){
            int a = row[i];
            int b = a + (a % 2 == 0 ? 1 : -1);
            
            int curNext = row[i+1]; // who is sitting beside a right now
            if (curNext != b){
                swaps++;
                swap(row[i+1], row[m[b]]); // swap their places
                swap(m[curNext], m[b]); // swap their place in the map as well
            }
        }
        return swaps;
    }
};
