/*
 * 7.Reverse Integer
 * Created by Moyuan Huang on 8.23.2016
 */
class Solution {
public:
    long int reverse(long int x) {
        long result = 0;
        while(x!=0)
        {
            result = (result * 10) + x % 10;
            if(result >= INT_MAX || result <= INT_MIN)
                return 0;
            x /= 10;
        }
        return result;
    }
};