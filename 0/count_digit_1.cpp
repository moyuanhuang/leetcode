// thinking about compute the number of 1's on the 100-digit of 5821
// first, get 58 and 21:
// 58 means there are 1xx, 11xx, 21xx, 31xx, 41xx, 51xx, each of them has 100 1's
// this is obtained by (n + 2)/ 10 * 100
// then 21 means if we have x1xx, we only have 21 1's instead of 100 1's

class Solution {
public:
    int countDigitOne(int n) {
      int count = 0;
      for(long long i = 1; i <= n; i *= 10){
        count += (n / i + 2)/10 * i + ((n / i) % 10 == 1) * (n % i + 1);
      }
      return count;
    }
};
