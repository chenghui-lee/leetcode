/*
Idea:
Think of having n place and 4 place for divider (|),
a divider is the place where we stop putting the current character and switch to the next character.
So we have a total of (n+4) places, and we need to pick 4 place to put divider, hence

(n+4) C 4
*/
class Solution {
public:
    int countVowelStrings(int n) {
        // (n+4) C 4
        return (n + 1) * (n + 2) * (n + 3) * (n + 4) / 24;
    }
};
