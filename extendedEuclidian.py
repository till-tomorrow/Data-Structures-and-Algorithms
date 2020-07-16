#Author: Rcsm89

'''
Euclidian Algorithm to Greatest Common Divisor
'''
def gcd(a, b):
    if(a%b == 0):
        return b
    else:
        return gcd(b, a%b)

'''
Extended Euclidian Algorithm to generate keys
'''
def extgcd(a, b):
    if (abs(a) >= abs(b)):
        if a % b == 0:
            v1 = [b, 0, 1]
            return v1
        else:
            q = a // b
            r = a % b
            D, s, t = extgcd(b, r)
            v2 = [D, t, s - t*q]
            return v2
    else:
        return extgcd(abs(b), abs(a))

def test():
    a = 57
    b = 1461501637330902918203684832716283019655932313743
    print ('gcd(a, b) = {}'.format(gcd(a, b)))
    v = extgcd(a, b)
    print ('D = {}, s = {}, t = {}'.format(v[0], v[1], v[2]))


test()
