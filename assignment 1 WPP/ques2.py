'''2. Write a program that generates 100 random integers that are either 0 or 1. Then find the
longest run of zeros, the largest number of zeros in a row. For instance, the longest run of
zeros in [1,0,1,1,0,0,0,0,1,0,0] is 4.'''

import random

# Step 1: Generate 100 random integers (either 0 or 1)
my_list = [random.randint(0, 1) for _ in range(100)]
print(my_list)

# Step 2: Initialize variables
count = 0  # To count consecutive zeros
longest_run = 0  # To store the longest run of zeros

# Step 3: Iterate through the list and find the longest run of zeros
for num in my_list:
    if num == 0:
        count += 1  # Increase count if it's zero
    else:
        # If we encounter a 1, update the longest run and reset the count
        longest_run = max(longest_run, count)
        count = 0  # Reset the count for the next sequence of zeros

# Final check in case the longest run ends at the end of the list
longest_run = max(longest_run, count)

# Step 4: Print the longest run of zeros
print(f"The longest run of zeros is: {longest_run}")


