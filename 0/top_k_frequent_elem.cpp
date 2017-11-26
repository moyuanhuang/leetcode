// leetcode 347. Top k frequent elements
// Two solutions available
// 1. umap + pq, where key of pq is the frequency
// 2. bucket sort, basiclly a vector of list, watch out the index!

class Solution {
public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    const int len = nums.size();
    vector<vector<int> > bucket(len, vector<int>());

    unordered_map<int, int> umap;
    for(int n : nums){
      if(umap.count(n)) umap[n]++;
      else  umap[n] = 1;
    }

    for(auto elem : umap){
      bucket[elem.second - 1].push_back(elem.first);
    }

    vector<int> ret;
    for(int i = len - 1; i >= 0; --i){
      for(int n : bucket[i]){
        ret.push_back(n);
        if(ret.size() == k)
          return ret;
      }
    }
    return ret;
  }
};


//
// struct TreeNode{
//   int num, freq;
//   TreeNode(int n, int f) : num(n), freq(f) {}
// }
//
// struct comparator{
//   bool operator()(TreeNode* a, TreeNode* b){
//     return a->freq > b->freq;
//   }
// }
//
// class Solution {
// public:
//   vector<int> topKFrequent(vector<int>& nums, int k) {
//     unordered_map<int, int> umap;
//     for(int n : nums){
//       if(umap.count(n)) umap[n]++;
//       else  umap[n] = 1;
//     }
//
//     priority_queue<TreeNode*, vector<TreeNode*>, cmp> pq;
//     for(auto elem : umap){
//       TreeNode* temp = new TreeNode(elem->second, elem->first);
//       pq.push(temp);
//     }
//
//     vector<int> ret;
//     for(int i = 0; i < k; i++){
//       int largest = pq.top()->num;
//       pq.pop();
//       ret.push_back(largest);
//     }
//     return ret;
//   }
// };
