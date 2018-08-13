# Uses python3
def edit_distance(A,B):
    D = [[999 for j in range(len(B))] for i in range(len(A))]

    #print(len(D[0]))
    for i in range(len(B)):
        D[0][i] = i
    for i in range(len(A)):
        D[i][0] = i
    #pprint(D)

    for j in range(1, len(B)):
        for i in range(1, len(A)):
            insertion = D[i][j-1] + 1 
            deletion  = D[i-1][j] + 1
            match     = D[i-1][j-1]
            mismatch  = D[i-1][j-1] + 1
            if A[i] == B[j]:
                D[i][j] = min(insertion, deletion, match) 
            else:
                D[i][j] = min(insertion, deletion, mismatch)
    return D[len(A)-1][len(B)-1]

if __name__ == "__main__":
    #print(edit_distance(input(), input()))
    print(edit_distance("short","ports"))
