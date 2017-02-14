class Solution {
public:
	string addBinary(string a, string b)
	{
		string ret = "";
		int n1 = a.size()-1, n2= b.size()-1;
		int carry = 0;
		while(n1>=0 and n2>=0)
		{
			ret.insert(ret.begin(), a[n1]-'0'+b[n2]+carry);
			if(ret[0] >= '2')
			{
				ret[0] -= 2;
				carry = 1;
			}
			else
				carry = 0;
			n1--;
			n2--;
		}
		while(n1 >= 0 or n2 >= 0)
		{
			if(n1 < 0)
				ret.insert(ret.begin(), b[n2]+carry);
			else
				ret.insert(ret.begin(), a[n1]+carry);
			if(ret[0] >= '2')
			{
				ret[0] -= 2;
				carry = 1;
			}
			else
				carry = 0;
			n1--;
			n2--;
		}
		if(carry)   ret.insert(ret.begin(), '1');
		return ret;
	}
};