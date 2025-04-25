import pandas as pd


s = pd.Series(['X', 'Y', 'T', 'Aaba', 'Baca', 'CABA', None, 'bird', 'horse', 'dog'])


upper_case = s.str.upper()
print("Uppercase:\n",upper_case)


lower_case = s.str.lower()
print("\nLowercase:\n",lower_case)

string_lengths = s.str.len()
print("\nLength of each string:\n",string_lengths)
