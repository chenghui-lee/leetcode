// @lee215
// States rotate every 14days
class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        for(N = (N-1)%14+1; N>0;N--){
            vector<int> temp(8,0);
            for(int i=1;i<=6;i++){
                if(cells[i-1]==cells[i+1]) temp[i] = 1;
                else temp[i] = 0;
            }
            cells = temp;
        }
        return cells;
    }
};
