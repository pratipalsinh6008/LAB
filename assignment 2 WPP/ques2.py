# Initialize an empty dictionary to store products and prices
products = {}

# Get product names and prices from the user
while True:
    name = input("Enter product name (or 'done' to stop): ")
    if name.lower() == 'done':
        break
    price = input(f"Enter price for {name}: ")
    
    # Try converting price to a float
    try:
        products[name] = float(price)
    except ValueError:
        print("Invalid price! Please enter a numeric value.")

# Look up product prices
while True:
    lookup = input("Enter a product name to look up (or 'exit' to quit): ")
    if lookup.lower() == 'exit':
        break
    if lookup in products:
        print(f"The price of {lookup} is ${products[lookup]:.2f}")
    else:
        print("Product not found.")