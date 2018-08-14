
def swap(arr, indexa,indexb):
	st = arr[indexa]
	fi = arr[indexb]
	arr[indexa] = fi
	arr[indexb] = st

def selectionSort(a):
	for i in range(len(a)):

		minindex = i
		for j in range(i+1,len(a)):
			if a[j] < a[minindex]:
				minindex = j
		#swap minindex
		swap(a,i,minindex)
		'''
		st = a[i]
		fi = a[minindex]
		a[i] = fi
		a[minindex] = st
		'''

def merge(B,C):
	D = [0]*(len(B)+len(C))

	nextelem = 0
	while len(B)>0 and len(C) > 0:
		b = B[0]
		c = C[0]
		if b <= c:
			b = B.pop(0)
			D[nextelem] = b
		else:
			c = C.pop(0)
			D[nextelem] = c
		nextelem += 1
	if len(B)>0:
		for i in B:
			D[nextelem] = i
			nextelem += 1
	if len(C)>0:
		for i in C:
			D[nextelem] = i
			nextelem += 1
	return D

def mergeSort(a):

	if len(a)==1:
		return a
	m = len(a)//2
	B = mergeSort(a[ : m ])
	C = mergeSort(a[ m : ])

	a_prime = merge(B,C)

	return a_prime

def partition(a,l,r):
	'''
	input array a,
	left index
	right index

	works on indices [ l, r )

	returns j such that a[0..j] <= a[l]
					and a[j+1..end] > a[l]
	'''
	pivot = a[l]	
	#j is index of the last element <= pivot
	j = l

	for i in range(l + 1, r):
		if a[i] <= pivot:
			j += 1
			swap(a,j,i)
	swap(a,l,j)
	return j		


def quickSort(a,l,r):
	# sorts from indices [l,r)
	if l >= r:
		return
	m = partition(a,l,r)
	#at this point A[m] is in the final position
	quickSort(a, l  , m )
	quickSort(a, m+1, r )


a = []
for i in range(10,0,-1):
	a.append(i)

#selectionSort(a)
a = mergeSort(a)
#print(a)


#s =[ 6,4,8,2,9,3,9,4,7,6,1]
t = [6,4,3,8,3,9,3]
quickSort(t,0,len(t))


print(t)

