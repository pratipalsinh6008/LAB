'''You are a student in a class of 10. Your class teacher assigns you a task of entering the
names of all the students in the class. You finally want to display the names given the
condition that the maximum allowed characters in a name is 15. As a fun task, reverse the
names and display them. [Hint: Slicing works when you are selecting maximum characters]'''
names = []
print("Enter the names of 10 students (max 15 characters):")

for i in range(10):
    while True:
        name = input(f"Student {i + 1}: ")
        if len(name) <= 15:
            names.append(name)
            break
        else:
            print("cannot exceed 15 characters")

reversed_names = []
for name in names:
    reversed_names.append(name[::-1])

print("\nReversed names of the students:")
for i in range(10):
    print(f"Student {i + 1}: {reversed_names[i]}")
