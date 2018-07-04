# Uses python3
import sys

def gcd_euclid(a, b):
    
    if b==0:
    	return a
    
    a_prime = a % b

    return gcd_euclid(b,a_prime)

def lcm_lucas(a, b):

	gc = gcd_euclid(a, b)

	result = max(a,b) * (min(a,b)//gc)
	return result

if __name__ == '__main__':
    input = sys.stdin.read()
    a, b = map(int, input.split())
    print(lcm_lucas(a, b))
'''
a,b = 28851538, 1183019
gc = lcm_lucas(a, b)
print(gc  )

a,b = 6,8
gc = lcm_lucas(a, b)
print(gc )
'''