// Maintain the current character run length and previous character run length. If prevRunLength >= curRunLength, we have found a valid string.
/*
currRunLength - this keeps track of the current count of contiguous 1's or 0's that you've currently seen
prevRunLength - this keeps track of the previous count of contiguous 1's or 0's that you've currently seen

The first if/else block manipulates these variables

The last if statement is for checking how many valid substrings you have seen so far in the iteration.
For any value of prevRunLength > 1, we can only have prevRunLength valid substrings up until prevRunLength is manipulated (this happens when we see mismatching digits)
*/
// https://leetcode.com/problems/count-binary-substrings/discuss/108600/Java-O(n)-Time-O(1)-Space
class Solution {
public:
    int countBinarySubstrings(string s) {
        int prev = 0, cur = 1, res = 0;
        for(int i=1; i<s.size(); i++){
            if (s[i] == s[i-1]) cur ++;
            else{
                prev = cur;
                cur = 1;
            }
            if (prev >= cur) res++;
        }
        return res;
    }
};
