class Solution {
public:
    int MOD = 1e9 + 7;
    
    long getArea(multiset<vector<int>>& intervals, long width){
        long area = 0;
        int prev = 0;
        
        for(auto x : intervals){
            int bottom = x[0], top = x[1];
            bottom = max(bottom, prev);
            if (top > bottom){
                area += (top - bottom) * width;
                prev = top;
            }
        }
        
        return area;
    }
    int rectangleArea(vector<vector<int>>& rectangles) {
        
        vector<vector<int>> events;
        for(auto& rect : rectangles){
            auto x1 = rect[0], y1 = rect[1], x2 = rect[2], y2 = rect[3];
            events.push_back({x1, 0, y1, y2});
            events.push_back({x2, 1, y1, y2});
        }
        sort(events.begin(), events.end());
        multiset<vector<int>> intervals;
        
        int prevX = 0;
        long res = 0;
        for(auto& e : events){
            auto curX = e[0], type = e[1], y1 = e[2], y2 = e[3];
            
            res += getArea(intervals, curX - prevX);
            
            if (type == 1){ // closing
                auto it = intervals.find({y1, y2});
                intervals.erase(it);
            }else{
                intervals.insert({y1, y2});
            }
            prevX = curX;
        }
        return res % MOD;
    }
};
