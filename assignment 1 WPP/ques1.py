'''1. Create the following lists using a for loop.
(a) A list consisting of the integers 0 through 49
(b) A list containing the squares of the integers 1 through 50.
(c) The list ['a','bb','ccc','dddd', ...] that ends with 26 copies of the letter z.'''

#(a)
list=[]
for i in range(0,50):
    list.append(i+1)
    i=i+1
print(list)

#(b)
my_list = [(i) * (i) for i in range(51)] 
print(my_list)

#(c)
# Create the list of increasing length strings
initial_list = [chr(97 + i) * (i + 1) for i in range(26)]  
# Append 26 copies of the letter 'z'
final_list = initial_list + ['z'] * 26

# Output the result
print(final_list)

