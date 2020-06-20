class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> v(n);
        string res = "";
        for(int i=0;i<n;i++){
            v[i] = i+1;
        }
        for(int i=1;i<k;i++){
            next_permutation(v.begin(), v.end());
        }
        for(int i=0;i<n;i++){
            res += ('0' + v[i]);
        }
        return res;
    }
};

// another solution, from https://leetcode.com/problems/permutation-sequence/discuss/696452/Algorithm-Explained-w-example
public String getPermutation(int n, int k) {
    int[] factorials = new int[n];
    List<Integer> list = new ArrayList();
    list.add(1);

    factorials[0] = 1;
    for(int i = 1; i < n; ++i){
      // generate factorials  0!, 1!, ..., (n - 1)!
      factorials[i] = factorials[i - 1] * i;
      // generate nums 1, 2, ..., n
      list.add(i + 1);
    }

    // Decrementing k
    k--;

    // compute factorial representation of k
    StringBuilder sb = new StringBuilder();
    for (int i = n - 1; i >= 0; i--){
      int j = k / factorials[i];
      k -= j * factorials[i];

      sb.append(list.get(j));
      list.remove(j);
    }
    return sb.toString();
  }
