// The idea is to do binary search to find the min index such that citations[i] >= len(citations) - i, then the answer is len(citations)-i
class Solution {
public:
    int hIndex(vector<int>& citations) {
        if (citations.size() == 0) return 0;
        int l = 0, r = citations.size()-1;
        
        while(l<=r){
            int mid = l + (r-l)/2;
            if (citations[mid] >= citations.size()-mid){
                r = mid -1;
            }else{
                l = mid+1;
            }
            
        }
        return citations.size() - l;
    }
};
