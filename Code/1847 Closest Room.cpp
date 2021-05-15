/*
Sort the room according to descending room size, sames goes to query

By having a set, holding the list of ids that contains the room ids that statisfy the current query size need (note that we sort them earlier)

Then find the nearest id in the set.
*/

class Solution {
public:
    vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {
        int n = rooms.size(), m = queries.size();
        for(int i=0; i<m; i++){
            queries[i].push_back(i);
        }
        sort(rooms.begin(), rooms.end(), [](const auto& r1, const auto& r2){ return r1[1] > r2[1];}); // sort according to room size descending
        sort(queries.begin(), queries.end(), [](const auto& q1, const auto& q2){ return q1[1] > q2[1];}); // sort according to size descending
        
        vector<int> res(m, -1);
        int i = 0;
        set<int> ids; // to store list of ids which fulfill the current query size
        
        for(auto q : queries){
            while(i < n && rooms[i][1] >= q[1]){ // larger or equal to curr room size
                ids.insert(rooms[i++][0]);
            }
            if (ids.empty()) continue;
            int preffered_id = q[0];
            auto it = ids.lower_bound(preffered_id);
            int id1 = (it != ids.end()) ? *it : INT_MAX;
            int id2 = id1;
            if (it != ids.begin()) id2 = *prev(it);
            res[q[2]] = abs(id1 - preffered_id) < abs(id2 - preffered_id) ? id1 : id2;
        }
        return res;
    }
};
