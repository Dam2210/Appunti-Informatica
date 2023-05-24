
x = int(input())
y = int(input())
z = int(input())
n = int(input())
    
ax = list(range(x+1))
by = list(range(y+1))
cz = list(range(z+1))

a = []

#creo una lista contentente liste con tutte le possibili combinazioni della lista ax, by, cz
t = [[i, j, k] for i in ax for j in by for k in cz]


for i in range(len(t)):
    if sum(t[i]) != n: #sommo i numeri contenuti in ogni lista presente all'interno della lista t e verifico che la somma sia diversa da n
        a.append(t[i]) #se è così li aggiungo alla lista a
    
print(a)