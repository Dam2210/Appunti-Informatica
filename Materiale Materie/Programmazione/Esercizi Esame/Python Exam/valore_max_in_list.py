"""
Popolare una lista con 20 numeri a piacere. Dopo l’inserimento visualizzare 
tutti gli elementi della lista con il relativo indice.
Dopo trovare il valore massimo tra quelli inseriti nella lista.
"""

a = [3, 6, 7, 9, 10, 30, 36, 404, 104, 569, 202, 4, 0]

for i in range (len(a)):
    print(i, "---->", a[i])

max_num = None
for i in range(len(a)):
    if max_num == None:
        max_num = a[i]
    if a[i] > max_num:
        max_num = a[i]

print(max_num)