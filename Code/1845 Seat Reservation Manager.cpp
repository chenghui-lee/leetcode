class SeatManager {
public:
    priority_queue<int, vector<int>, greater<int>> q;
    SeatManager(int n) {
        for(int i=1; i<=n; i++){
            q.push(i);
        }
    }
    
    int reserve() {
        int pos = q.top();
        q.pop();
        return pos;
    }
    
    void unreserve(int seatNumber) {
        q.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */

// using bitset
class SeatManager {
public:
    bitset<100000> s;
    SeatManager(int n) {
        s.set();
    }
    
    int reserve() {
        int pos = s._Find_first();
        s.reset(pos);
        return pos+1;
    }
    
    void unreserve(int seatNumber) {
        s.set(seatNumber - 1);
    }
};
