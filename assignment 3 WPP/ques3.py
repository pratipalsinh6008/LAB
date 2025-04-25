def utopian_tree(n):
    height = 1  # Initial height of the tree
    for cycle in range(1, n + 1):
        if cycle % 2 == 1:  # Odd cycles (Monsoon) -> Double height
            height *= 2
        else:  # Even cycles (Summer) -> Increase by 1
            height += 1
    return height

# Read number of test cases
T = int(input())

# Process each test case
for _ in range(T):
    N = int(input())
    print(utopian_tree(N))