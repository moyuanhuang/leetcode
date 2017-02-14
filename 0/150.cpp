class Solution {
public:
	int evalRPN(vector<string>& tokens)
	{
		stack<int>	s;
		for(int i = 0; i < tokens.size(); i++)
		{
			string tmp = tokens[i];
			if(isdigit(tmp[0]) or isdigit(tmp[1]))
				s.push(stoi(tmp));
			else
			{
				int b = s.top(); s.pop();
				int a = s.top(); s.pop();
				if(tmp == "+") s.push(a+b);
				else if(tmp == "-") s.push(a-b);
				else if(tmp == "/") s.push(a/b);
				else if(tmp == "*") s.push(a*b);
			}
		} 
		return s.top();
	}
};
