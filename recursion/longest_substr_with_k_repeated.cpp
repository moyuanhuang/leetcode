// leetcode 395. Longest Substring with At Least K Repeating Characters
// medium
// looks like a sliding window, but is actually recursive!

class Solution {
public:
    int longestSubstring(string s, int k) {
        // cout << s << endl;
        int counts[26] = {0};
        for(char c : s){
            counts[c - 'a']++;
        }

        int mid = 0;
        while(mid < s.size()) {
            if(counts[s[mid] - 'a'] < k) break;
            mid++;
        }

        if(mid == s.size()) return s.size();

        int left = longestSubstring(s.substr(0, mid), k);
        int right = longestSubstring(s.substr(mid + 1), k);
        // cout << left << " " << right << endl;
        return max(left, right);
    }
};
