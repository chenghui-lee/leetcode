class MyCalendar {
public:
    vector<vector<int>> d;
    MyCalendar() {
        vector<vector<int>> temp;
        d = temp;
    }
    
    bool book(int start, int end) {
        for(auto b : d){
            if (max(b[0], start) < min(b[1], end)) return false;
        }
        d.push_back({start, end});
        return true;
    }
};

// use set
class MyCalendar {
public:
    set<pair<int, int>> s;
    MyCalendar() {
        
    }
    
    /*
    |----|  |----| <- next
        |-----|
    
    
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
