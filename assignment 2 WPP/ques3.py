# Function to count divisible digit positions
def count_divisible_positions(N):
    count = 0
    str_N = str(N)  # Convert number to string for digit extraction

    for digit in str_N:
        if digit != '0' and N % int(digit) == 0:
            count += 1

    return count

# Read number of test cases
T = int(input())

# Process each test case
for _ in range(T):
    N = int(input())
    print(count_divisible_positions(N))