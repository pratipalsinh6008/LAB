'''Decode the message: 
A message containing the letters from A-Z can be encoded into the numbers using the mapping 
A-> 1, B-> 2, C-> 3, ..., Z-> 26. To decode an encoded message, you need to group the digits 
and do the reverse mapping. You are required to display all the possible decoded messages. 
For example: "11106" can be decoded into: 
a. "AAJF" with the grouping (1 1 10 6) 
b. "KJF" with the grouping (11 10 6)'''

class Decoder:
    def __init__(self, s):
        self.s = s
        self.result = []

    def decode_ways(self, index=0, path=""):
        if index == len(self.s):
            self.result.append(path)
            return
        
        if self.s[index] != '0': 
            self.decode_ways(index + 1, path + chr(int(self.s[index]) + 64))
        
        if index + 1 < len(self.s) and 10 <= int(self.s[index:index+2]) <= 26:
            self.decode_ways(index + 2, path + chr(int(self.s[index:index+2]) + 64))
    
    def get_decodings(self):
        self.decode_ways()
        return self.result

encoded_message = "11106"
decoder = Decoder(encoded_message)
possible_decodings = decoder.get_decodings()
print("Possible Decodings:")
for decoding in possible_decodings:
    print(decoding)

    