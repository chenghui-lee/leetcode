/*
https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/solutions/197668/count-the-number-of-islands-o-n/
Idea: Use union find to group all the points that sharing the same row or col index

Then for each group, we can remove all but one points.

This translates into (number of total points) - (number of groups)

The -(j+1) is actually equivalent to ~j. This is to handle 0 index, as -0 = 0. 
*/
class Solution {
private:
    unordered_map<int, int> m;
    int numOfGroups = 0;

    int root(int x){
        if (m.find(x) == m.end()){
            m[x] = x;
            numOfGroups++;
        }
        if (x != m[x]) m[x] = root(m[x]);
        return m[x];
    }

    void uni(int x, int y){
        int rootx = root(x), rooty = root(y);
        if (rootx != rooty){
            m[rootx] = rooty;
            numOfGroups--;
        }
    }
public:
    int removeStones(vector<vector<int>>& stones) {
        for(auto s : stones){
            uni(s[0], ~(s[1]));
        }
        return stones.size() - numOfGroups;
    }
};
