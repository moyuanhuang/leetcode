// leetcode 280. Wiggle Sort
// the fastest way is to just compare the current elem with next,
// and swap if needed
// time complexity: O(n)
class Solution {
public:
    // solution 1, bubble sort
    // time complexity: O(n^2)
    // void wiggleSort(vector<int>& nums) {
    //     int count = 0;
    //     for(int i = 0; i < nums.size(); i++){
    //         int pivot = nums[i], index = i;
    //         for(j = i + 1; j < nums.size(); j++){
    //             if(count % 2){
    //                 // find min
    //                 if(nums[j] < nums[i]){
    //                     pivot = nums[j];
    //                     index = j;
    //                 }
    //             } else {
    //                 // find_max
    //                 if(nums[j] > nums[i]){
    //                     pivot = nums[j];
    //                     index = j;
    //                 }
    //             }
    //         }
    //         swap(nums[i], nums[j]);
    //         count++;
    //     }
    // }

    // solution 2: one-pass scan
    void wiggleSort(vector<int>& nums) {
        if(nums.empty())    return;
        for(int i = 0; i < nums.size() - 1; i++){
            if((i % 2 == 0) and nums[i] > nums[i + 1]){
                swap(nums[i], nums[i+1]);
            }
            else if((i % 2 == 1) and nums[i] < nums[i + 1]){
                swap(nums[i], nums[i+1]);
            }
        }
        return;
    }
};
