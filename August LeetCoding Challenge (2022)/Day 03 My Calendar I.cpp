class MyCalendar {
public:
    set<pair<int, int>> s;
    MyCalendar() {
        
    }
    
     /*
    |----|  |----| <- next
        |-----|
    
    binary search the position of the current interval in the available booking, 
    then see if the previous and next booking are intersecting with this
    current interval or not
    */
    bool book(int start, int end) {
        auto next = s.lower_bound({start, end});
        if (next != s.end() && next->first < end) return false;
        if (next != s.begin() && (--next)->second > start) return false;
        s.insert({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
