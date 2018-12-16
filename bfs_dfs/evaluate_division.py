# 399. Evaluate Division
# medium

class Solution:
    def calcEquation(self, equations, values, queries):
        """
        :type equations: List[List[str]]
        :type values: List[float]
        :type queries: List[List[str]]
        :rtype: List[float]
        """
        pairs = {}
        for i, eq in enumerate(equations):
            a, b = eq[0], eq[1]
            value = values[i]
            pairs[(a,a)] = 1.0
            pairs[(b,b)] = 1.0
            pairs[(a,b)] = value
            pairs[(b,a)] = 1 / value

        visited = set()
        result = []

        def helper(denom, numer, value):
            # print(denom, numer)
            if (denom, numer) in pairs:
                value *= pairs[(denom, numer)]
                result.append(value)
                return True

            for eq, v in pairs.items():
                a, b = eq[0], eq[1]
                if denom != a or b in visited:
                    continue

                visited.add(b)
                found = helper(b, numer, value * v)
                if found:
                    return True
                visited.remove(b)

            return False

        for query in queries:
            x, y = query[0], query[1]
            visited = set()

            found = helper(x, y, 1)
            if not found:
                result.append(-1.0)

        return result
