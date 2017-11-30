// Leetcide 406. Queue Reconstruction by Height
// LET THE LARGER HEIGHTS PUSHED BACK FIRST

struct cmp{
  bool operator()(pair<int, int> a, pair<int, int> b){
    if(a.first != b.first)  return a.first < b.first;
    else  return a.second > b.second;
  }
};

class Solution {
public:
  vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
    vector<pair<int, int> > ret;
    priority_queue<pair<int, int>, vector<pair<int, int> >, cmp> pq(people.begin(), people.end());
    while(!pq.empty()){
      pair<int, int> tmp = pq.top();
        cout << "[" << tmp.first << "," << tmp.second << "]" << endl;
      pq.pop();
      ret.insert(people.begin() + tmp.second, tmp);
    }
    return ret;
  }
};
