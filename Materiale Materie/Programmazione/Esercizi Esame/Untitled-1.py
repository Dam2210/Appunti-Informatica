def enigma(n):
    a = list(range(n))
    A = set(a)
    if len(A) > 0:
        B=set(a*6)
        return 1+enigma(len(B-A))
    else:
        return 0

print(enigma(7))