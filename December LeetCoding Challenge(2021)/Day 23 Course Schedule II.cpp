class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<unordered_set<int>> dependsOnMe(numCourses);
        vector<unordered_set<int>> dependsOnWho(numCourses);

        
        for(auto x : prerequisites){
            dependsOnMe[x[1]].insert(x[0]);
            dependsOnWho[x[0]].insert(x[1]);
        }
        
        vector<int> res;
        queue<int> q;
        for(int i=0;i<numCourses; i++){
            if (dependsOnWho[i].size() == 0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            res.push_back(cur);
            for(auto x : dependsOnMe[cur]){
                dependsOnWho[x].erase(cur);
                if (dependsOnWho[x].size() == 0) q.push(x);
            }
        }
        
        if (res.size() != numCourses) res.clear();
        return res;
    }
};
