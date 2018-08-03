# Uses python3
import sys
from math import floor

def binary_search(a, x, low=0, high=None):
    if high is None:
        high = len(a)

    mid = int(floor( low + (high - low) / 2. ) )
    
    if low > high or mid >= len(a):
        return -1   

    if a[mid] == x:
        return mid

    elif a[mid] > x:
        return binary_search(a,x,low, mid-1)
    elif a[mid] < x:        
        return binary_search( a, x,mid+1,high )
    return -1


def linear_search(a, x):
    for i in range(len(a)):
        if a[i] == x:
            return i
    return -1

if __name__ == '__main__':
    
    input = sys.stdin.read()
    data = list(map(int, input.split()))
    n = data[0]
    m = data[n + 1]
    a = data[1 : n + 1]
    for x in data[n + 2:]:
        # replace with the call to binary_search when implemented
        print(binary_search(a, x), end = ' ')
    