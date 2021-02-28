class FreqStack {
public:
    vector<vector<int>> num; // index = occurance
    unordered_map<int, int> m; // num, frequency
    int maxOcc = 0;
    FreqStack() {
        num = vector<vector<int>>(10001);
    }
    
    void push(int x) {
        m[x]++;
        num[m[x]].push_back(x);
        maxOcc = max(maxOcc, m[x]);
    }
    
    int pop() {
        for(int i=maxOcc; i>=1; i--){
            if (num[i].size()){
                int ans = num[i].back();
                m[ans]--;
                num[i].pop_back();
                return ans;
            }
        }
        return -1; // not possible
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */
