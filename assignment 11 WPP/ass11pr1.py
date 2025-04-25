import pandas as pd
from datetime import datetime, date, time


dt_jan_15 = pd.to_datetime('2012-01-15')
print("a) Date time for Jan 15, 2012:", dt_jan_15)


dt_specific = pd.to_datetime('2025-04-13 21:20')
print("b) Specific date and time of 9:20 PM:", dt_specific)


dt_local = pd.Timestamp.now()
print("c) Local date and time:", dt_local)

dt_date_only = pd.to_datetime('2025-04-13').date()
print("d) Date without time:", dt_date_only)


current_date = date.today()
print("e) Current date:", current_date)


dt_full = pd.Timestamp.now()
only_time = dt_full.time()
print("f) Time from current datetime:", only_time)

local_time = datetime.now().time()
print("g) Current local time:", local_time)
