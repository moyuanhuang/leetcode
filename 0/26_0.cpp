/* 26. Remove Duplicates from Sorted Array
 * Created by Moyuan Huang on Sep.11, 2016.
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0)   return 0;
        int size = nums.size();
        int new_size = 1;
        for( int i = 1; i < size; i++)
        {
            if(nums[i] != nums[i-1])
                nums[new_size++] = nums[i];
        }
        return new_size;
    }
};