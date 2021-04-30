class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        unordered_set<int> s;
        int x_powerbound = x==1?bound : log2(bound) / log2(x);
        int y_powerbound = y==1?bound : log2(bound) / log2(y);
        
        for(int i=0; i<= x_powerbound; i++){
            for(int j=0; j<= y_powerbound; j++){
                long val = pow(x, i) + pow(y, j);
                if (val <= bound) s.insert((int)val);
                if (y == 1) break;
            }
            if (x == 1) break;
        }
        return vector<int>(s.begin(), s.end());
    }
};
