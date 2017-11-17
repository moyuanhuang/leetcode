class Solution {

typedef long long llong;
public:
  int largestPalindrome(int n) {
    if(n == 1)  return 9;
    llong largest = pow(10, n) * pow(10, n) - 1;
    llong mod = pow(10, n);
    llong left = largest / mod, right = largest % mod;
    if(reverse(left) > right) left--;
    llong pal = left * mod + reverse(left);
    while(pal > pow(10, 2 * n - 2)){
      for(llong i = mod - 1; i > pal / i; --i){
        if( pal % i  == 0)  return pal % 1337;
      }
      --left;
      pal = left * mod + reverse(left);
    }
    return -1;
  }

private:
  int reverse(int x){
    int ret = 0;
    while(x){
      ret = ret * 10 + x % 10;
      x /= 10;
    }
    return ret;
  }
};
