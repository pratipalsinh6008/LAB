def  digital_root(n):
    while n >= 10:  # Keep looping until n is a single digit
        n = sum(int(digit) for digit in str(n))  # Convert number to string, sum up its digits
    return n

# Taking user input
num = int(input("Enter a number: "))
print("Digital Root:", digital_root(num))