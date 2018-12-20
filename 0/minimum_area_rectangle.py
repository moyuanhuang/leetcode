# 939. Minimum Area Rectangle
# medium

import sys
from collections import defaultdict

class Solution:
    def minAreaRect(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """

        length = len(points)
        allPoints = set()
        for pt in points:
            x, y = pt[0], pt[1]
            allPoints.add((x, y))

        minArea = sys.maxsize
        hasRectangle = False

        for i in range(length):
            for j in range(i + 1, length):
                x1, y1 = points[i][0], points[i][1]
                x2, y2 = points[j][0], points[j][1]

                if x1 == x2 or y1 == y2:
                    continue

                if (x1, y2) in allPoints and (x2, y1) in allPoints:
                    hasRectangle = True
                    minArea = min(minArea, abs(x1 - x2) * abs(y1 - y2))

        return minArea if hasRectangle else 0
