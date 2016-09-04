/*
 * 11.Container With Most Water
 * Created by Moyuan Huang on 25/08/2016
*/
class Solution {
public:
	int maxArea(vector<int>& height) {
		int area = 0;
		int l = 0;
		int r = height.size() - 1;
		while(l < r)
			area = max( area, (r - l) * height[ height[l] <= height[r]? l++: r--]);
		return area;
    }
};