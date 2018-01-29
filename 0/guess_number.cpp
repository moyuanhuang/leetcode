// leetcode 374. Guess number high or lower
// EASY: simple binary search

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int lo = 1, hi = n;
        while(true){
            int mid = lo + (hi - lo) / 2;
            int res = guess(mid);
            if(res == -1){
                hi = mid - 1;
            } else if(res == 1){
                lo = mid + 1;
            } else {
                return mid;
            }
        }
        return -1;
    }
};
