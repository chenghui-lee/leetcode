// Idea : https://leetcode.com/problems/next-greater-element-iii/discuss/101824/Simple-Java-solution-(4ms)-with-explanation.
/*
1. Starting rightmost side, find the index with number lesser than prev number.
2. Starting from that index to right side, find the min num which greater than the number.
3. Swap both of them.
4. Sort the string from index+1 to the end.
*/
class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        int N = s.size();
        
        int index = -1;
        char prev = s[N-1];
        for(int i=N-2; i>=0; i--){
            if (s[i] < prev){
                index = i;
                break;
            }
            prev = s[i];
        }
        if (index == -1) return -1;
        
        int mn = s[index+1], minIndex = index+1;
        for(int i=index+1; i<N; i++){
            if (s[i] <= mn && s[i] > s[index]){
                mn = s[i];
                minIndex = i;
            }
        }
        swap(s[index], s[minIndex]);
        sort(s.begin()+index+1, s.end());
        auto temp = stoll(s);
        return (temp <= INT_MAX)?temp:-1;
    }
};
