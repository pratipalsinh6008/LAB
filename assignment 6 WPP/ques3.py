'''3. Write a class called Converter. The user will pass a length and a unit when declaring an object 
from  the  class—for  example,  c  =  Converter(9,'inches').  The  possible  units  are  inches,  feet, 
yards,  miles,  kilometers,  meters,  centimeters,  and  millimeters.  For  each  of  these  units  there 
should be a method that returns the length converted into those units. For example, using the 
Converter object created above, the user could call c.feet() and should get 0.75 as the result. '''

class Converter:
    rates = {
        "in": 1, "ft": 12, "yd": 36, "mi": 63360, 
        "km": 39370.1, "m": 39.3701, "cm": 0.393701, "mm": 0.0393701
    }

    def __init__(self, len, unit):
        if unit not in self.rates:
            raise ValueError("Invalid unit!")
        self.len = len
        self.unit = unit
        self.base = len * self.rates[unit]

    def in_(self): 
        return self.base / self.rates["in"]
    def ft(self): 
        return self.base / self.rates["ft"]
    def yd(self): 
        return self.base / self.rates["yd"]
    def mi(self): 
        return self.base / self.rates["mi"]
    def km(self): 
        return self.base / self.rates["km"]
    def m(self): 
        return self.base / self.rates["m"]
    def cm(self): 
        return self.base / self.rates["cm"]
    def mm(self): 
        return self.base / self.rates["mm"]

l = float(input("Length: "))
u = input("Unit (in, ft, yd, mi, km, m, cm, mm): ").lower()

c = Converter(l, u)

print(f"Feet: {c.ft()} Yards: {c.yd()} Miles: {c.mi()}")
print(f"Kilometers: {c.km()} Meters: {c.m()} Centimeters: {c.cm()} Millimeters: {c.mm()}")
