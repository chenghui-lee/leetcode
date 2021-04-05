// https://leetcode.com/problems/global-and-local-inversions/discuss/113644/C%2B%2BJavaPython-Easy-and-Concise-Solution
/*

All local inversions are global inversions.
If the number of global inversions is equal to the number of local inversions,
it means that all global inversions in permutations are local inversions.
It also means that we can not find A[i] > A[j] with i+2<=j.
In other words, max(A[i]) < A[i+2]

In this first solution, I traverse A and keep the current biggest number cmax.
Then I check the condition cmax < A[i+2]

*/
class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        int curmax = 0, n = A.size();;
        for(int i=0; i<n-2; i++){
            curmax = max(curmax, A[i]);
            if (curmax > A[i+2]) return false;
        }
        return true;
    }
};
