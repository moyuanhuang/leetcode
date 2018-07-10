class Solution:
    def minWindow(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """

        char_cnt = {}
        for ch in t:
            cnt = char_cnt.get(ch, 0)
            char_cnt[ch] = cnt + 1
        left = 0
        right = 0
        res = ""
        shortest = sys.maxsize
        for i in range(len(s)):
            ch = s[i]
            if ch in char_cnt:    
                char_cnt[ch] -= 1
                if s[left] == ch or not s[left] in char_cnt:
                    for j in range(left, i):
                        if not s[j] in char_cnt:
                            left += 1
                        elif s[j] in char_cnt and char_cnt[s[j]] < 0:
                            char_cnt[s[j]] += 1
                            left += 1
                        else:
                            break
                valid = True
                for key in char_cnt:
                    if char_cnt[key] > 0:
                        valid = False
                        break
                if valid:
                    right = i
                    temp = right - left + 1
                    if temp < shortest:
                        res = s[left: right + 1]
                        shortest = temp
        return res

