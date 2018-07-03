# Uses python3
import sys

def get_fibonacci_last_digit_naive(n):
    if n <= 1:
        return n

    a = 0
    b  = 1

    for _ in range(n - 1):
        a,b = (a + b)%10, (b)%10

    return a

if __name__ == '__main__':
    input = sys.stdin.read()
    n = int(input)
    print(get_fibonacci_last_digit_naive(n))
