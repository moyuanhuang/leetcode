class Solution {
public:
	bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites)
	{
		vector<unordered_set<int>> graph = make_graph(numCourses, prerequisites);
		vector<int> indegree = compute_degree(graph);

		for(int i = 0; i < numCourses; i++)
		{
			int j = 0;
            for (; j < numCourses; j++)
                if (!indegree[j]) break;

			if(j == numCourses)	return false;
			indegree[j] = -1;
			for(int next: graph[j])
				indegree[next]--;

		}
		return true;
	}
private:
	vector<unordered_set<int>> make_graph(int n, vector<pair<int, int>>& prerequisites)
	{
		vector<unordered_set<int>> graph(n);
		for(auto p : prerequisites)
			graph[p.second].insert(p.first);
		return graph;
	}

	vector<int> compute_degree(vector<unordered_set<int>> graph)
	{
		vector<int> indegree(graph.size(), 0);
		for(auto p : graph)
		    for(int pre : p)
			    indegree[pre]++;
		return indegree;
	}
};