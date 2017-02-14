/* 27. Remove Element
 * Created by Moyuan Huang on Sep 13,2016.
*/
class Solution {
public:
    int removeElement(vector<int>& nums, int val)
    {
        for(vector<int>::iterator iter = nums.begin(); iter != nums.end(); iter++)
        	if(*iter == val)
        	{
        		nums.erase(iter);
        		iter--;
        	}

        cout << nums.size() << endl;
        return nums.size();
    }
};