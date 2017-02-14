class Solution {
public:
	vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites)
	{
		vector<unordered_set<int>> graph = make_graph(numCourses, prerequisites);
		vector<int> indeg = compute_degree(graph);
		vector<int> ans;
		// toposort using BFS
		queue<int> q;
		for(int i = 0; i < indeg.size(); i++)
			if(indeg[i] == 0)	q.push(i);
		for(int i = 0; i < numCourses; i++)
		{
			if(q.empty())	return {};
			int tmp = q.front();
			q.pop();
			ans.push_back(tmp);
// 			cout << tmp << endl;
			for(int child : graph[tmp])
			{
				indeg[child]--;
				if(indeg[child]==0)	q.push(child);
			}
		}
		return ans;
	}
private:
	vector<unordered_set<int>> make_graph(int n, vector<pair<int,int>> prerequisites)
	{
		vector<unordered_set<int>> graph(n);
		for(auto pre : prerequisites)
			graph[pre.second].insert(pre.first);
		return graph;
	}

	vector<int> compute_degree(vector<unordered_set<int>> graph)
	{
		vector<int> indeg(graph.size(), 0);
		for(auto course : graph)
			for(int child : course)
				indeg[child]++;
		return indeg;
	}
};