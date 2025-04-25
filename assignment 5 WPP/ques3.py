def next_lexicographical_permutation(w):
    # Convert string to list for easier manipulation
    w = list(w)
    
    # Step 1: Find the pivot
    n = len(w)
    i = n - 2
    while i >= 0 and w[i] >= w[i + 1]:
        i -= 1
    
    if i == -1:
        return "no answer"
    
    # Step 2: Find the smallest character on the right of w[i] that is greater than w[i]
    j = n - 1
    while w[j] <= w[i]:
        j -= 1
    
    # Step 3: Swap characters at i and j
    w[i], w[j] = w[j], w[i]
    
    # Step 4: Reverse the suffix starting at i+1
    w = w[:i+1] + w[i+1:][::-1]
    
    return ''.join(w)

# Taking user input
t = int(input())
for _ in range(t):
    w = input()
    print(next_lexicographical_permutation(w))