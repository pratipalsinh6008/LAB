import math

def count_squares(A, B):
    lower = math.ceil(math.sqrt(A))  # Smallest integer >= sqrt(A)
    upper = math.floor(math.sqrt(B))  # Largest integer <= sqrt(B)
    return max(0, upper - lower + 1)  # Count of perfect squares

# Taking user input
T = int(input("Enter the number of test cases: "))

for _ in range(T):
    A, B = map(int, input("Enter two space-separated integers (A B): ").split())
    print("Number of square integers:", count_squares(A, B))