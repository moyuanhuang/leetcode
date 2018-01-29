// leetcode 135. Candy
// two-pass scan! left to right, right to left

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies(n, 1);
        for(int i = 0; i < candies.size() - 1; i++){
            if(ratings[i] < ratings[i + 1])
                candies[i+1] = candies[i] + 1;
        }
        for(int i = candies.size()-1; i > 0; i--){
            if(ratings[i-1] > ratings[i])
                candies[i-1] = max(candies[i-1], candies[i] + 1);
        }
        int sum = 0;
        for(int c : candies){
            sum += c;
            cout << sum << " ";
        }
        return sum;
    }
};
