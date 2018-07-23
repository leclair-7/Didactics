# Uses python3
import sys

def get_optimal_value(capacity, weights, values):
    value = 0.
    # write your code here
    remaining_capacity = capacity

    while remaining_capacity > 0:
        vtow = []
        for i in range(len(values)):
            vtow.append(values[i]/weights[i])
        if len(vtow)==0:
            break
        curr_item = vtow.index( max(vtow) )
        #print(vtow,  remaining_capacity, curr_item)
        # check if remaiini capa is enough
        if remaining_capacity - weights[curr_item] >= 0:
            #print("this")
            value += values[curr_item]
            remaining_capacity -= weights[curr_item]
        else:
            value += values[curr_item] * (float(remaining_capacity)/weights[curr_item])
            remaining_capacity -= remaining_capacity
        
        del weights[curr_item]
        del values[curr_item]

        #print(weights)
    return value

if __name__ == "__main__":
    
    data = list(map(int, sys.stdin.read().split()))
    n, capacity = data[0:2]
    values = data[2:(2 * n + 2):2]
    weights = data[3:(2 * n + 2):2]
    
    '''
        
    n =1
    capacity = 1000
    values =[500]
    weights = [30]    
    '''
    
    opt_value = get_optimal_value(capacity, weights, values)
    print("{:.10f}".format(opt_value))
