#A = [2,4,6,9,13,20,5,2]
#A = [20, 13, 11, 10, 8, 7, 2, 0]
A = [3, 20, 13, 11, 10, 8, 7, 2, 0] #non funziona con quest'array

def ric_max(A,i,j):
    if(i>j):
        return -1
    m = (i+j)//2
    if(A[m] > A[m-1]and A[m] > A[m+1]):
        return m
    if(A[m] < A[m+1]):
        return ric_max(A,m+1,j)
    else:
        return ric_max(A,i,m-1)
    
def Max(A):
    n = len(A)-1
    if(A[0] > A[1]):
        return 0
    if(A[n] > A[n-1]):
        return n
    return ric_max(A,2,n-1)

def OrdinaArray(A, mass):
    B = A[:mass] #array B gia ordinato
    C = A[mass:] #ordino solo la parte rimanente che è in ordine decrescente
    i = 0
    j = len(C)-1
    while(i<j):
        if(C[i] > C[j]):
            appo = C[i]
            C[i] = C[j]
            C[j] = appo
            i+=1
            j-=1
    A = merge(B, C)
    return A
    
def merge(B, C):
    Appo = []
    i = 0
    j = 0
    if(len(B)!=0 and len(C)!= 0):
        while i < len(B) and j < len(C):
            if(B[i]<C[j]):
                Appo.append(B[i])
                i+=1
            else:
                Appo.append(C[j])
                j+=1
        if(B[len(B)-1] < C[len(C)-1]):
            Appo.append(C[len(C)-1])
        else:
            Appo.append(B[len(B)-1])
    else:
        Appo = C
    return Appo
   
mass = Max(A)
print(A[mass])
A = OrdinaArray(A, mass)
print(A)