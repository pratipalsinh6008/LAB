def max_xor(L, R):
    max_xor_value = 0  # Initialize maximum XOR value
    
    for A in range(L, R + 1):  # Loop through A
        for B in range(A, R + 1):  # Loop through B (A <= B)
            max_xor_value = max(max_xor_value, A ^ B)  # Compute XOR and update max
    
    return max_xor_value

# Taking user input
L = int(input("Enter L: "))
R = int(input("Enter R: "))

print("Maximum XOR value:", max_xor(L, R))