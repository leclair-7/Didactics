#Uses python3

import sys

def max_dot_product(a, b):
    #write your code here
    revenue = 0

    while len(a) > 0:

        maxa_index = a.index( max(a) )
        maxa = a[maxa_index]

        maxb_index = b.index( max(b) )
        maxb = b[maxb_index]
        
        del a[maxa_index]
        del b[maxb_index]
        revenue += ( maxa * maxb )

    return revenue

if __name__ == '__main__':    
    
    input = sys.stdin.read()
    data = list(map(int, input.split()))
    n = data[0]
    a = data[1:(n + 1)]
    b = data[(n + 1):]
    '''
    a = [23]
    b = [39]
    '''
    print(max_dot_product(a, b))
    
