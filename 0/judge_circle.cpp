class Solution {
public:
    bool judgeCircle(string moves) {
      int st[2] = {0, 0};
      for(char m : moves){
        if(m == 'U')  st[0]++;
        else if(m == 'D') st[0]--;
        else if(m == 'L') st[1]++;
        else if(m == 'R') st[1]--;
      }
      return st[0] == 0 and st[1] == 0;
    }
};
