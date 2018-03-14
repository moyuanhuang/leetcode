// 389. Find the Difference
// easy
// time: O(nlogn), space: O(1) (we can also have O(n) time complexity,
// but use more space by using unordered_map )

class Solution {
public:
    char findTheDifference(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        for(int i = 0; i < s.size(); i++){
            if(s[i] != t[i]){
                return t[i];
            }
        }
        return t[t.size() - 1];
    }
};
