class Solution(object):
    def maxProduct(self, n):
        """
        :type n: int
        :rtype: int
        """
        arr=[]
        while n>0:
            k=n%10
            arr.append(k)
            n=n/10
        
        arr.sort()

        return arr[-1] * arr[-2]