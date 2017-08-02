class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
      int size = input.size();
      if(size == 0) return vector<int>();
      vector<int> res;
      for(int i = 1; i < size; i++){
        char op = input[i];
        if( op == '+' or op == '-' or op == '*'){
          vector<int> res1 = diffWaysToCompute(input.substr(0, i));
          vector<int> res2 = diffWaysToCompute(input.substr(i + 1));
          for(int n1 : res1){
            for(int n2 : res2){
              if(op == '+')
                res.push_back(n1 + n2);
              else if(op == '-')
                res.push_back(n1 - n2);
              else
                res.push_back(n1 * n2);
            }
          }
        }
      }
      if(res.empty())
        res.push_back(stoi(input));
      return res;
    }
};
