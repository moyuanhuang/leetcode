class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> umap;
        vector<int> ret;
        for(int n : nums1){
            umap[n]++;
        }
        for(int n : nums2){
            if(umap[n] > 0){
                umap[n]--;
                ret.push_back(n);
            }
        }
        return ret;
    }
};
