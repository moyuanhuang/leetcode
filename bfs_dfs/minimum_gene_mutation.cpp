// leetcode 433. minimum genetic mutation
// USE BFS!!

class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
      unordered_set<string> dict(bank.begin(), bank.end());
      queue<string> to_visit;
      to_visit.push(start);
      int ret = 0;
      while(!to_visit.empty()){
        int size = to_visit.size();
        for(int i = 0; i < size; ++i){
          string gene = to_visit.front();
          to_visit.pop();
          if(gene == end) return ret;
          find_mutation(gene, dict, to_visit);
        }
        ret++;
      }
      return -1;
    }

private:
  void find_mutation(string gene, unordered_set<string>& dict, queue<string>& to_visit){
    dict.erase(gene);
    char genes[4] = {'A', 'C', 'G', 'T'};
    for(int i = 0; i < gene.size(); ++i){
      char letter = gene[i];
      for(int j = 0; j < 4; ++j){
        if(letter == genes[j])  continue;
        gene[i] = genes[j];
        if(dict.count(gene)){
          to_visit.push(gene);
          dict.erase(gene);
        }
      }
      gene[i] = letter;
    }
  }
};
