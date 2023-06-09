import random as rn

def r_float( n ):
    '''
    Input: n, un intero
    Output: un float pseudo-casuale in [0,1) con n cifre significative dopo
        il punto
    '''
    str_f = '0.'
    for c in range(n-1):
        # n-1 caratteri in 0...9
        str_f += str(rn.randint(0, 9))
    # l'ultimo carattere non deve essere 0
    str_f += str(rn.randint(1, 9))
    return float(str_f)

print(r_float(20))