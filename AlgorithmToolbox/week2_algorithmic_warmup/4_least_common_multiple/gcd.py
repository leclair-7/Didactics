# Uses python3
import sys
'''
We're going to get least common multiple

gcd a b ==> d s.t. a|d and b|d
'''
def gcd_euclid(a, b):
    
    if b==0:
    	return a
    
    a_prime = a % b

    return gcd_euclid(b,a_prime)

a,b = 28851538, 1183019
gc = gcd_euclid(a, b)
print(a * (b//gc)  )

a,b = 6,8
gc = gcd_euclid(a, b)
print(a * (b//gc)  )
