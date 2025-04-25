'''4. Take numbers from 1 to 10000. Create equivalence classes for modulo 5 on this set of
numbers. Check the validity of your equivalence classes. [Hint: the union of all equivalence
classes should be the original set/list.]'''
numbers = list(range(1, 10001))

equivalence_classes = {i: [] for i in range(5)}
for number in numbers:
    equivalence_classes[number % 5].append(number)

union_of_classes = []
for eq_class in equivalence_classes.values():
    union_of_classes.extend(eq_class)

union_of_classes.sort()

is_valid = (union_of_classes == numbers)

print("Equivalence classes are valid:", is_valid)