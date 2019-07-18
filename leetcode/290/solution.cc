class Solution(object):
    
    def wordPattern(self, pattern, str):
        """
        :type pattern: str
        :type str: str
        :rtype: bool
        """
        str = str.split()
        if len(pattern) != len(str):
            return False
        p2s = {}
        s2p = {}
        for p, s in zip(pattern, str):
            if p in p2s and p2s[p] != s:
                return False
            if p not in p2s and s in s2p:
                return False
            p2s[p] = s
            s2p[s] = p
        return True
