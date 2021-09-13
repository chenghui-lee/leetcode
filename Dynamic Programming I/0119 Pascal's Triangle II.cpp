class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex == 0) return {1};
        else if (rowIndex==1) return {1,1};
        // vector<int> res(rowIndex+1);
        
        vector<int> store = {1,1};
        for(int i=2; i<=rowIndex; i++){
            vector<int> cur(i+1, 1);
            for(int j=1;j<cur.size()-1; j++){
                cur[j] = store[j-1] + store[j];
            }
            store = cur;
        }
        
        return store;
    }
};
