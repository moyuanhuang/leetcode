# 332. Reconstruct Itinerary
# medium

from collections import defaultdict

class Solution:
    def findItinerary(self, tickets):
        """
        :type tickets: List[List[str]]
        :rtype: List[str]
        """
        paths = defaultdict(list)

        for ticket in tickets:
            departure, arrival = ticket[0], ticket[1]
            paths[departure].append(arrival)
            
        for destinations in paths.values():
            destinations.sort()

        self.route = []

        def helper(airport, current_route):
            if len(current_route) == len(tickets) + 1:
                self.route = current_route
                return True

            for i in range(len(paths[airport])):
                next_stop =  paths[airport].pop(i)
                found = helper(next_stop, current_route + [next_stop])

                if found:
                    return True

                paths[airport].insert(i, next_stop)

            return False

        helper('JFK', ['JFK'])
        return self.route
