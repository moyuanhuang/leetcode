/* 50. Pow(x, n)
 * Created by Moyuan Huang on Sep.22, 2016. 
*/
class Solution {
public:
	double myPow(double x, int n)
	{
		if(n == 0)	return 1;
		bool neg = n > 0? false: true;
		double ret = 1;
		n = abs(n);
		for(int i = 0; i < n; i++)
			ret = ret * x;
		if(neg)	return 1/ret;
		else	return ret;
	}
};