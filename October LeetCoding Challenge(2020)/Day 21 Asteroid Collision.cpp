class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res;
        for(int x : asteroids){
            if(x > 0) res.push_back(x);
            else{
                while(!res.empty() && res.back() > 0 && res.back() < -x) res.pop_back();
                if (res.empty() || res.back() < 0) res.push_back(x);
                else if (res.back() == -x) res.pop_back();
            }
        }
        return res;
    }
};
