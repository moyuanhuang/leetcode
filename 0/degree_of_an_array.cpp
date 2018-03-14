// leetcode 697. Degree of an Array

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> freq;
        unordered_map<int, pair<int, int> > bound;
        for(int i = 0; i < nums.size(); i++){
            int n = nums[i];
            if(freq.count(n) != 0){
                freq[n]++;
                bound[n].second = i;
            }
            else {
                freq[n] = 1;
                bound[n] = {i, i};
            }
        }

        int max_freq = 0;
        for(auto it = freq.begin(); it != freq.end(); it++){
            max_freq = max(max_freq, it->second);
        }

        int ret = INT_MAX;
        for(auto it = freq.begin(); it != freq.end(); it++){
            if(it->second == max_freq){
                auto b = bound[it->first];
                ret = min(ret, b.second - b.first + 1);
            }
        }
        return ret;
    }
};
