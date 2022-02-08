class Bitset {
public:
    vector<int> v;
    vector<int> f;
    int onee = 0, zero = 0;
    Bitset(int size) {
        vector<int> v1(size, 0);
        v = v1;
        vector<int> f1(size, 1);
        f = f1;
        zero = size;
    }
    
    void fix(int idx) {
        if (v[idx] == 1) return;
        onee++;
        zero--;
        v[idx] = 1;
        f[idx] = 0;
    }
    
    void unfix(int idx) {
        if (v[idx] == 0) return;
        onee--;
        zero++;
        v[idx] = 0;
        f[idx] = 1;
    }
    
    void flip() {
        swap(onee, zero);
        swap(v, f);
    }
    
    bool all() {
        return onee == v.size();
    }
    
    bool one() {
        return onee > 0;
    }
    
    int count() {
        return onee;
    }
    
    string toString() {
        string res = "";
        for(auto x : v){
            res += to_string(x);
        }
        return res;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */
