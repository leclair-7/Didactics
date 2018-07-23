


def minRefills(x,n,L):
	numrefills = 0
	current_refill = 0

	while current_refill < n:
		last_refill = current_refill

		# if we're in array, and if the next step will work:
		while (current_refill < n) and (x[current_refill+1] - x[last_refill] <= L):
			print(current_refill, len(x), numrefills, x[current_refill+1] , x[last_refill])
			current_refill = current_refill + 1

			if current_refill + 1 == n:
				break	
		if current_refill == last_refill:
			return -1
		if current_refill <= n:
			numrefills += 1
		if current_refill + 1 == n:
				break
	return numrefills

x =[0,3,4,5,6,7,9,11]
n=len(x)
L = 3
print(minRefills(x,n,L))