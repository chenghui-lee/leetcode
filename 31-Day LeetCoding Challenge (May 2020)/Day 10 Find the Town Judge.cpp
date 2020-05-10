class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        // map<int, int> 这个人被trust几个, 最后我们check他的value 是不是等于 N-1
        // map<int, bool> 那个人有没有trust别人
        // [1,3]
        // 我们 SET  [3] =1, [1] = true;
        // 完了后我们iter过 N, if [M] = N-1 && [M] != true, return M,else return false
        unordered_map<int, int> trusted;
        unordered_map<int, bool> trustSomebody;
        for (int i =0; i<trust.size(); i++){
            int a = trust[i][0];
            int b = trust[i][1];
            trusted[b]++;
            trustSomebody[a] = true;
        }
        for (int i = 1; i<=N ; i++){
            if (trusted[i] == N-1 && trustSomebody[i] != true){
                return i;
            }
        }
        return -1;
    }
};
