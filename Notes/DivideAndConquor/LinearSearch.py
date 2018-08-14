
from math import floor

def LinearSearch(A, low, high, key):
	'''
	Maybe we should call this one a subtract and conquor

	'''
	#base case
	if high < low:
		return -1
	if A[low] == key:
		return low
	return LinearSearch(A, low+1, high, key)

a = [1,3,5,7,24,35,57,86]

#print(LinearSearch(a,0,len(a), 86))

def binarySearch(A,low,high,key):

	if high < low:
		return low - 1
	mid = floor( low + (  (high - low)/2. ) )
	mid = int(mid)
	if A[ mid ] == key:
		return mid
	elif A[mid] < key:
		return binarySearch(A,mid+1,high,key)
	elif A[mid] > key:
		return binarySearch(A, low, mid-1, key)

print(binarySearch(a,0,len(a), 87))
