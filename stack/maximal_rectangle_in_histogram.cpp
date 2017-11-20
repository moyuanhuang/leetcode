class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
      heights.push_back(0);
      stack<int> index;
      int area = 0;

      for(int i = 0; i < heights.size(); i++){
        while(!index.empty() and heights[i] <= heights[index.top()]){
          int h = heights[index.top()];
          index.pop();
          int left = index.empty() ? -1 : index.top();

          area = max(area, (i - left - 1) * h);
        }
        index.push(i);
      }
      return area;

    }
};
