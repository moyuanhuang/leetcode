# 785. Is Graph Bipartite?
# medium

class Solution(object):
    def isBipartite(self, graph):
        """
        :type graph: List[List[int]]
        :rtype: bool
        """
        color = {}
        def helper(a):
            for b in graph[a]:
                if b in color:
                    if color[b] == color[a]:
                        return False
                else:
                    color[b] = 1 - color[a]
                    valid = helper(b)
                    if not valid:
                        return False
                return True

            for a in graph:
                if a in color:
                    continue
                else:
                    color[a] = 0
                    valid = helper(a)
                    if not valid:
                        return False
            return True
