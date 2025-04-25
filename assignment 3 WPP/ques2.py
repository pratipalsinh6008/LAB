import math

def is_perfect_square(x):
    """Check if x is a perfect square"""
    s = int(math.sqrt(x))
    return s * s == x

def is_fibonacci(n):
    """Check if n is a Fibonacci number using the mathematical property"""
    return is_perfect_square(5 * n * n + 4) or is_perfect_square(5 * n * n - 4)

# Read number of test cases
T = int(input())

# Process each test case
for _ in range(T):
    N = int(input())
    if is_fibonacci(N):
        print("IsFibo")
    else:
        print("IsNotFibo")