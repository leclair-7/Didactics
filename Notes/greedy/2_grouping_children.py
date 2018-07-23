

def pointsCoveredSorted(x):
	R = []

	i=0
	#i points to leftmost thing in the set
	n=len(x)
	while i < n:
		l,r = x[i], x[i] + 1

		r_small = [l,r]

		R.append(r_small)

		i += 1

		while i < n and x[i] <= r:
			i += 1
	return len(R)

x = [1,2,2,3,5,5,6,7,7,7,7,7,7]
print(pointsCoveredSorted(x))
