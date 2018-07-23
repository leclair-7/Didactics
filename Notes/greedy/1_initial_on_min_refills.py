
def minRefills(x,n,L):

	current_pos =0
	numrefills =0
	lastrefill =0	

	while current_pos < n:

		lastrefill = current_pos

		while (x[current_pos + 1] - x[lastrefill] <= L ):

			current_pos += 1

			if current_pos+1 == n:
				break
		if current_pos > lastrefill:
			print(current_pos, lastrefill)
			numrefills += 1
		if current_pos == lastrefill:
			print("Yeah dude, not gonna work")
			return -1
		
		if current_pos+1 == n:
			break


	return numrefills


x =[0,3,4,5,6,7,9,11,12,13]
n=len(x)
L = 3
print(minRefills(x,n,L))