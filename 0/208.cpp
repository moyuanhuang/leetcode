class TrieNode {
public:
	// Initialize your data structure here.
	TrieNode() {
		isKey = false;
		for(int i = 0; i < 26; i++)
			children[i] = NULL;
	}
};

class Trie {
public:
	bool isKey;
	vector<TrieNode*> children;

	Trie() {
		root = new TrieNode();
	}

	// Inserts a word into the trie.
	void insert(string word) {
		TrieNode* tmp = root;
		for(int i = 0; i < word.length(); i++)
		{
			int idx = word[i]-'a';
			if(tmp->children[idx] == NULL)
				tmp->children[idx] = new TrieNode();
			tmp = tmp->children[idx];
		}
		tmp->isKey = true;
	}

	// Returns if the word is in the trie.
	bool search(string word) {
		TrieNode* tmp = root;
		for(int i = 0; i < word.length(); i++)
		{
			int idx = word[i] - 'a';
			if(tmp->isKey)	return true;
			if(tmp->children[idx] == NULL)
				return false;
			tmp = tmp->children[idx];
		}
		return true;
	}

	// Returns if there is any word in the trie
	// that starts with the given prefix.
	bool startsWith(string prefix) {
		TrieNode* tmp = root;
		for(int i = 0; i < prefix.length(); i++)
		{
			int idx = prefix[i] - 'a';
			if(tmp->isKey)	return true;
			if(tmp->children[idx] == NULL)
				return false;
			tmp = tmp->children[idx];
		}
		return true;


	}

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");