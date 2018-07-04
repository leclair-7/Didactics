# Uses python3
def calc_fib(n):
    if (n <= 1):
        return n
    a,b = 0,1
    for i in range(n):
    	b,a = b+a,b
    return a

n = int(input())
print(calc_fib(n))
'''
for i in range(10):
	print(calc_fib(i))
'''