'''3. Write a program that asks the user to enter a length in feet. The program should then give
the user the option to convert from feet into inches, yards, miles, millimeters, centimeters,
meters, or kilometers. Say if the user enters a 1, then the program converts to inches, if they
enter a 2, then the program converts to yards, etc. While this can be done with if statements,
it is much shorter with lists and it is also easier to add new conversions if you use lists.'''

# Conversion factors (1 foot = ...)
conversion_factors = {
    "inches": 12,               # 1 foot = 12 inches
    "yards": 1 / 3,             # 1 foot = 1/3 yard
    "miles": 1 / 5280,          # 1 foot = 1/5280 mile
    "millimeters": 304.8,       # 1 foot = 304.8 millimeters
    "centimeters": 30.48,       # 1 foot = 30.48 centimeters
    "meters": 0.3048,           # 1 foot = 0.3048 meters
    "kilometers": 0.0003048     # 1 foot = 0.0003048 kilometers
}

# Ask the user for input
length_in_feet = float(input("Enter a length in feet: "))
print("\nChoose a conversion option:")
print("1. Convert to inches")
print("2. Convert to yards")
print("3. Convert to miles")
print("4. Convert to millimeters")
print("5. Convert to centimeters")
print("6. Convert to meters")
print("7. Convert to kilometers")

# Get the user's choice
choice = int(input("\nEnter the number corresponding to your choice: "))

# Perform the conversion using if-elif-else
if choice == 1:
    converted_length = length_in_feet * conversion_factors["inches"]
    unit = "inches"
elif choice == 2:
    converted_length = length_in_feet * conversion_factors["yards"]
    unit = "yards"
elif choice == 3:
    converted_length = length_in_feet * conversion_factors["miles"]
    unit = "miles"
elif choice == 4:
    converted_length = length_in_feet * conversion_factors["millimeters"]
    unit = "millimeters"
elif choice == 5:
    converted_length = length_in_feet * conversion_factors["centimeters"]
    unit = "centimeters"
elif choice == 6:
    converted_length = length_in_feet * conversion_factors["meters"]
    unit = "meters"
elif choice == 7:
    converted_length = length_in_feet * conversion_factors["kilometers"]
    unit = "kilometers"
else:
    print("\nInvalid choice. Please run the program again and select a valid option.")
    exit()

# Output the result
print(f"\n{length_in_feet} feet is equal to {converted_length:.2f} {unit}.")
