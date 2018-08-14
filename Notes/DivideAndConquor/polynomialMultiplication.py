

def multPolyNaive(A,B,n):
	product = [0]*(2*n -1)
	#print(product)
	for i in range(len(A)):
		for j in range(len(B)):
			print(i,j)
			product[i+j] = product[i+j] + A[i] * B[j]
	return product
print(multPolyNaive([3,4],[1,2],2))







