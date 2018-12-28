# 489. Robot Room Cleaner
# hard

# """
# This is the robot's control interface.
# You should not implement it, or speculate about its implementation
# """
#class Robot(object):
#    def move(self):
#        """
#        Returns true if the cell in front is open and robot moves into the cell.
#        Returns false if the cell in front is blocked and robot stays in the current cell.
#        :rtype bool
#        """
#
#    def turnLeft(self):
#        """
#        Robot will stay in the same cell after calling turnLeft/turnRight.
#        Each turn will be 90 degrees.
#        :rtype void
#        """
#
#    def turnRight(self):
#        """
#        Robot will stay in the same cell after calling turnLeft/turnRight.
#        Each turn will be 90 degrees.
#        :rtype void
#        """
#
#    def clean(self):
#        """
#        Clean the current cell.
#        :rtype void
#        """

class Solution(object):
    def cleanRoom(self, robot):
        """
        :type robot: Robot
        :rtype: None
        """
        visited = set()

        def helper(robot, x, y, dirX, dirY):
            robot.clean()
            visited.add((x, y))

            for _ in range(4):
                nextX = x + dirX
                nextY = y + dirY
                if (nextX, nextY) not in visited and robot.move():
                    helper(robot, nextX, nextY, dirX, dirY)
                    robot.turnLeft()
                    robot.turnLeft()
                    robot.move()
                    robot.turnLeft()
                    robot.turnLeft()
                robot.turnLeft()
                dirX, dirY = -dirY, dirX

        helper(robot, 0, 0, 0, 1)
