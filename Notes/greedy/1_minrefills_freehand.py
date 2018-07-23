
def minRefills(x,n,L):
	current_pos =0
	numrefills =0
	lastrefill =0	

	while current_pos < n:
		lastrefill = current_pos
		
		while current_pos <n and (x[current_pos + 1] - x[lastrefill] <= L ):
			current_pos += 1
			if current_pos+1 == n-1:
				break

		if current_pos == lastrefill:
			return -1
		if current_pos+1 == n-1:
			break
		numrefills += 1

	return numrefills


x =[0,3,4,5,6,7,9,11]
n=len(x)
L = 3
print(minRefills(x,n,L))