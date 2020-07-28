class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if (n == 0) return tasks.size();
        unordered_map<char, int> m;
        int max_occur = 0;
        int numMax = 0;
        for(auto x : tasks) {
            m[x]++;
            if(max_occur == m[x]) numMax++;
            else if (m[x] > max_occur){
                max_occur = m[x];
                numMax = 1;
            }
        }
        int partCount = max_occur - 1;
        int partLength = n - (numMax - 1);
        int emptySlot = partCount * partLength;
        int availableTask = tasks.size() - max_occur*numMax;
        int idleSlot = max(0, emptySlot - availableTask);
        return tasks.size() + idleSlot;
        
    }
};
// https://leetcode.com/problems/task-scheduler/discuss/104500/Java-O(n)-time-O(1)-space-1-pass-no-sorting-solution-with-detailed-explanation
