class Password_manager:
    def __init__(self):
        self.old_passwords = []
    
    def get_password(self):
        """Returns the current password (last in the list)"""
        if self.old_passwords:
            return self.old_passwords[-1]
        return None
    
    def set_password(self, new_password):
        """Sets a new password if it has not been used before"""
        if new_password not in self.old_passwords:
            self.old_passwords.append(new_password)
            print(f"UPDATED PASSWORD - {new_password}")
        else:
            print("ERROR! YOUR PASSWORD WAS USED BEFORE.")
    
    def is_correct(self, password):
        """Checks if the given password matches the current password"""
        if password == self.get_password():
            print(f"{password} IS THE CURRENT PASSWORD")
            return True
        else:
            print(f"{password} IS NOT THE CURRENT PASSWORD")
            return False


# Create an instance of Password_manager
pass_manager = Password_manager()

# Get the number of passwords from the user
num = int(input("ENTER NUMBER OF PASSWORDS YOU WANT TO INSERT: "))

# Insert passwords
for i in range(num):
    pas = input(f"{i+1}) ENTER A PASSWORD: ")
    pass_manager.set_password(pas)

# Display the current password
print(f"CURRENT PASSWORD --> {pass_manager.get_password()}")

# Ask user to check passwords
while True:
    check_pass = input("ENTER A PASSWORD TO CHECK (or type 'exit' to stop): ")
    if check_pass.lower() == 'exit':
        break
    print(f"IT IS THE CURRENT PASSWORD: {pass_manager.is_correct(check_pass)}")
