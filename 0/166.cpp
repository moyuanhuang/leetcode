class Solution {
public:
	string fractionToDecimal(int numerator, int denominator)
	{
		if(numerator == 0)	return 0;
		string res("");
		if(numerator < 0 ^ denominator < 0)	res += '-';

		int64_t n = abs(numerator);
		int64_t d = abs(denominator);

		res += to_string(n/d);
		if(n%d == 0)	return res;

		unordered_map<int, int> map;
		for(int64_t r = n%d; r; r%= d)
		{
			if(map.count(r) > 0)
			{
				res.insert(map[r], 1, '(');
				res+= ')'
			}
			map[r] = res.size();
			r*= 10;
			res += to_string(n, d);
		}
		return res;



	}
};