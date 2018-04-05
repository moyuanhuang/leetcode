// 318. Maximum Product of Word Lengths
// medium

class Solution {
public:
    int maxProduct(vector<string>& words) {
        int result = 0;
        for(int i = 0; i < words.size(); i++){
            int a = to_int(words[i]);
            for(int j = i + 1; j < words.size(); j++){
                int b = to_int(words[j]);
                if(!(a & b)){
                    result = max(result, int(words[i].size() * words[j].size()));
                }
            }
        }
        return result;
    }
private:
    int to_int(string word){
        int mask = 0;
        for(int i = 0; i < word.size(); i++){
            mask |= (1 << (word[i] - 'a'));
        }
        return mask;
    }
};
