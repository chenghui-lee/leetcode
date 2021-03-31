// https://leetcode.com/problems/stamping-the-sequence/discuss/201546/12ms-Java-Solution-Beats-100/304246
class Solution {
public:
  vector<int> movesToStamp(string stamp, string target) {
    vector<bool> visited(target.size(), false);
    vector<int> ret;

    int stars = 0;
    while (stars < target.size()) {
      bool has_replace = false;
      for (int i = 0; i <= target.size() - stamp.size(); i++) {
        if (!visited[i] && canReplace(target, i, stamp)) {
          stars = doReplace(target, i, stamp.size(), stars);

          has_replace = true;
          visited[i] = true;
          ret.push_back(i);
          if (stars == target.size()) {
            break;
          }
        }
      }

      if (!has_replace) {
        return vector<int>{};
      }
    }

    reverse(ret.begin(), ret.end());
    return ret;
  }
  // from pos at start from target to match stamp
  bool canReplace(string &target, int start, string &stamp) {
    for (int i = 0; i < stamp.size(); i++) {
      if (target[i + start] != '*' && target[i + start] != stamp[i]) {
        return false;
      }
    }
    return true;
  }

  int doReplace(string &target, int start, int len, int count) {
    for (int i = 0; i < len; i++) {
      if (target[i + start] != '*') {
        target[i + start] = '*';
        count++;
      }
    }
    return count;
  }
};
