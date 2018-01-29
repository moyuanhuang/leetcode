// leetcode 453. Minimum Moves to Equal Array Elements
// math problem: key is to treat "increment n-1 numbers" as "decrement 1 number"

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int sum = 0, minimum = INT_MAX;
        for(int n : nums){
            sum += n;
            minimum = min(n, minimum);
        }
        return sum -  minimum * nums.size(); 
    }
};
