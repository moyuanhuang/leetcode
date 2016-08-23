class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map charIndex;
        int start = -1;
        int maxlen = 0;
        for(int i =0; i < s.length(); i++)
        {
            if(charIndex.count(s[i])!=0)
            {
                start = max(start, charIndex[s[i]]);
            }
            charIndex[s[i]] = i;
            maxlen = max(maxlen, i-start);
        }
    }
};