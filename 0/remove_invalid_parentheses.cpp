class Solution {
public:
  vector<string> removeInvalidParentheses(string s) {
    int left = 0, right = 0;
    for(char c : s){
      if(c == '(')  ++left;
      else if(c == ')'){
        if(left != 0) --left;
        else  ++right;
      }
    }
    unordered_set<string> ret;
    helper(s, ret, "", 0, left, right, stack<char>());
    return vector<string>(ret.begin(), ret.end());
  }

private:
  void helper(const string& s, unordered_set<string>& ret, string path, int index, int left_to_remove, int right_to_remove, stack<char> st){
    if(index == s.size()){
      if(st.empty() and left_to_remove == 0 and right_to_remove == 0)
        ret.insert(path);
      return;
    }
    char c = s[index];

    ++index;
    if(c != '(' && c != ')')
      helper(s, ret, path + c, index, left_to_remove, right_to_remove, st);
    else if(c == '('){
      if(left_to_remove > 0)
        helper(s, ret, path, index, left_to_remove - 1, right_to_remove, st);
      st.push(c);
      helper(s, ret, path + c, index, left_to_remove, right_to_remove, st);
    }
    else if(c == ')'){
      if(right_to_remove > 0)
        helper(s, ret, path, index, left_to_remove, right_to_remove - 1, st);
      if(!st.empty()){
        st.pop();
        helper(s, ret, path + c, index, left_to_remove, right_to_remove, st);
      }
    }
    cout << endl;
    return;
  }
};
