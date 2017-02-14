class Solution {
public:
	int countPrimes(int n)
	{
		int cnt = 0;
		int upper = sqrt(n);
		vector<bool> isPrime(n, true);
		for(int i = 2; i < n; i++)
		{
			if(isPrime[i])
			{
				cnt++;
				if(i > upper)
					continue;
				for(int j = i*i; j < n; j += i)
					isPrime[j] = false;
			}
		}
		return cnt;
	}
};