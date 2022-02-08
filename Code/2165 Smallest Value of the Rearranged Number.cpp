class Solution {
public:
    long long smallestNumber(long long num) {
        vector<int> v;
        
        if (num == 0) return 0;
        long long t = num < 0 ? -num : num;
        while(t > 0){
            v.push_back(t % 10);
            t /= 10;
        }
        
        long long res = 0;
        if (num < 0){
            sort(v.rbegin(), v.rend());
            int i = 0;
            if (v[0] == 0) return res;
            for(int i = 0; i<v.size(); i++){
                res = res * 10 + v[i];
            }
            return -res;
        }else{
            sort(v.begin(), v.end());
            int i = 0;
            while(v[i] == 0) i++;
            swap(v[0], v[i]);
            for(int i = 0; i<v.size(); i++){
                res = res * 10 + v[i];
            }
            return res;
        }
        return res;
    }
};
