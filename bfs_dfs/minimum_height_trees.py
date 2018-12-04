# Minimum Height Trees
# medium

from collections import defaultdict

class Solution:
    def findMinHeightTrees(self, n, edges_):
        """
        :type n: int
        :type edges_: List[List[int]]
        :rtype: List[int]
        """
        # corner case: n = 1, edges = []
        if n <= 1:
            return [0]
            
        # construct graph
        edges = defaultdict(set)
        for edge in edges_:
            a, b = edge[0], edge[1]
            edges[a].add(b)
            edges[b].add(a)

        # find all leave nodes
        leaves = [node for node in edges if len(edges[node]) == 1]

        # KENG: use n to guard the loop!! 
        while n > 2:
            n -= len(leaves)
            new_leaves = []

            while leaves:
                node = leaves.pop(0)
                for j in edges[node]:
                    edges[j].remove(node)
                    if len(edges[j]) == 1:
                        new_leaves.append(j)
            leaves = new_leaves

        return leaves

    # classic BFS
    def findMinHeightTrees_(self, n, edges_):
        """
        :type n: int
        :type edges_: List[List[int]]
        :rtype: List[int]
        """
        # corner case
        if n == 0 or n == 1:
            return [0]

        edges = defaultdict(set)
        for edge in edges_:
            a, b = edge[0], edge[1]
            edges[a].add(b)
            edges[b].add(a)

        min_height = n - 1
        heights = defaultdict(list)

        for starter in range(n):
            stack = [starter]
            visited = set()
            height = 0

            while stack:
                n_elem = len(stack)
                for _ in range(n_elem):
                    a = stack.pop(0)
                    visited.add(a)

                    for b in edges[a]:
                        if b in visited:
                            continue
                        stack.append(b)

                height += 1
            # print("Start node: %d, height: %d" % (starter, height))
            heights[height - 1].append(starter)
            min_height = min(min_height, height - 1)

        return heights[min_height]
