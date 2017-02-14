/*
 * 31.Next Permutation
 * Created By Moyuan Huang on Sep.17, 2016.
*/
/*
 * 其中红色的数字表示next permutation改变原数字的最高位。比如对于725321来说，
 * 由于5321由于从最低位到最高位是升序排列，已经达到*该四位数字permutation的最
 * 大值。这时不得不改变第5位的2来增加数值。如何改变？为了使增量最小，在前4位中比
 * 第5位大的数(5, 3)中找一个最小的数，即数字3。用3替换2，而剩下5, 2, 2, 1四个
 * 数字要组成最低4位。由于第5位已经从2增加到3，同样为了使增量最小，我们希望剩下
 * 的4位数尽可能小。所以将他们从低到高位降序排列即可。
*/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int mismatch = nums.size() - 1;
        while(mismatch > 0 and nums[mismatch-1] >= nums[mismatch])
        	mismatch--;
        mismatch--;
        if(mismatch == -1)
        {
        	reverse(nums.begin(), nums.end());
        	return;
        }
        int pos = -1;
        int i = 0;
        for(i = nums.size()-1; i > mismatch; i--)
        	if(nums[i] > nums[mismatch])	break;
        swap(nums[i], nums[mismatch]);
        sort(nums.begin() + mismatch + 1, nums.end());
        return;
    }
};