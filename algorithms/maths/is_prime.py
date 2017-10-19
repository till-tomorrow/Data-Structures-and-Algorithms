import math

def is_prime(n) :
	if n == 1:
		return False
	if n == 2:
		return True
	if n%2 == 0:
		return False
	
	upto = int(math.sqrt(n))
	for i in range(3, upto+1, 2):
		if n%i == 0 :
			return False

	return True

#Tests
assert(is_prime(3) == True)
assert(is_prime(10) == False)
assert(is_prime(1297561) == True)