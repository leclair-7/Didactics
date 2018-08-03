# Uses python3
import sys
import random

def partition3(a, l, r):   

    i=l    
    less_than,greater_than = l,r
    x = a[l]

    while i <= greater_than:
        if a[i] < x:
            a[less_than], a[i] = a[i], a[less_than]
            less_than += 1
            i += 1
        elif a[i] > x:
            a[i], a[greater_than] = a[greater_than], a[i]
            greater_than -= 1
        else:
            i += 1
    return less_than, greater_than 




def randomized_quick_sort(a, l, r):
    if l >= r:
        return
    k = random.randint(l, r)
    a[l], a[k] = a[k], a[l]
    #use partition3
    m,k = partition3(a, l, r)
    randomized_quick_sort(a, l, m - 1);
    randomized_quick_sort(a, k+1, r);


if __name__ == '__main__':
    input = sys.stdin.read()
    n, *a = list(map(int, input.split()))
    randomized_quick_sort(a, 0, n - 1)
    for x in a:
        print(x, end=' ')
    '''
    #a = [2,3,9,4,5,6,7,8,7,6,5,4,2,2,]
    #a = [2, 2, 2, 6, 5, 6, 5, 3, 7, 9, 8]
    #randomized_quick_sort(a,0,len(a)-1)
    #print(a)
    
    #u,v = partition3(a)

    '''

    

    