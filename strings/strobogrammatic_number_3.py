# 248. Strobogrammatic Number III
# hard

class Solution:
    def strobogrammaticInRange(self, low, high):
        """
        :type low: str
        :type high: str
        :rtype: int
        """
        self_sym = {
            '0': '0',
            '1': '1',
            '8': '8'
        }

        mapping = {
            '0': '0',
            '1': '1',
            '6': '9',
            '8': '8',
            '9': '6'
        }
        
        self.result = 0
        
        def my_toi(char_list):
            return int(''.join(char_list))

        def isValid(number):
            return number >= int(low) and number <= int(high)

        def helper(i, cur):
            if i == pivot:
                if n % 2 == 1:
                    for x in self_sym:
                        cur[i] = x
                        if isValid(my_toi(cur)):
                            self.result += 1
                else:
                    if isValid(my_toi(cur)):
                        self.result += 1
                return
            
            for x in mapping:
                if x == '0' and i == 0:
                    continue

                cur[i], cur[n - i - 1] = x, mapping[x]
                # trim search space
                if (n == len(low) and my_toi(cur[:i + 1]) < int(low[:i + 1])) or \
                    (n == len(high) and my_toi(cur[:i + 1]) > int(high[:i + 1])):
                    continue
                
                helper(i + 1, cur[:])


        for n in range(len(low), len(high) + 1):
            pivot = n // 2
            cur = ['0'] * n
            helper(0, cur)

        return self.result
