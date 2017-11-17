class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int i = 0, r = minutesToTest / minutesToDie + 1;
        while(true){
            if(pow(r,i) >= buckets)    return i;
            i++;
        }
    }
};
