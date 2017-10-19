"""
To check whether a number is divisible by powers of 2
"""

def checkTwoPower(n):
    if (not(n & n -1)):
        return True
    else:
        return False


#                               ### Testcases ###
# print(checkTwoPower(8))
# print(checkTwoPower(5))
# print(checkTwoPower(1))
