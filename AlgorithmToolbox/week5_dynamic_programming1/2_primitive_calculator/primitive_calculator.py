# Uses python3
import sys

def optimal_sequence(n):
    sequence = []

    arr = [ i-1 for i in range(n+1) ]

    index = 0
    for i in range(n+1):
        addone = -1
        mul2   = -1
        mul3   = -1

        if i * 3 <= n:
            mul3 = i * 3
            if arr[i] + 1 < arr[mul3]:
                arr[mul3] = arr[i] + 1

        if i * 2 <= n:
            mul2 = i * 2
            if arr[i] + 1 < arr[mul2]:
                arr[mul2] = arr[i] + 1

        if i + 1 <= n:
            addone = i + 1
            if arr[i] + 1 < arr[addone]:
                arr[addone] = arr[i] + 1
    sequence = [n]
    while n >= 1:
        
        subone = -1
        div2   = -1
        div3   = -1
        #it's not quite this, but this is sooo close, question is how is it related to coin change problem?
        #the next number is the min( arr[i//2], arr[i//3], arr[i-1] ), but only the ones that work
        div3 = n // 3 if n % 3 == 0 else 10**7
        div2 = n // 2 if n % 2 == 0 else 10**7
        subone = n - 1

        candidates = [i for i in [subone,div2,div3] if i != 10**7]
        #print(candidates)
        #thenextseq = min( candidates  )
        
        cans = []
        for i in candidates:
            cans.append(arr[i])

        n = candidates[cans.index(min(cans))]

        #print(n, candidates, cans)
        #print(arr)
        #n = thenextseq
        sequence.append( n )

    #print(arr[:15])
    sequence = sequence[:-1]
    return reversed(sequence)

input = sys.stdin.read()
n = int(input)
sequence = list(optimal_sequence(n))
print(len(sequence) - 1)
for x in sequence:
    print(x, end=' ')
'''
print(optimal_sequence(1))
'''