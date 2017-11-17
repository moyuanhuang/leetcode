// class Solution {
// public:
//     int bulbSwitch(int n) {
//       for(int i = 1; i <= n; i++){
//         for(int j = 1; j <= n; ++j){
//           if(j % i == 0)
//             toggle(j);
//         }
//       }
//       return uset.size();
//     }
//
// private:
//     unordered_set<int> uset;
//
//     void toggle(int i){
//       auto it = uset.find(i);
//       if(it != uset.end()){
//         uset.erase(it);
//       }
//       else{
//         uset.insert(i);
//       }
//       return;
//     }
// };

class Solution {
public:
    int bulbSwitch(int n) {
      return sqrt(n);
    }
};
