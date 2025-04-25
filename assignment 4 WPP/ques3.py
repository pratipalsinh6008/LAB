def is_pangram(s):
    s = s.lower()  # Convert to lowercase
    letter_set = set()  

    for char in s:
        if char.isalpha():  # Only consider alphabetic characters
            letter_set.add(char)

    return "pangram" if len(letter_set) == 26 else "not pangram"

# Taking user input
sentence = input("Enter a sentence: ")
print(is_pangram(sentence))