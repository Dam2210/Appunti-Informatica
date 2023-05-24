def bubblesort_migliorata( a ): 
    n = len(a)
    ordinata = False
    num_scansioni = 0
    while not ordinata:
        ordinata = True
        for i in range(n-1-num_scansioni):
                if a[i] > a[i+1]:
                    # scambio gli elementi, non posso dire che la lista è ordinata
                    a[i], a[i+1] = a[i+1], a[i]
                    ordinata = False
        num_scansioni += 1
        print(num_scansioni, "       ", b)


b = [9, 0, 2, 5, 1, 8,]
print(bubblesort_migliorata(b))
print(" ")
print("la lista ordinata è:", b)