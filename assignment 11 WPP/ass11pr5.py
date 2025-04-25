import pandas as pd
from itertools import product

concerts = pd.DataFrame({
    'date': pd.to_datetime([
        '2024-01-05', '2024-01-05', '2024-01-20', '2024-02-01', '2024-02-15'
    ]),
    'artist': ['A', 'B', 'A', 'A', 'B'],
    'venue': ['X', 'X', 'Y', 'Y', 'X']
})

concerts['year_month'] = concerts['date'].dt.to_period('M')

grouped = concerts.groupby(['year_month', 'artist', 'venue']).size().reset_index(name='count')

artists = concerts['artist'].unique()
venues = concerts['venue'].unique()
year_months = concerts['year_month'].unique()

full_index = pd.MultiIndex.from_product(
    [year_months, artists, venues],
    names=['year_month', 'artist', 'venue']
)

grouped_full = grouped.set_index(['year_month', 'artist', 'venue']).reindex(full_index, fill_value=0)

wide_table = grouped_full.reset_index().pivot_table(
    index='year_month',
    columns=['artist', 'venue'],
    values='count',
    fill_value=0
)

wide_table.columns = [f'{artist}_{venue}' for artist, venue in wide_table.columns]
print(wide_table)
