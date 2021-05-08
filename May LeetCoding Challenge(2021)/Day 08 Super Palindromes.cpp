// https://leetcode.com/problems/super-palindromes/discuss/272581/C%2B%2B-8ms-BFS-solution-no-cheating
class Solution {
public:
    int superpalindromesInRange(string L, string R) {
        long double lb = sqrtl(stol(L)), ub = sqrtl(stol(R));
        int ans = lb <= 3 && 3 <= ub;
        queue<pair<long, int>> q;
        q.push({1, 1}), q.push({2, 1});
        while (true) {
            auto p = q.front(); q.pop();
            long x = p.first, len = p.second;
            if (x > ub) break;
            long W = powl(10, (len + 1) / 2);
            if (x >= lb) ans += is_palindrome(x * x);
            long r = x % W, l = x - (len % 2 ? x % (W / 10) : r);
            if (len % 2)
                q.push({10 * l + r, len + 1});
            else
                for (int d = 0; d <= 2; d++)
                    q.push({10 * l + d * W + r, len + 1});
        }
        return ans;
    }
private:
    bool is_palindrome(long x) {
        if (x == 0) return true;
        if (x % 10 == 0) return false;
        long left = x, right = 0;
        while (left >= right) {
            if (left == right || left / 10 == right) return true;
            right = 10 * right + (left % 10), left /= 10;
        }
        return false;
    }
};
