# Uses python3
import sys

def get_change(m):
    '''
	The goal in this problem is to find the minimum number of coins needed to change the input value
	(an integer) into coins with denominations 1, 5, and 10.
    '''
    tens,therest = divmod(m,10)
    fives,more_therest = divmod(therest,5)

    return tens+fives+more_therest

if __name__ == '__main__':
    m = int(sys.stdin.read())
    #m=28
    print(get_change(m))
