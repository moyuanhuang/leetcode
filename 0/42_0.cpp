/* 42. Trapping Rain Water
 * Created by Moyuan Huang on Sep.22, 2016. 
*/
class Solution {
public:
	int trap(vector<int>& height)
	{
	    if(!height.size())  return 0;
		int left = 0;
		int right = height.size() - 1;
		int lMax = height[left], rMax = height[right];
		int ret = 0;
		while(left <= right)
		{
			if(lMax <= rMax)
			{
				ret += lMax - height[left];
				left++;
				lMax = lMax > height[left]? lMax: height[left];
			}
			else
			{
				ret += rMax - height[right];
				right--;
				rMax = rMax > height[right]? rMax: height[right];
			}
            // cout << "left:" << left << " right: " << right << " return:" << ret << " lMax:" << lMax << " rMax:" << rMax << endl;
		}
		return ret;
	}
};