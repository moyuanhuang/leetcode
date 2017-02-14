/* 29. Divide Two Integers
 * Created by Moyuan Huang on Sep 15th, 2016.
*/
class Solution {
public:
	int divide(int dividend, int divisor)
	{
	    if (!divisor || (dividend == INT_MIN && divisor == -1))
            return INT_MAX;
	    int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
	    // to have the abs value of INT_MIN(which is BT INT_MAX, we need a long type variable to store it)
		long dvd = labs(dividend);
        long dvs = labs(divisor);
		int res = 0;
		while (dvd >= dvs)
		{
		    long temp = dvs, multiple = 1;
		    while(dvd >= (temp << 1))
		    {
		        temp <<= 1;
		        multiple <<= 1;
		    }
		    dvd -= temp;
		    res += multiple;
		}
	    return (sign == 1)? res: -res;
	}
};