class TrieNode{
public:
	isKey;
	vector<TrieNode*> children;
	TrieNode(): isKey(false){
		children = vector<TrieNode*> (26,NULL);
	}

}
class WordDictionary {
public:
	WordDictionary()
	{
        root = new TrieNode();
    }
    // Adds a word into the data structure.
	void addWord(string word)
	{
		TrieNode* tmp = root;
		for(int i =0; i < word.length();i++)
		{
			int idx = word[i] - 'a';
			if(tmp->children[idx] == NULL)
				tmp->children[idx] = new TrieNode();
			tmp = tmp->children[idx];
		}
		tmp->isKey = true;
		return;
	}

	// Returns if the word is in the data structure. A word could
	// contain the dot character '.' to represent any one letter.
	bool search(string word)
	{
		return helper(word, 0, root);
	}
private:
	TrieNode* root;
	bool helper(string& word, int idx, TrieNode* cur)
	{
		TrieNode* tmp = cur;
		for(int i = idx; i < word.length(); i++)
		{
			if(tmp and word[i] != '.')
				tmp = tmp->children[word[i] - 'a'];
			else if(tmp and word[i] == '.')
			{
				for(auto node : tmp->children)
				{
					if(helper(word, i+1, node))
						return true;
				}
			}
			else
				break;
		}
		return tmp and tmp->isKey;
	}
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");