# 149. Max Points on a Line
# hard

# Definition for a point.
# class Point:
#     def __init__(self, a=0, b=0):
#         self.x = a
#         self.y = b

class Solution:
    def maxPoints(self, points):
        """
        :type points: List[Point]
        :rtype: int
        """
    
        def gcd(a, b):
            if b == 0:
                return a
            return gcd(b, a % b)

        res = 0
        cnt = collections.Counter()
        
        for i in range(len(points)):
            cnt.clear()
            pmax, overlap = 0, 0
            for j in range(i + 1, len(points)):
                x = points[i].x - points[j].x
                y = points[i].y - points[j].y
                
                if x == 0 and y == 0:
                    overlap += 1
                    continue
                    
                div = gcd(x, y)
                x = x // div
                y = y // div
                
                key = str(x) + '/' + str(y)
                print(x, y, key)
                cnt[key] += 1
                pmax = max(pmax, cnt[key])
            res = max(res, pmax + overlap + 1)
            
        return res
