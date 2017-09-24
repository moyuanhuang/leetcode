// sort() will sort the vector in ascending order as default
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
      vector<int> count(26, 0);
      for(char t : tasks)
        count[t - 'A']++;
      sort(count.begin(), count.end());
      int i = 25;
      while(i >= 0 and count[i] == count[25]) --i;
      // the 25 - i is the additional repeated chunck starter
      // see here http://www.cnblogs.com/grandyang/p/7098764.html
      return max(int(tasks.size()), (count[25] - 1) * (n + 1) + 25 - i);
    }
};

// priority queue can also work
