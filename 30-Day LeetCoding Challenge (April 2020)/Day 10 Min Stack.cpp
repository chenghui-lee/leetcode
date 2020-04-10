class MinStack {
public:
    /** initialize your data structure here. */
    vector <int> stack;
    vector <int> min;
    MinStack() {
        
    }
    
    void push(int x) {
        if(min.empty() || x <= min.back()){
            min.push_back(x);
        }
        stack.push_back(x);
    }
    
    void pop() {
        if (stack.back() == min.back()){
            min.pop_back();
        }
        stack.pop_back();
    }
    
    int top() {
        if (stack.empty()){
            return -1;
        }
        return stack.back();
    }
    
    int getMin() {
        if (min.empty()){
            return -1;
        }
        return min.back();
    }
};

// idea by LIGHTNINGMCQUEEN

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
