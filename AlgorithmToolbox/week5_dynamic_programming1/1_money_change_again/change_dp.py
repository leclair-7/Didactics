# Uses python3
import sys

def get_change(m):
    '''
	input: m - quantity with which to make change

	gets the minimum number of coins to make change
	with 1, 3, 4

	this only works if 
    '''

    coins = [1, 3, 4]
    arr = [i for i in range(m + 1)]
    arr[0] = 0

    for i in range(len(arr)):
    	for c in range(len(coins)):
    		if i- coins[c] >= 0:
	    		if arr[i- coins[c]] + 1 < arr[i]:
	    			arr[i] = arr[i-coins[c]] + 1 
    return arr[-1]

if __name__ == '__main__':
    m = int(sys.stdin.read())
    print(get_change(m))
    '''
    m = 34
    print("The min number of coins for {} is {}".format(m, get_change(m)) )
    m = 2
    print("The min number of coins for {} is {}".format(m, get_change(m)) )
    m = 15
    print("The min number of coins for {} is {}".format(m, get_change(m)) )
	'''