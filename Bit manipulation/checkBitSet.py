"""
To check whether the m'th bit in an integer is set or not
"""

def checkBitSet(n, m):
        aux = 1 << (m-1)
        if (n & m):
            return True
        else:
            return False


#                                   ### Testcases ###
# print(checkBitSet(5,2))
# print(checkBitSet(5,3))
