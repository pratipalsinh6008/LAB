import pandas as pd

df = pd.DataFrame({
    'john': [True, False, True, True, False, False, True, False, True, True],
    'judy': [True, True, False, True, True, False, False, True, False, True]
})


df['party'] = df['john'] & df['judy']

days_til_party = []
next_party_day = None

for i in reversed(range(len(df))):
    if df.loc[i, 'party']:
        next_party_day = i
        days_til_party.append(0)
    elif next_party_day is not None:
        days_til_party.append(next_party_day - i)
    else:
        days_til_party.append(None)

df['days_til_party'] = list(reversed(days_til_party))

print(df)
