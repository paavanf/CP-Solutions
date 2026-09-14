class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        if len(s)!=len(t):
            return False
        fq=[0]*26
        for ch in s:
            fq[ord(ch)-ord('a')]+=1
        for ch in t:
            idx=ord(ch)-ord('a')
            fq[idx]-=1
            if fq[idx]<0:
                return False
        return True