class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0 or matrix[0].size() == 0)  return false;
        for(int r = 0; r < matrix.size(); i++){
        	if(matrix[r][0] > target)	break;
        	int low = 0, high = matrix[r].size();
        	while(low < high){
        		int mid = low + (high - low)/2;
        		int val = matrix[r][mid];
        		if(val == target)
        			return true;
        		else if(val < target)
        			low = mid + 1;
        		else
        			high = mid;
        	}
        	if(matrix[r][low] == target)
        		return true;
        }
		return false;
	}
};