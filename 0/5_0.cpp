/*
 * 8. Longers Polindrome String
 * Created by Moyuan Huang on 8.23.2016
*/ 
 class Solution {
public:
    string longestPalindrome(string s)
    {
        if(s.empty())   return "";
        if(s.length()==1) return s;

        int start, end;
        int maxStart;
        int maxLen = 0;
        int i = 0;
        while(i < s.length())
        {
            if(s.length()-i< maxLen/2)
                break;
            start = i;
            end = i;
            // a little tricky here
            while(end + 1 < s.length() and s[end] == s[end+1])
                end++;
            i = end + 1;
            while( start > -1 and end < s.length() and s[start]==s[end])
            {
                end++;
                start--;
            }
            if(end-start-1 > maxLen)
            {
                maxLen = end-start-1;
                maxStart = start + 1;
            }
        }   
        return s.substr(maxStart, maxLen);
    }
};