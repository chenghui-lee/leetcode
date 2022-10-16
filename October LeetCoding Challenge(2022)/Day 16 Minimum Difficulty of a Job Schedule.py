# Python 3
# https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/solutions/490316/java-c-python3-dp-o-nd-solution/

import functools
class Solution:
    def minDifficulty(self, jobDifficulty: List[int], d: int) -> int:
        n = len(jobDifficulty)
        if n < d:
            return -1

        @functools.lru_cache(None)
        def dfs(i,d): # the new cut starts at i, with d days remaining
            if d == 1: # last day, have to do all the job. Hence the largest element from i to n-1
                return max(jobDifficulty[i:]) 
            res = float('inf')
            maxD = 0
            for j in range(i, n - d + 1): # for all the remaining jobs
                maxD = max(maxD, jobDifficulty[j])
                res = min(res, maxD + dfs(j+1, d-1))
            return res

        return dfs(0, d)
