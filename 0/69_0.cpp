class Solution {
public:
	int mySqrt(int x) {
		if(!x)	return x;
		int l = 1, r = INT_MAX;
		while(true)
		{
			int mid = l + (r-l)/2;
			if(mid * mid > x)
				r = mid -1;
			else
			{
				if((mid + 1) * (mid + 1) > x )
					return mid;
				l = mid + 1;
			}
		}
		return mid;

	}
};