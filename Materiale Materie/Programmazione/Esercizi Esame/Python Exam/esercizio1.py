def rimuovi_non_ordinati(a):
    n = len(a)
    i = 0
    a = list(a)
    
    for i  in range(n-1):
        if i > n-1:
            break
        if ord(a[i]) > ord(a[i+1]):
            a = a[:i+1] + a[i+2:]
            n-=1
        elif ord(a[i]) < ord(a[i+1]):
            a = a[:i]+a[i+1:]
            n-=1
        elif ord(a[i]) == ord(a[i]):
            a = a
    a = str(a)
    return a



a = "ddabeceffgfh"
a = rimuovi_non_ordinati(a)
print(a)