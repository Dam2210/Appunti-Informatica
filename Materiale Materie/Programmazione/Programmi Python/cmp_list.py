
a = [1, 4, 7]
b = [2, 1, 9]
n = len(a)
c=[] 

def cmp_list(a, b):
    for i in range(n):
        print(a[i], ":", b[i])
        if a[i] >= b[i]:
            c.append(False)
    c.append(True)

print(cmp_list(a,b))
print(c)
print(all(c)) #restituisce true se tutti sono true
print(any(c)) #restituisce true se almeno uno è true
c1 = [x**2 for x in range(10)] #10 = n
#lista contenente tutti i numeri da 0 a n alla seconda
print(c1)
c2 = [a[i]<b[i] for i in range(n)]
print(c2)
print(all(c2))