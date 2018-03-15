// 647. Palindromic Substrings
// medium
// traverse every i as center, try to enlarge it

class Solution {
public:
    int countSubstrings(string s) {
        if(s.empty())   return 0;
        count = 0;
        for(int i = 0; i < s.size(); i++){
            extendPal(s, i, i);
            extendPal(s, i, i + 1);
        }
        return count;
    }

private:
    int count;
    void extendPal(string& s, int left, int right){
        while(left >= 0 and right < s.size() and s[left] == s[right]){
            count++;
            left--;
            right++;
        }
    }
};
