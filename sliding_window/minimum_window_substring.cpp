// #76. Minimum Window Substring
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> umap;
        int count = t.size(), left = 0, start = 0, len = INT_MAX;
        for(char c : t){
            umap[c]++;
        }
        for(int i = 0; i < s.size(); i++){
            char c = s[i];
            umap[c]--;
            // for those not in t, the value of them will always be negative
            if(umap[c] >= 0) count--;

            while(count == 0){
                if((i - left + 1) < len){
                    start = left;
                    len = i - start + 1;
                }
                char c = s[left];
                umap[c]++;
                // only add count back when a value > 0, consider "aaab" & "aab"
                if(umap[c] > 0){
                    count++;
                }
                left++;
            }
        }
        return len == INT_MAX? "" : s.substr(start, len);
    }
};
