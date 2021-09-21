/*
Microsoft | OA 2019 | Min Adj Swaps to Make Palindrome
Given a string, what is the minimum number of adjacent swaps required to convert a string into a palindrome. If not possible, return -1.
https://leetcode.com/discuss/interview-question/351783/

Input: "mamad"
Output: 3

Input: "asflkj"
Output: -1

Input: "aabb"
Output: 2

Input: "ntiin"
Output: 1

*/
/*
     * Algorithm:
     *     1. First check the given string is a jumbled/shuffled palindrome or not.
     *     2. Next have two pointers p1 at 0 and p2 at s.length - 1 and start iterating.
     *     3. If chars at both the pointers are same then just shrink the window (increase the p1 and decrease the p2).
     *     4. or Else
     *          a. find the matching pair and swap the char to p2 index (increase swap count while swapping) and finally shrink the window.
     *          b. if not found just swap once with adjacent index and increase the swap count (do not shrink the window here)
     *     5. Print the Swap Count
     *
     * Time Complexity: O(n) to find Palindrome + [ O(n) for two pointer iteration * O(n) for checking and swapping ] so => O(n^2)
     * Space Complexity: O(n)
     *
     */

bool isShuffledPalindrome(string& s){
    vector<int> count(26);
    for(auto& ch : s){
        count[ch - 'a']++;
    }
    int odd = 0;
    for(auto& c : count){
        if (c % 2 == 1) odd++;
    }
    return odd <= 1;
}

int getNoOfSwaps(string s){
    if (s.size() <= 1) return 0;
    if (!isShuffledPalindrome(s)) return -1;
    int i = 0, j = (int)s.size() - 1;
    int res = 0;
    
    while(i < j){
        if (s[i] == s[j]) i++, j--;
        else{
            int k = j;
            while(i < k && s[i] != s[k]) k--;
            
            if (i == k){ // if the odd char, we move it to center
                swap(s[i], s[i+1]);
                res++;
            }else{ // swap matching char to j
                while(k < j){
                    swap(s[k], s[k+1]);
                    res++, k++;
                }
                i++, j--;
            }
        }
    }
    return res;
    
}

int main() {
    cout << getNoOfSwaps("mamad") << endl;
    cout << getNoOfSwaps("asflkj") << endl;
    cout << getNoOfSwaps("aabb") << endl;
    cout << getNoOfSwaps("ntiin") << endl;
}

