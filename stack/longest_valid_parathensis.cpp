// leetcode 32. Longest Valid Parentheses
// HARD
// Use a stack to store invalid indexes, then the valid length is just the
// length between two invalid indexes!

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        for(int i = 0; i < s.size(); i++){
            char c = s[i];
            if(c == '('){
                st.push(i);
            } else {
                if(st.empty() or s[st.top()] == ')'){
                    st.push(i);
                } else {
                    st.pop();
                }
            }
        }
        if(st.empty())  return s.size();
        int right = s.size();
        int res = 0;
        while(!st.empty()){
            int left = st.top();
            st.pop();
            int length = right - left - 1;
            res = max(length, res);
            right = left;
        }
        return max(res, right);
    }
};
