class Solution {
public:
    int addDigits(int num) {
      while(num % 10 != 0){
        int tmp = 0;
        while(num != 0){
          tmp += num % 10;
          tmp /= 10;
        }
        num = tmp;
      }
      return num;
    }
};
