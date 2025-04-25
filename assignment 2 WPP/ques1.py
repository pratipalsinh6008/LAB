# Ask the user to enter a word
word = input("Enter a word: ")

# Capitalize every other letter
new_word = ""
for i in range(len(word)):
    if i % 2 == 0:  # Even index (0, 2, 4...) remains lowercase
        new_word += word[i].lower()
    else:  # Odd index (1, 3, 5...) is capitalized
        new_word += word[i].upper()

# Print the result
print("Modified word:", new_word)