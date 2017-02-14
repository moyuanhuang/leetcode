/* 43. Multiply Strings
 * Created by Moyuan Huang on Sep.25, 2016.
*/
class Solution {
public:
	string multiply(string num1, string num2)
	{
		vector<int> ret(num1.length() + num2.length() + 1, 0);
		for(int i = num1.length()-1; i >= 0; i--)
			for(int j = num2.length()-1; j>= 0; j--)
				ret[i+j] = num1[i] * num2[j];
		for(int i = ret.size()-1; i >0; i--)
		{
			ret[i-1] += ret[i]/10;
			ret[i] = ret[i]%10;
		}
		string ret_string(num1.length() + num2.length() + 1, 0);
		for(int i = 0; i < ret.size(); i++)
		    ret_string[i] = ret[i] + '0';
		return ret_string;
		    
	}
};