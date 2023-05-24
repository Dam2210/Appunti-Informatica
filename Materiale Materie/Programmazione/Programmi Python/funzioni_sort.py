a = [1,2,3,4,5,6]
b=a[:]
b.insert(6,10)
print(a,b)
print(id(a)==id(b))

#funzioni sort
a.sort(reverse=True)
print(a)
j=["ciao","porco"]
j.sort(reverse=True)
print(j)
z=[1,2,8,0]
print(sorted(z))
k=["primo","terzo","secondo","quarto"]
print(sorted(k,key=len,reverse=True))
print("Con Tuple : ",sorted(("primo","terzo","secondo","quarto"),key=len,reverse=True))

t=[1,2,5,4,8,6,2,4,5]
print(id(t))
t=sorted(t)#restituisce una nuova lista
print(id(t))
print(t)
#si può fare anche con sort
d=["primo","terzo","secondo","quarto"]
print(id(d))
d.sort(key=len)#restituisce una nuova lista
print(id(d))
print(d)

c = 'abcde'
d = c[:]
print(c,d)
print(id(c)==id(d))

try:
    x=int(input("Numero 1 : "))
except ValueError:
    x=0
    print("Uso il valore di default")
ciclo = True
while ciclo:
    try:
        y=int(input("Numero 2 : "))
        ciclo = False
    except ValueError:
        print("Riprova")
try:
    print(x/y)
except ZeroDivisionError:
    print("non posso dividere per 0")
