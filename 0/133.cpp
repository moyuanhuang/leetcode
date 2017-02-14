/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node)
	{
		unordered_map<int, UndirectedGraphNode*> newed;
		return helper(node, newed);
	}

	UndirectedGraphNode* helper(UndirectedGraphNode* old, unordered_map<int, UndirectedGraphNode*>& newed)
	{
		if(old->neighbors.empty())	return;
		UndirectedGraphNode* root = new UndirectedGraphNode(old->label);
		newed[root->label] = root;
		for(auto n: old->neighbors)
		{
			auto it = newed->find(n->label)
			if(it == newed.end())
				root->neighbors.push_back(helper(it, newed));
			else
				root->neighbors.push_back(it->second);
		}
		return root;
	}

};