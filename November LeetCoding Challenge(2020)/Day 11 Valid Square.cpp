// idea
// square will have 2 different length, the side and the diagoonal
class Solution {
public:
    int distance(vector<int>& p1, vector<int>& p2){
        return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]); // to get rid of negative value
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        unordered_set<int> dist;
        dist.insert(distance(p1, p2));
        dist.insert(distance(p1, p3));
        dist.insert(distance(p1, p4));
        dist.insert(distance(p2, p3));
        dist.insert(distance(p2, p4));
        dist.insert(distance(p3, p4));
        return dist.size() == 2 && !dist.count(0);
    }
};
