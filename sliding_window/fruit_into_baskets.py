# # 904. Fruit Into Baskets
# # medium

class Solution(object):
    def totalFruit(self, tree):
        """
        :type tree: List[int]
        :rtype: int
        """
        types = set()
        consecutive = 0
        
        max_fruit = 0
        counter = 0
        for i, tree_type in enumerate(tree):
            if len(types) < 2 or (tree_type in types):
                counter += 1
                types.add(tree_type)
            else:
                max_fruit = max(counter, max_fruit)
                counter = 1 + consecutive
                types = set([tree_type, tree[i - 1]])
            if i > 0 and tree_type == tree[i - 1]:
                consecutive += 1
            else:
                consecutive = 1
        max_fruit = max(max_fruit, counter)
        return max_fruit
