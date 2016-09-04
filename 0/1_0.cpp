// 1.Two Sum
// created on 8/20/2016 by Moyuan Huang
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       	unordered_map<int, int> map;
       	vector<int> result;
       	for(int i=0; i< nums.size(); i++)
       	{
       		if(map.count(target-num[i]))
       		{
       			result.push_back(map[num[i]]);
       			result.push_back(map[target-num[i]];
       		}
       		map[num[i]]=i;
       	}
       	return result;
    }
};