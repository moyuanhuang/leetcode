/* 20. Valid Parentheses
 * Created by Moyuan Huang on Sep.4, 2016.
*/
class Solution {
public:
	bool isValid(string s)
	{
		stack<char> myStack;
		for(int i = 0; i < s.length(); i++)
		{
			if(s[i] == '(' or s[i] == '[' or s[i] == '{')
				myStack.push(s[i]);
			else
			{
			    if(myStack.empty()) return false;
				char temp = myStack.top();
				myStack.pop();
				if((s[i] == ')' and temp == '(') or (s[i] == ']' and temp == '[') or (s[i] == '}' and temp == '{'))	continue;
				else	return false;
			}
		}
		return myStack.empty();
	}
};