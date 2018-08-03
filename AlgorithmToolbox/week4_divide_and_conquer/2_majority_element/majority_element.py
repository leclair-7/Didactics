# Uses python3
import sys
from math import floor

def majority(B,C):    
    if len(B)==1 and len(C) ==1:
        return B[0] if B[0]==C[0] else -1
    return -1

def get_majority_element(a, left=0, right=0):

    if left == right:
        return -1
    if left + 1 == right:
        return a[left]

    m = len(a)//2
    left_maj  = get_majority_element(a, left, int(floor((left + right )//2 )) )
    right_maj = get_majority_element(a, int(floor((left + right )//2 ) ), right)
    
    print(left_maj,right_maj)
    threshold = (right-left)//2
    left_c =0
    right_c =0
    for i in range(left,right):
        if a[i] == left_maj:
            left_c  += 1
        if a[i] == right_maj:
            right_c += 1
    if left_c > threshold:
        return left_c
    if right_c > threshold:
        return right_c   

    return 0
def getmagE2(a,left=0, right =0):
    dic = {}

    maxitem = 0
    for i in a:
        if i in dic:
            dic[i] += 1
            if dic[i] > maxitem:
                maxitem = dic[i]
        else:
            dic[i] =1
    if maxitem > len(a)//2:
        return 1
    else:
        return -1

if __name__ == '__main__':
    input = sys.stdin.read()
    n, *a = list(map(int, input.split()))
    if getmagE2(a, 0, n) != -1:
        print(1)
    else:
        print(0)
    '''

    n = 6
    a = [2,3,9,2,2,1]
    print(getmagE2(a, 0, n))
    '''

