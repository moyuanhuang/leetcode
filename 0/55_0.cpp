class Solution {
public:
    bool canJump(vector<int>& nums) {
    	int i = nums.size() - 1;
    	if(!i)	return true;
    	int temp = i - 1;
		while(temp >= 0)
		{
			int distance = i - temp;
			if(nums[temp] >= distance)
			{
				if(temp == 0)	return true;
				i = temp;
				temp = i - 1;
				continue;
			}
			temp--;
		}
		return false;
    }
};