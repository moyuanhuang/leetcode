# 68. Text Justification
# hard

class Solution:
    def fullJustify(self, words, maxWidth):
        """
        :type words: List[str]
        :type maxWidth: int
        :rtype: List[str]
        """

        res = []
        temp = [words[0]]
        words_len = len(words[0])
        for w in words[1:]:
            if words_len + len(temp) + len(w) > maxWidth:
                white_spaces = maxWidth - words_len
                slot = len(temp) - 1

                line = temp.pop(0)[:]
                if slot == 0:
                    line += " " * (maxWidth - len(line))
                elif white_spaces % slot == 0:
                    chunk = white_spaces // slot
                    while temp:
                        line += " " * chunk + temp.pop(0)
                else:
                    first_round = white_spaces % slot
                    chunk = white_spaces // slot

                    for i in range(first_round):
                        line += " " * (chunk + 1) + temp.pop(0)
                    while temp:
                        line += " " * chunk + temp.pop(0)
                res.append(line)

                temp = [w]
                words_len = len(w)
            else:
                temp.append(w)
                words_len += len(w)
        res += [' '.join(temp).ljust(maxWidth)]
        return res 

