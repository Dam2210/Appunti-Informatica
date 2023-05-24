a = [[0,1], 1, 2, 3]
b = [2, 1, 0]
c = [4, 5, 6, 7]
for x in zip(a, b, c):
    print(x[0], x[1], x[2])

f=zip(b,c)
print(type(f))
print(f)
d=range(4)
print(type(d))
m=set(f)
print(len(m))

print(m)