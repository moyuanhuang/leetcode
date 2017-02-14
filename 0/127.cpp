class Solution {
public:
	int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList)
	{
		int min_cnt = 0;
		helper(beginWord, endWord, wordList, min_cnt, 0);
		return min_cnt;
	}

	void helper(string& beginWord, string &endWord, unordered_set<string>& wordList, int& min_cnt, int cur)
	{
		if(beginWord == endWord)
		{
			min_cnt = min_cnt > cur ? min_cnt: cur;
			return;
		}
		for(int i = 0; i < beginWord.length(); i++)
		{
			char tmp = beginWord[i];
			for(int j = 0; j < 26; j++)
			{
				beginWord[i] = 'a' + j;
				if((iterator<unordered_Set<string>> iter = wordList.find(beginWord)) != wordList.end())
				{
					wordList.erase(iter);
					helper(beginWord, endWord, wordList, min_cnt, cur+1);
					wordList.insert(beginWord);
				}
			}
			beginWord[i] = tmp;
		}
		return;
	}
};