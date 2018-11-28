# 261. Graph Valid Tree
# medium

from collections import defaultdict

class Solution:
    def validTree(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: bool
        """
        # corner cases
        if len(edges) == 0:
            return True

        # construct children as if the graph is a tree
        children = defaultdict(set)
        for edge in edges:
            a, b = edge[1], edge[2]
            children[a].add(b)
            children[b].add(a)

        visited = set()

        def check_successor(parent, node):
            visited.add(node)
            for succ in children[node]:
                if succ == parent:
                    continue
                if succ in visited:
                    return False

                valid = check_successor(node, succ)

                if not valid:
                    return False
                return True

        return check_successor(-1, 0)

