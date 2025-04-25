import pandas as pd

num_cars = int(input("Enter number of cars: "))

asking_prices = []
fair_prices = []

for i in range(num_cars):
    ask = float(input(f"Enter asking price for car {i+1}: "))
    fair = float(input(f"Enter fair price for car {i+1}: "))
    asking_prices.append(ask)
    fair_prices.append(fair)


asking_series = pd.Series(asking_prices)
fair_series = pd.Series(fair_prices)


good_deals = asking_series < fair_series
good_deal_indices = list(good_deals[good_deals].index)

print("\nGood deal indices :", good_deal_indices)
