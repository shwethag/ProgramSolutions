#!/bin/python

class Solution:
    # @param s, a string
    # @return a string
    def reverseWords(self, s):
        if (len(s) == 0):
            s = ""
        else:
            slist = s.split()
            slist.reverse()
            s = ""
            for i in slist:
                s += i+" "
            s = s.strip()
        
        return s

sol = Solution()
y = sol.reverseWords("the sky is blue")
print y