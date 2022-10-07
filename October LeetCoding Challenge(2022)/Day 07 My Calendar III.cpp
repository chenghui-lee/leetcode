// line sweeping
// https://leetcode.com/problems/my-calendar-iii/solutions/2670758/leetcode-the-hard-way-explained-line-by-line/?orderBy=most_votes
class MyCalendarThree {
public:
    map<int,int> m;
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        m[start]++;
        m[end]--;
        int cur = 0, res = 0;
        for(auto x : m) {
            cur += x.second; // the reason why we add up all values is
            // because within an interval, the final result will be the
            // highest value in it. When a new interval starts, we add
            // the value, when it ends, we deduct it.
            res = max(res, cur);
        }
        return res;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */
