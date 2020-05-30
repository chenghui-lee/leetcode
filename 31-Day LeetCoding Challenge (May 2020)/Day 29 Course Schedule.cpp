class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> pointToMe(numCourses);
        
        for (int i=0;i<prerequisites.size();i++){
            pointToMe[prerequisites[i][0]]++; 
        }
        
        stack<int> s;
        for (int i=0;i<pointToMe.size();i++){
            if (pointToMe[i] == 0) s.push(i);
        }
        int count =0;
        while (!s.empty()){
            count++;
            int temp = s.top();
            s.pop();
            for (int i=0;i<prerequisites.size();i++){
                if (temp == prerequisites[i][1]){
                    pointToMe[prerequisites[i][0]]--;
                    if (pointToMe[prerequisites[i][0]] == 0){
                        s.push(prerequisites[i][0]);
                    }
                }
                
            }
        }
        return count == numCourses;
    }
};


// another solution using dfs (faster)
class Solution {
    vector<vector<int>> graph;
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        graph = vector<vector<int>>(numCourses);
        for (auto x : prerequisites){
            graph[x[0]].push_back(x[1]);
        }
        vector<int> vec(numCourses,0);
        for (int i=0;i<numCourses;i++){
            if (cycle(i, vec))
                return false;
        }
        return true;
    }
    bool cycle(int index, vector<int> &vec){
        if (vec[index]==1) return true;
        if (vec[index]==2) return false;
        vec[index] = 1;
        for (const int t : graph[index]){
            if (cycle(t,vec))
                return true;
        }
        vec[index]=2;
        return false;
    }
};
