class MyCircularQueue {
public:
    vector<int> v;
    int cap;
    MyCircularQueue(int k) {
        cap = k;
    }
    
    bool enQueue(int value) {
        if (v.size() < cap){
            v.push_back(value);
            return true;
        }else return false;
    }
    
    bool deQueue() {
        if (v.size()){
            v.erase(v.begin());
            return true;
        }else return false;
    }
    
    int Front() {
        if (v.size()) return *v.begin();
        return -1;
    }
    
    int Rear() {
        if (v.size()) return v.back();
        return -1;
    }
    
    bool isEmpty() {
        return v.empty();
    }
    
    bool isFull() {
        return v.size() == cap;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
