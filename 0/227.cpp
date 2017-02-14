class Solution {
public:
	int calculate(string s)
	{
		istringstream in('+' + s + '+');
		long long ans = 0, term = 0, n; 
		char op;
		while(in >> op)
		{
			if(op == '+' or op == '-')
			{
				ans += term;
				in >> term;
				term *= op == '+'? 1: -1;
			}
			else
			{
				in >> n;
				if(op == '*')	term *= n;
				else if(op == '/')	term /= n;
			}
		}
		return ans;
	}
};