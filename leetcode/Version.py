#!/bin/python

class Solution:
    # @param {string} version1
    # @param {string} version2
    # @return {integer}
    def compareVersion(self, version1, version2):
    	v1 = version1.split('.')
    	v2 = version2.split('.')
    	l1 = len(v1)
    	l2 = len(v2)
    	l = max(l1,l2)
    	for i in range(l):
    		if i < l1:
    			n1 = int(v1[i])
    		else:
    			n1 = 0
    		if i < l2:
    			n2 = int(v2[i])
    		else:
    			n2 = 0
    		if n1 > n2:
    			return 1
    		elif n1 < n2:
    			return -1

    	return 0

sol = Solution()
n = sol.compareVersion("3.2.12","3.2")
print n
