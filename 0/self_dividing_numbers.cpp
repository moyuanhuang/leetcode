//  leetcode #728. Self Dividing Numbers
class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ret;
        for(int i = left; i <= right; i++){
            int temp = i;
            bool is_sd = true;
            while(temp){
                int digit = temp % 10;
                if(digit == 0 or i % digit != 0){
                    is_sd = false;
                    break;
                }
                temp /= 10;
            }
            if(is_sd)   ret.push_back(i);
        }
        return ret;
    }
};
