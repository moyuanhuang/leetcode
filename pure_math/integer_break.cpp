// 343. Integer Break
// medium
// math problem:
// if f >= 4, we can get 2*(f-2) >= f, so we always can split f into (f-2 * 2)
// 3*3 is simply better than 2*2*2, so you’d never use 2 more than twice.

class Solution {
public:
    int integerBreak(int n) {
        int result = 1;
        if(n == 2)  return 1;
        if(n == 3)  return 2;
        while(n > 1){
            if(n == 2 or n == 4){
                n -= 2;
                result *= 2;
            }
            else {
                n -= 3;
                result *= 3;
            }
        }
        return result;
    }
};
