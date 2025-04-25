t = int(input())
for _ in range(t):
    s = input()
    n = len(s)
    operations = 0
    for i in range(n // 2):
        left = ord(s[i])
        right = ord(s[n - 1 - i])
        operations += abs(left - right)
    print(operations)
   