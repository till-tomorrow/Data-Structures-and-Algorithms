"""
Brian Kerninghan - Count the number of set bits in an integer
Time Complexity - O(log n)
Key idea: n & (n-1)
"""

def brianKerninghan(n):
    count = 0
    while (n):
        n = n & (n-1)
        count += 1
    return count


#                               ### Testcases ###
# print(brianKerninghan(7))
# print(brianKerninghan(1024))
