# Uses python3

from pprint import pprint

def edit_distance(A,B):
    D = [[999 for j in range(len(B)+1)] for i in range(len(A)+1)]
    
    D[0][0] = 0

    for i in range(1,len(B)+1):
        D[0][i] = i
    for i in range(1,len(A)+1):
        D[i][0] = i
    #pprint(D)
    #return 
    #D[0][0] = 1
    for j in range(1, len(B)+1):
        for i in range(1, len(A)+1):
            
            insertion = D[i][j-1] + 1 
            deletion  = D[i-1][j] + 1
            match     = D[i-1][j-1]
            mismatch  = D[i-1][j-1] + 1

            indel = max(insertion, deletion)

            if A[i-1] == B[j-1]:                
                D[i][j] = min(insertion, deletion, match) 
            else:                
                D[i][j] = min(insertion, deletion, mismatch)
    #pprint(D)
    return D[len(A)][len(B)]

'''
short
ports 
should be 3

'''
if __name__ == "__main__":
    print(edit_distance(input(), input()))
    #print(edit_distance("editing","distance"))
