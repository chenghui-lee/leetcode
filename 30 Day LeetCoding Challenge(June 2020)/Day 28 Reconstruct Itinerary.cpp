// https://leetcode.com/problems/reconstruct-itinerary/discuss/78768/Short-Ruby-Python-Java-C%2B%2B
/*
Lets say for the tickets : [["JFK","KUL"],["JFK","NRT"],["NRT","JFK"]]
we can derive the following :
JKF -> KUL, NRT
NRT -> JFK
The main idea is to DFS the route from JFK, when we encounter a dead end(route), we want to push that place to the back of the result

1) Firstly JKF -> KUL , since KUL is deadend, we add KUL to the back of the result.
vector : {KUL}
2) Then we go to second airport, which is NRT
3) NRT -> JFK
4) And now JFK is deadend, since we remove airport everytime we explore a new place, JFK is added to the resultt
vector : {JFK,KUL}
5) Backtrack to NRT, NRT is deadend so we add NRT to result
vector : {NRT,JFK,KUL}
6) And finally JFK again
vector : {JFK,NRT,JFK,KUL} ## answer
In the program we keep pushing back, so we need to reverse it


*/
class Solution {
public:
    map<string, multiset<string>> airports;
    vector<string> result;
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto x : tickets){
            airports[x[0]].insert(x[1]);
        }
        visit("JFK");
        return vector<string>(result.rbegin(), result.rend());
    }
    
    void visit(string from){
        while(airports[from].size()){
            string next = *airports[from].begin();
            airports[from].erase(airports[from].begin());
            visit(next);
        }
        result.push_back(from);
    }
    
};
