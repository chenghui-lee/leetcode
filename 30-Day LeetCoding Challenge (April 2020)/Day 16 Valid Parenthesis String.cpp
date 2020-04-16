class Solution {
public:
bool checkValidString(string s) {
/*


'*' can be used as either ( or ) or nothing.
We can solve this by using two stack, storing int for the index of '(' and '*'
The first stack we store the index of each '(' we encounter
The second stack we store the index of each '*' we encounter
If the character is ')', we pop from first stack, else we push from second stack. (If both stacks are empty, then return false)
After completing the string checking, we check is there any left over '(' by poping elements from both stacks, comparing their index
If the index of second stack is smaller than first index, meaning the star appear before the '(', return false.
Finally return first stack.isEmpty()

*/
        stack<int> q;
        stack<int> star;
        for (int i = 0; i<s.length(); i++){
        	char x = s[i];
        	if (x == '('){
        		q.push(i);
        	}else if (x == '*'){
        		star.push(i);
        	}else{
        		if (q.empty() && star.empty()){
        			return false;
        		}
        		if (!q.empty()){
        			q.pop();
        		}else{
        			star.pop();
        		}
        	}
        }
        while(!q.empty() && !star.empty()){
            int x = q.top(); q.pop();
            int y = star.top(); star.pop();
        	if (y < x){ 
        		return false; // if the star is before the ( , return false
        	}
        }
        return q.empty();
        

}
};
