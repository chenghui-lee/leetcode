/*
Microsoft | OA 2019 | Min Steps to Make Piles Equal Height
https://leetcode.com/discuss/interview-question/364618/

Alexa is given n piles of equal or unequal heights. In one step, Alexa can remove any number of boxes from the pile which has the maximum height and try to make it equal to 
the one which is just lower than the maximum height of the stack. 
Determine the minimum number of steps required to make all of the piles equal in height.

Input: piles = [5, 2, 1]
Output: 3
Explanation:
Step 1: reducing 5 -> 2 [2, 2, 1]
Step 2: reducing 2 -> 1 [2, 1, 1]
Step 3: reducing 2 -> 1 [1, 1, 1]
So final number of steps required is 3.


*/

int minSteps(vector<int> piles){
    int n = piles.size();
    if (n <= 1) return 0;
    
    sort(begin(piles), end(piles), greater<int>());
    int res = 0;
    for(int i=1; i<n; i++){
        if (piles[i] != piles[i-1]){
            res += i;
        }
    }
    return res;
}

int main() {
    cout << minSteps({5, 2, 1}) << endl;
    cout << minSteps({1, 1, 2, 2, 2, 3, 3, 3, 4, 4}) << endl;
}

