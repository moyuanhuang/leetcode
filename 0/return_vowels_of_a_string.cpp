class Solution {
public:
  string reverseVowels(string s) {
    char vowels_[10] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    unordered_set<char> vowels;
    for(int i = 0; i < 10; i++){
      vowels.insert(vowels_[i]);
    }
    int l = 0, r = s.size();
    while(l < r){
        cout << l << " " << r << endl;
      while(l < r and vowels.count(s[l]) == 0) l++;
      while(r > l and vowels.count(s[r]) == 0) r--;
      swap(s[l], s[r]);
      l++;
      r--;
    }
    return s;
  }
};
