#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*GENERALE*/

struct array_int
{
    int *a;
    int n;
};
typedef struct array_int array_int;

/*restituisce un array con la posizione delle vocali*/
array_int Posizione_vocali(char *s)
{
    int i = 0;
    array_int a;
    int j = 0;

    a.n = 0;
    a.a = malloc(sizeof(int) * strlen(s));

    while (s[i] != '\0')
    {
        if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' || s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
        {
            a.n++;
            a.a[j] = i;
            j++;
        }
        i++;
    }
    a.a = realloc(a.a, sizeof(int) * j);
    return a;
}

/*sposta tutte le lettere che si ripetono a fine stringa*/
void Ripetizioni_a_fine_stringa(char a[])
{
    int i = 0;
    int j;
    int t;
    int start;
    int caratteri_spostati = 0;
    int len = strlen(a);
    while (i < len)
    {
        j = i + 1;
        caratteri_spostati = 0;
        while (j < len - caratteri_spostati)
        {
            if (a[j] == a[i])
            {
                start = j;
                while (start < len - 1) //senza -1 elimina tutte le ripetizioni
                {
                    t = a[start];
                    a[start] = a[start + 1];
                    a[start + 1] = t;
                    start++;
                }
                caratteri_spostati++;
            }
            j++;
             /*questo if serve nel caso in cui ci siano ripetizioni vicine ad esempio: mamma*/
            if (a[j - 1] == a[i])
            {
                j--;
            }
        }
        i++;
    }
}

/*elimina tutte le lettere ripetute nella stringa*/
void Elimina_ripetizioni_stringa(char a[])
{
    int i = 0;
    int j = 1;
    int n = strlen(a);
    Ripetizioni_a_fine_stringa(a);
    while (a[j] != a[i])
    {
        j++;
        if (j == n)
        {
            i++;
            j = i + 1;
        }
    }
    a[j] = '\0';
}

void cpstr(char *x, char *y)
{
    int i = 0;

    while (x[i] != '\0')
    {
        y[i] = x[i];
        i++;
    }

    y[i] = x[i];
}

/*date due stringhe copia quella di lunghezza minore in quella di lunghezza maggiore sovrascrivendola*/
void Copia_Stringa(char *x, char *y) 
{
    int lun_x = strlen(x);
    int lun_y = strlen(y);
    
    if (lun_x < lun_y)
    {
        cpstr(x, y);
    }
    else
    {
        cpstr(y, x);
    }
}

char *ConcatenaStringhe(char *x, char *y)
{
    int lx = strlen(x);
    int ly = strlen(y);
    char *outstr = (char *)malloc((lx + ly + 1) * sizeof(char));
    int i;

    if (outstr == NULL)
        return NULL;

    i = 0;
    while (x[i] != '\0')
    {
        outstr[i] = x[i];
        i++;
    }
    i = 0;
    while (y[i] != '\0')
    {
        outstr[lx + i] = y[i];
        i++;
    }
    outstr[lx + i] = '\0';

    return outstr;
}

char *Clona_stringa(char *x)
{
    int n = strlen(x);
    char *y = (char *)malloc((n + 1) * sizeof(char));
    int i;

    if (y == NULL)
        return NULL;

    for (i = 0; i < n; i++)
    {
        y[i] = x[i];
    }

    y[i] = '\0';

    return y;
}

void BubbleSort(char *x)
{
    int n = strlen(x);
    int i, j = 0;
    char t;
    int scambi = 1;

    while (scambi > 0)
    {
        i = 0;
        scambi = 0;
        while (i < n - 1 - j)
        {
            if (x[i] > x[i + 1])
            {
                t = x[i + 1];
                x[i + 1] = x[i];
                x[i] = t;
                scambi++;
            }
            i++;
        }
        j++;
    }
}

int StrCmp(char *x, char *y)
{
    int i = 0;
    int risultato;

    while (x[i] == y[i] && y[i] != '\0')
    {
        i++;
    }

    if (x[i] == y[i])
    {
        risultato = 0;
    }
    else
    {
        if (x[i] < y[i] || x[i] == '\0')
        {
            risultato = -1;
        }
        else if (x[i] > y[i] || y[i] == '\0')
        {
            risultato = 1;
        }
    }

    return risultato;
}

int Anagrammi(char *x, char *y)
{
    char *xx, *yy;
    int r;

    if (strlen(x) != strlen(y))
        return 0;

    xx = Clona_stringa(x);
    yy = Clona_stringa(y);

    if (xx == NULL || yy == NULL)
        return -1;

    BubbleSort(xx);
    BubbleSort(yy);

    if (strcmp(xx, yy) == 0)
        r = 1;
    else
        r = 0;

    free(xx);
    free(yy);

    return r;
}

int Sottostringa(char a[], char b[])
{
    int i, j;
    int n = strlen(a);
    int m = strlen(b);
    for (i = 0; i <= n - m; i = i + 1)
    {
        j = 0;
        while (j < m && a[i + j] == b[j])
        {
            j = j + 1;
        }
        if (j == m)
        {
            return i;
        }
    }
    return -1;
}

void Rimuovi_non_ordinati(char *a)
{
    int i = 0;
    int j;
    char t;

    "ddabeceffgfh";
    while (a[i] != '\0')
    {
        if (a[i] > a[i + 1])
        {
            j = i + 1;
            while (a[j + 1] != '\0')
            {
                t = a[j + 1];
                a[j + 1] = a[j];
                a[j] = t;
                j++;
            }
            a[j] = '\0';
        }
        i++;
        if (a[i] < a[i - 1] && a[i + 1] != '\0')
        {
            i--;
        }
    }
}

int Rimuovi_sottostringa(char *a, char *b)
{
    int i = 0;
    int n;
    int j;
    int risultato = 0;
    while (a[i] != '\0')
    {
        n = 0;
        if (a[i] == b[n])
        {
            j = i;
            while (a[j] == b[n] && b[n] != '\0')
            {
                j++;
                n++;
            }
            if (strlen(b) == (n))
            {
                while (a[j] != '\0')
                {
                    a[j - n] = a[j];
                    j++;
                }
                a[j - n] = '\0';
                risultato++;
            }
            n = 0;
        }
        i++;
    }
    if (risultato > 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void BubbleSort_porzione(char x[], int p, int q)
{
    if (p >= strlen(x) - 1 q >= strlen(x) - 1 q <= p)
    {
        p = 0;
        q = strlen(x) - 1;
    }
    int i, j = 0;
    char t;
    int scambi = 1;

    while (scambi > 0)
    {
        i = p;
        scambi = 0;
        while (i < q - j)
        {
            if (x[i] > x[i + 1])
            {
                t = x[i + 1];
                x[i + 1] = x[i];
                x[i] = t;
                scambi++;
            }
            i++;
        }
        j++;
    }
}

void BubbleSort_inverso_porzione(char x[], int p, int q)
{
    if (p >= strlen(x - 1) q >= strlen(x) - 1 q <= p)
    {
        p = 0;
        q = strlen(x) - 1;
    }
    int i, j = 0;
    char t;
    int scambi = 1;

    while (scambi > 0)
    {
        i = p;
        scambi = 0;
        while (i < q - j)
        {
            if (x[i] < x[i + 1])
            {
                t = x[i + 1];
                x[i + 1] = x[i];
                x[i] = t;
                scambi++;
            }
            i++;
        }
        j++;
    }
}

void Elimina_spazi(char a[])
{
    int i = 0;
    int l = strlen(a);
    int n = l - 1;
    int j;
    int d = 0;
    char t;

    while (n >= 0)
    {
        if (a[n] == ' ')
        {
            j = n;
            while (j + 1 != l - d)
            {
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
                j++;
            }
            d++;
        }
        n--;
    }
    a[l - d] = '\0';
}

void Rendi_maiuscolo(char a[])
{
    int i = 0;
    while (a[i] != '\0')
    {
        if (a[i] >= 'a' && a[i] <= 'z')
        {
            a[i] = a[i] + ('A' - 'a');
        }
        i++;
    }
}

void Rendi_minuscolo(char a[])
{
    int i = 0;
    while (a[i] != '\0')
    {
        if (a[i] >= 'A' && a[i] <= 'Z')
        {
            a[i] = a[i] + ('a' - 'A');
        }
        i++;
    }
}
/*
 * restituisce 1 se la stringa a è quasi uguale alla stringa b
 * 0 altrimenti
 * (quasi uguale: differiscono solo per alcune lettere che invece che maiuscolo sono minuscole o viceversa)
 * */
int IgnoraMaiuscolo(char a[], char b[])
{
    int i = 0;
    int j = 0;
    if (strlen(a) == strlen(b))
    {
        while (a[i] != '\0' && b[i] != '\0')
        {
            if (a[i] <= 'z' || a[i] >= 'A')
            {
                if (b[i] == a[i] b[i] == a[i] + 'A' - 'a' b[i] == a[i] + 'a' - 'A')
                {
                    j++;
                }
            }
            i++;
        }
    }
    if (j == strlen(a) && j >= 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/*
 * NUMERI
 * */

void Numeri_a_inizio_stringa(char a[])
{
    int i = 0;
    int n = strlen(a) - 1;
    int j;
    int d = 0;
    char t;

    while (a[i] != '\0')
    {
        if (a[i] == '0' a[i] == '1' a[i] == '2' a[i] == '3' a[i] == '4' a[i] == '5' a[i] == '6' a[i] == '7' a[i] == '8' || a[i] == '9')
        {
            j = i;
            while (j != d)
            {
                t = a[j];
                a[j] = a[j - 1];
                a[j - 1] = t;
                j--;
            }
            d++;
        }
        i++;
    }
}

void Numeri_a_fine_stringa(char a[])
{
    int i = 0;
    int l = strlen(a);
    int n = l - 1;
    int j;
    int d = 0;
    char t;

    while (n >= 0)
    {
        if (a[n] == '0' a[n] == '1' a[n] == '2' a[n] == '3' a[n] == '4' a[n] == '5' a[n] == '6' a[n] == '7' a[n] == '8' || a[n] == '9')
        {
            j = n;
            while (j + 1 != l - d)
            {
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
                j++;
            }
            d++;
        }
        n--;
    }
}

void Elimina_numeri(char a[])
{
    int i = 0;
    Numeri_a_fine_stringa(a);
    while (a[i] != '\0')
    {
        if (a[i] == '0' a[i] == '1' a[i] == '2' a[i] == '3' a[i] == '4' a[i] == '5' a[i] == '6' a[i] == '7' a[i] == '8' || a[i] == '9')
        {
            a[i] = '\0';
        }
        i++;
    }
}

int Conta_numeri_porzione(char a[], int p, int q)
{
    if (p >= strlen(a) - 1 q >= strlen(a) - 1 q <= p)
    {
        p = 0;
        q = strlen(a) - 1;
    }
    int i = p;
    int j = 0;

    while (a[i] != '\0' && i != q)
    {
        if (a[i] == '0' a[i] == '1' a[i] == '2' a[i] == '3' a[i] == '4' a[i] == '5' a[i] == '6' a[i] == '7' a[i] == '8' || a[i] == '9')
        {
            j++;
        }
        i++;
    }
    return j;
}

void BubbleSort_numeri_porzione(char a[], int p, int q)
{
    int i, j;
    int v = Conta_numeri_porzione(a, p, q);
    char t;
    if (p >= strlen(a) - 1 q >= strlen(a) - 1 q <= p)
    {
        p = 0;
        q = strlen(a) - 1;
    }

    while (v > 0)
    {
        i = p;
        while (i < q)
        {
            j = 1;
            if (a[i] == '0' a[i] == '1' a[i] == '2' a[i] == '3' a[i] == '4' a[i] == '5' a[i] == '6' a[i] == '7' a[i] == '8' || a[i] == '9')
            {
                while ((a[i + j] != '0' && a[i + j] != '1' && a[i + j] != '2' && a[i + j] != '3' && a[i + j] != '4' && a[i + j] != '5' && a[i + j] != '6' && a[i + j] != '7' && a[i + j] != '8' && a[i + j] != '9') && i + j <= q)
                {
                    j++;
                }
                if (a[i + j] == '0' a[i + j] == '1' a[i + j] == '2' a[i + j] == '3' a[i + j] == '4' a[i + j] == '5' a[i + j] == '6' a[i + j] == '7' a[i + j] == '8' || a[i + j] == '9')
                {
                    if (a[i] > a[i + j])
                    {
                        t = a[i + j];
                        a[i + j] = a[i];
                        a[i] = t;
                    }
                    i = i + j - 1;
                }
            }
            i++;
        }
        q = i;
        v--;
    }
}

char *EstraiSegmento(char a[], int p, int q)
{
    int i = 0;
    if (p >= strlen(a) - 1 q >= strlen(a) - 1 q <= p)
    {
        p = 0;
        q = strlen(a) - 1;
    }
    char *b = malloc(sizeof(char) * (q - p + 1));
    while (p <= q)
    {
        b[i] = a[p];
        i++;
        p++;
    }
    return b;
}

/*
 * VOCALI
 * */

void Vocali_a_inizio_stringa(char a[])
{
    int i = 0;
    int j;
    int d = 0;
    char t;

    while (a[i] != '\0')
    {
        if (a[i] == 'a' a[i] == 'e' a[i] == 'i' a[i] == 'o' a[i] == 'u' a[i] == 'A' a[i] == 'E' a[i] == 'I' a[i] == 'O' || a[i] == 'U')
        {
            j = i;
            while (j != d)
            {
                t = a[j];
                a[j] = a[j - 1];
                a[j - 1] = t;
                j--;
            }
            d++;
        }
        i++;
    }
}

void Vocali_a_fine_stringa(char a[])
{
    int l = strlen(a);
    int n = l - 1;
    int j;
    int d = 0;
    char t;

    while (n >= 0)
    {
        if (a[n] == 'a' a[n] == 'e' a[n] == 'i' a[n] == 'o' a[n] == 'u' a[n] == 'A' a[n] == 'E' a[n] == 'I' a[n] == 'O' || a[n] == 'U')
        {
            j = n;
            while (j + 1 != l - d)
            {
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
                j++;
            }
            d++;
        }
        n--;
    }
}

void Elimina_vocali(char a[])
{
    int i = 0;
    Vocali_a_fine_stringa(a);
    while (a[i] != '\0')
    {
        if (a[i] == 'a' a[i] == 'e' a[i] == 'i' a[i] == 'o' a[i] == 'u' a[i] == 'A' a[i] == 'E' a[i] == 'I' a[i] == 'O' || a[i] == 'U')
        {
            a[i] = '\0';
        }
        i++;
    }
}

int Conta_vocali_porzione(char a[], int p, int q)
{
    if (p >= strlen(a) - 1 q > strlen(a) - 1 q <= p)
    {
        p = 0;
        q = strlen(a) - 1;
    }
    int i = p;
    int j = 0;

    while (a[i] != '\0' && i != q)
    {
        if (a[i] == 'a' a[i] == 'e' a[i] == 'i' a[i] == 'o' a[i] == 'u' a[i] == 'A' a[i] == 'E' a[i] == 'I' a[i] == 'O' || a[i] == 'U')
        {
            j++;
        }
        i++;
    }
    return j;
}

void BubbleSort_vocali_porzione(char a[], int p, int q)
{
    int i, j = 0;
    int v = Conta_vocali_porzione(a, p, q);
    char t;
    if (p >= strlen(a) - 1 q >= strlen(a) - 1 q <= p)
    {
        p = 0;
        q = strlen(a) - 1;
    }

    while (v > 0)
    {
        i = p;
        while (i < q)
        {
            j = 1;
            if (a[i] == 'a' a[i] == 'e' a[i] == 'i' a[i] == 'o' a[i] == 'u' a[i] == 'A' a[i] == 'E' a[i] == 'I' a[i] == 'O' || a[i] == 'U')
            {
                while ((a[i + j] != 'a' && a[i + j] != 'e' && a[i + j] != 'i' && a[i + j] != 'o' && a[i + j] != 'u' && a[i + j] != 'A' && a[i + j] != 'E' && a[i + j] != 'I' && a[i + j] != 'O' && a[i + j] != 'U') && i + j <= q)
                {
                    j++;
                }
                if (a[i + j] == 'a' a[i + j] == 'e' a[i + j] == 'i' a[i + j] == 'o' a[i + j] == 'u' a[i + j] == 'A' a[i + j] == 'E' a[i + j] == 'I' a[i + j] == 'O' || a[i + j] == 'U')
                {
                    if (a[i] > a[i + j])
                    {
                        t = a[i + j];
                        a[i + j] = a[i];
                        a[i] = t;
                    }
                    i = i + j - 1;
                }
            }
            i++;
        }
        q = i;
        v--;
    }
}

void Vocali_ripetute_a_fine_stringa(char a[])
{
    int i = 0;
    int j;
    int t;
    int l;
    int d = 0;
    int n = strlen(a);
    while (i < n)
    {
        while (((a[i] >= 'z' a[i] < 'A')(a[i] != 'a' && a[i] != 'e' && a[i] != 'i' && a[i] != 'o' && a[i] != 'u' && a[i] != 'A' && a[i] != 'E' && a[i] != 'I' && a[i] != 'O' && a[i] != 'U')) && i < n)
        {
            i++;
        }
        j = i + 1;
        d = 0;
        while (j < n - d)
        {
            if (a[j] == a[i])
            {
                l = j;
                while (l < n - d - 1)
                {
                    t = a[l];
                    a[l] = a[l + 1];
                    a[l + 1] = t;
                    l++;
                }
                d++;
            }
            j++;
            if (a[j - 1] == a[i])
            {
                j--;
            }
        }
        i++;
    }
}

void Elimina_vocali_ripetute(char a[])
{
    int i = 0;
    int j = 1;
    int n = strlen(a);
    Vocali_ripetute_a_fine_stringa(a);
    while (a[j] != a[i])
    {
        j++;
        if (j == n)
        {
            i++;
            j = i + 1;
        }
    }
    a[j] = '\0';
}

/*
 * CONSONANTI
 * */
void Consonanti_a_inizio_stringa(char a[])
{
    int i = 0;
    int j;
    int d = 0;
    char t;

    while (a[i] != '\0')
    {
        if ((a[i] <= 'z' || a[i] > 'A') && a[i] != 'a' && a[i] != 'e' && a[i] != 'i' && a[i] != 'o' && a[i] != 'u' && a[i] != 'A' && a[i] != 'E' && a[i] != 'I' && a[i] != 'O' && a[i] != 'U')
        {
            j = i;
            while (j != d)
            {
                t = a[j];
                a[j] = a[j - 1];
                a[j - 1] = t;
                j--;
            }
            d++;
        }
        i++;
    }
}

void Consonanti_a_fine_stringa(char a[])
{
    int l = strlen(a);
    char t;

    while (n >= 0)
    {
        if ((a[n] <= 'z' || a[n] > 'A') && a[n] != 'a' && a[n] != 'e' && a[n] != 'i' && a[n] != 'o' && a[n] != 'u' && a[n] != 'A' && a[n] != 'E' && a[n] != 'I' && a[n] != 'O' && a[n] != 'U')
        {
            j = n;
            while (j + 1 != l - d)
            {
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
                j++;
            }
            d++;
        }
        n--;
    }
}

void Elimina_consonanti(char a[])
{
    int i = 0;
    Consonanti_a_fine_stringa(a);
    while (a[i] != '\0')
    {
        if ((a[i] <= 'z' || a[i] > 'A') && a[i] != 'a' && a[i] != 'e' && a[i] != 'i' && a[i] != 'o' && a[i] != 'u' && a[i] != 'A' && a[i] != 'E' && a[i] != 'I' && a[i] != 'O' && a[i] != 'U')
        {
            a[i] = '\0';
        }
        i++;
    }
}

int Conta_consonanti_porzione(char a[], int p, int q)
{
    if (p >= strlen(a) - 1 q > strlen(a) - 1 q <= p)
    {
        p = 0;
        q = strlen(a) - 1;
    }
    int i = p;
    int j = 0;

    while (a[i] != '\0' && i <= q)
    {
        if ((a[i] <= 'z' || a[i] > 'A') && a[i] != 'a' && a[i] != 'e' && a[i] != 'i' && a[i] != 'o' && a[i] != 'u' && a[i] != 'A' && a[i] != 'E' && a[i] != 'I' && a[i] != 'O' && a[i] != 'U')
        {
            j++;
        }
        i++;
    }
    return j;
}

void BubbleSort_consonanti_porzione(char a[], int p, int q)
{
    int i, j = 0;
    int v = Conta_consonanti_porzione(a, p, q);
    char t;
    if (p >= strlen(a) - 1 q >= strlen(a) - 1 q <= p)
    {
        p = 0;
        q = strlen(a) - 1;
    }

    while (v > 0)
    {
        i = p;
        while (i < q)
        {
            j = 1;
            if ((a[i] <= 'z' || a[i] > 'A') && a[i] != 'a' && a[i] != 'e' && a[i] != 'i' && a[i] != 'o' && a[i] != 'u' && a[i] != 'A' && a[i] != 'E' && a[i] != 'I' && a[i] != 'O' && a[i] != 'U')
            {
                while ((a[i + j] > 'z' a[i + j] <= 'A')(a[i + j] == 'a' a[i + j] == 'e' a[i + j] == 'i' a[i + j] == 'o' a[i + j] == 'u' && a[i + j] == 'A' && a[i + j] == 'E' a[i + j] == 'I' a[i + j] == 'O' || a[i + j] == 'U') && i + j <= q)
                {
                    j++;
                }
                if ((a[i + j] <= 'z' || a[i + j] > 'A') && a[i + j] != 'a' && a[i + j] != 'e' && a[i + j] != 'i' && a[i + j] != 'o' && a[i + j] != 'u' && a[i + j] != 'A' && a[i + j] != 'E' && a[i + j] != 'I' && a[i + j] != 'O' && a[i + j] != 'U')
                {
                    if (a[i] > a[i + j])
                    {
                        t = a[i + j];
                        a[i + j] = a[i];
                        a[i] = t;
                    }
                    i = i + j - 1;
                }
            }
            i++;
        }
        q = i;
        v--;
    }
}

void Consonanti_ripetute_a_fine_stringa(char a[])
{
    int i = 0;
    int j;
    int t;
    int l;
    int d = 0;
    int n = strlen(a);
    while (i < n)
    {
        while (((a[i] > 'z' a[i] <= 'A')(a[i] == 'a' a[i] == 'e' a[i] == 'i' a[i] == 'o' a[i] == 'u' a[i] == 'A' a[i] == 'E' a[i] == 'I' a[i] == 'O' || a[i] == 'U')) && i < n)
        {
            i++;
        }
        j = i + 1;
        d = 0;
        while (j < n - d)
        {
            if (a[j] == a[i])
            {
                l = j;
                while (l < n - d - 1)
                {
                    t = a[l];
                    a[l] = a[l + 1];
                    a[l + 1] = t;
                    l++;
                }
                d++;
            }
            j++;
            if (a[j - 1] == a[i])
            {
                j--;
            }
        }
        i++;
    }
}

void Elimina_consonanti_ripetute(char a[])
{
    int i = 0;
    int j = 1;
    int n = strlen(a);
    Consonanti_ripetute_a_fine_stringa(a);
    while (a[j] != a[i])
    {
        j++;
        if (j == n)
        {
            i++;
            j = i + 1;
        }
    }
    a[j] = '\0';
}

/*
 * CARATTERI SPECIALI
 * */

void Caratteri_speciali_a_inizio_stringa(char a[])
{
    int i = 0;
    int j;
    int d = 0;
    char t;

    while (a[i] != '\0')
    {
        if ((a[i] > 'z' || a[i] < 'A') && a[i] != '0' && a[i] != '1' && a[i] != '2' && a[i] != '3' && a[i] != '4' && a[i] != '5' && a[i] != '6' && a[i] != '7' && a[i] != '8' && a[i] != '9')
        {
            j = i;
            while (j != d)
            {
                t = a[j];
                a[j] = a[j - 1];
                a[j - 1] = t;
                j--;
            }
            d++;
        }
        i++;
    }
}

void Caratteri_speciali_a_fine_stringa(char a[])
{
    int i = 0;
    int l = strlen(a);
    int n = l - 1;
    int j;
    int d = 0;
    char t;

    while (n >= 0)
    {
        if ((a[i] > 'z' || a[i] < 'A') && a[i] != '0' && a[i] != '1' && a[i] != '2' && a[i] != '3' && a[i] != '4' && a[i] != '5' && a[i] != '6' && a[i] != '7' && a[i] != '8' && a[i] != '9')
        {
            j = n;
            while (j + 1 != l - d)
            {
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
                j++;
            }
            d++;
        }
        n--;
    }
}

void Elimina_caratteri_speciali(char a[])
{
    int i = 0;
    Caratteri_speciali_a_fine_stringa(a);
    while (a[i] != '\0')
    {
        if ((a[i] > 'z' || a[i] < 'A') && a[i] != '0' && a[i] != '1' && a[i] != '2' && a[i] != '3' && a[i] != '4' && a[i] != '5' && a[i] != '6' && a[i] != '7' && a[i] != '8' && a[i] != '9')
        {
            a[i] = '\0';
        }
        i++;
    }
}

int Conta_caratteri_speciali_porzione(char a[], int p, int q)
{
    if (p >= strlen(a) - 1 q > strlen(a) - 1 q <= p)
    {
        p = 0;
        q = strlen(a) - 1;
    }
    int i = p;
    int j = 0;

    while (a[i] != '\0' && i <= q)
    {
        if ((a[i] > 'z' || a[i] < 'A') && a[i] != '0' && a[i] != '1' && a[i] != '2' && a[i] != '3' && a[i] != '4' && a[i] != '5' && a[i] != '6' && a[i] != '7' && a[i] != '8' && a[i] != '9')
        {
            j++;
        }
        i++;
    }
    return j;
}

/*
 * CARATTERI NON ALFABETICI
 * */

void Caratteri_non_alfabetici_a_inizio_stringa(char a[])
{
    int i = 0;
    int j;
    int d = 0;
    char t;

    while (a[i] != '\0')
    {
        if (a[i] > 'z' || a[i] < 'A')
        {
            j = i;
            while (j != d)
            {
                t = a[j];
                a[j] = a[j - 1];
                a[j - 1] = t;
                j--;
            }
            d++;
        }
        i++;
    }
}

void Caratteri_non_alfabetici_a_fine_stringa(char a[])
{
    int i = 0;
    int l = strlen(a);
    int n = l - 1;
    int j;
    int d = 0;
    char t;

    while (n >= 0)
    {
        if (a[i] > 'z' || a[i] < 'A')
        {
            j = n;
            while (j + 1 != l - d)
            {
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
                j++;
            }
            d++;
        }
        n--;
    }
}

void Elimina_caratteri_non_alfabetici(char a[])
{
    int i = 0;
    Caratteri_non_alfabetici_a_fine_stringa(a);
    while (a[i] != '\0')
    {
        if (a[i] > 'z' || a[i] < 'A')
        {
            a[i] = '\0';
        }
        i++;
    }
}

int Conta_caratteri_non_alfabetici_porzione(char a[], int p, int q)
{
    if (p >= strlen(a) - 1 q > strlen(a) - 1 q <= p)
    {
        p = 0;
        q = strlen(a) - 1;
    }
    int i = p;
    int j = 0;

    while (a[i] != '\0' && i <= q)
    {
        if (a[i] > 'z' || a[i] < 'A')
        {
            j++;
        }
        i++;
    }
    return j;
}
int n = l - 1;
int j;
int d = 0;
char t;

while (n >= 0)
{
    if ((a[n] <= 'z' || a[n] > 'A') && a[n] != 'a' && a[n] != 'e' && a[n] != 'i' && a[n] != 'o' && a[n] != 'u' && a[n] != 'A' && a[n] != 'E' && a[n] != 'I' && a[n] != 'O' && a[n] != 'U')
    {
        j = n;
        while (j + 1 != l - d)
        {
            t = a[j];
            a[j] = a[j + 1];
            a[j + 1] = t;
            j++;
        }
        d++;
    }
    n--;
}
}

void Elimina_consonanti(char a[])
{
    int i = 0;
    Consonanti_a_fine_stringa(a);
    while (a[i] != '\0')
    {
        if ((a[i] <= 'z' || a[i] > 'A') && a[i] != 'a' && a[i] != 'e' && a[i] != 'i' && a[i] != 'o' && a[i] != 'u' && a[i] != 'A' && a[i] != 'E' && a[i] != 'I' && a[i] != 'O' && a[i] != 'U')
        {
            a[i] = '\0';
        }
        i++;
    }
}

int Conta_consonanti_porzione(char a[], int p, int q)
{
    if (p >= strlen(a) - 1 q > strlen(a) - 1 q <= p)
    {
        p = 0;
        q = strlen(a) - 1;
    }
    int i = p;
    int j = 0;

    while (a[i] != '\0' && i <= q)
    {
        if ((a[i] <= 'z' || a[i] > 'A') && a[i] != 'a' && a[i] != 'e' && a[i] != 'i' && a[i] != 'o' && a[i] != 'u' && a[i] != 'A' && a[i] != 'E' && a[i] != 'I' && a[i] != 'O' && a[i] != 'U')
        {
            j++;
        }
        i++;
    }
    return j;
}

void BubbleSort_consonanti_porzione(char a[], int p, int q)
{
    int i, j = 0;
    int v = Conta_consonanti_porzione(a, p, q);
    char t;
    if (p >= strlen(a) - 1 q >= strlen(a) - 1 q <= p)
    {
        p = 0;
        q = strlen(a) - 1;
    }

    while (v > 0)
    {
        i = p;
        while (i < q)
        {
            j = 1;
            if ((a[i] <= 'z' || a[i] > 'A') && a[i] != 'a' && a[i] != 'e' && a[i] != 'i' && a[i] != 'o' && a[i] != 'u' && a[i] != 'A' && a[i] != 'E' && a[i] != 'I' && a[i] != 'O' && a[i] != 'U')
            {
                while ((a[i + j] > 'z' a[i + j] <= 'A')(a[i + j] == 'a' a[i + j] == 'e' a[i + j] == 'i' a[i + j] == 'o' a[i + j] == 'u' && a[i + j] == 'A' && a[i + j] == 'E' a[i + j] == 'I' a[i + j] == 'O' || a[i + j] == 'U') && i + j <= q)
                {
                    j++;
                }
                if ((a[i + j] <= 'z' || a[i + j] > 'A') && a[i + j] != 'a' && a[i + j] != 'e' && a[i + j] != 'i' && a[i + j] != 'o' && a[i + j] != 'u' && a[i + j] != 'A' && a[i + j] != 'E' && a[i + j] != 'I' && a[i + j] != 'O' && a[i + j] != 'U')
                {
                    if (a[i] > a[i + j])
                    {
                        t = a[i + j];
                        a[i + j] = a[i];
                        a[i] = t;
                    }
                    i = i + j - 1;
                }
            }
            i++;
        }
        q = i;
        v--;
    }
}

void Consonanti_ripetute_a_fine_stringa(char a[])
{
    int i = 0;
    int j;
    int t;
    int l;
    int d = 0;
    int n = strlen(a);
    while (i < n)
    {
        while (((a[i] > 'z' a[i] <= 'A')(a[i] == 'a' a[i] == 'e' a[i] == 'i' a[i] == 'o' a[i] == 'u' a[i] == 'A' a[i] == 'E' a[i] == 'I' a[i] == 'O' || a[i] == 'U')) && i < n)
        {
            i++;
        }
        j = i + 1;
        d = 0;
        while (j < n - d)
        {
            if (a[j] == a[i])
            {
                l = j;
                while (l < n - d - 1)
                {
                    t = a[l];
                    a[l] = a[l + 1];
                    a[l + 1] = t;
                    l++;
                }
                d++;
            }
            j++;
            if (a[j - 1] == a[i])
            {
                j--;
            }
        }
        i++;
    }
}

void Elimina_consonanti_ripetute(char a[])
{
    int i = 0;
    int j = 1;
    int n = strlen(a);
    Consonanti_ripetute_a_fine_stringa(a);
    while (a[j] != a[i])
    {
        j++;
        if (j == n)
        {
            i++;
            j = i + 1;
        }
    }
    a[j] = '\0';
}

/*
 * CARATTERI SPECIALI
 * */

void Caratteri_speciali_a_inizio_stringa(char a[])
{
    int i = 0;
    int j;
    int d = 0;
    char t;

    while (a[i] != '\0')
    {
        if ((a[i] > 'z' || a[i] < 'A') && a[i] != '0' && a[i] != '1' && a[i] != '2' && a[i] != '3' && a[i] != '4' && a[i] != '5' && a[i] != '6' && a[i] != '7' && a[i] != '8' && a[i] != '9')
        {
            j = i;
            while (j != d)
            {
                t = a[j];
                a[j] = a[j - 1];
                a[j - 1] = t;
                j--;
            }
            d++;
        }
        i++;
    }
}

void Caratteri_speciali_a_fine_stringa(char a[])
{
    int i = 0;
    int l = strlen(a);
    int n = l - 1;
    int j;
    int d = 0;
    char t;

    while (n >= 0)
    {
        if ((a[i] > 'z' || a[i] < 'A') && a[i] != '0' && a[i] != '1' && a[i] != '2' && a[i] != '3' && a[i] != '4' && a[i] != '5' && a[i] != '6' && a[i] != '7' && a[i] != '8' && a[i] != '9')
        {
            j = n;
            while (j + 1 != l - d)
            {
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
                j++;
            }
            d++;
        }
        n--;
    }
}

void Elimina_caratteri_speciali(char a[])
{
    int i = 0;
    Caratteri_speciali_a_fine_stringa(a);
    while (a[i] != '\0')
    {
        if ((a[i] > 'z' || a[i] < 'A') && a[i] != '0' && a[i] != '1' && a[i] != '2' && a[i] != '3' && a[i] != '4' && a[i] != '5' && a[i] != '6' && a[i] != '7' && a[i] != '8' && a[i] != '9')
        {
            a[i] = '\0';
        }
        i++;
    }
}

int Conta_caratteri_speciali_porzione(char a[], int p, int q)
{
    if (p >= strlen(a) - 1 q > strlen(a) - 1 q <= p)
    {
        p = 0;
        q = strlen(a) - 1;
    }
    int i = p;
    int j = 0;

    while (a[i] != '\0' && i <= q)
    {
        if ((a[i] > 'z' || a[i] < 'A') && a[i] != '0' && a[i] != '1' && a[i] != '2' && a[i] != '3' && a[i] != '4' && a[i] != '5' && a[i] != '6' && a[i] != '7' && a[i] != '8' && a[i] != '9')
        {
            j++;
        }
        i++;
    }
    return j;
}

/*
 * CARATTERI NON ALFABETICI
 * */

void Caratteri_non_alfabetici_a_inizio_stringa(char a[])
{
    int i = 0;
    int j;
    int d = 0;
    char t;

    while (a[i] != '\0')
    {
        if (a[i] > 'z' || a[i] < 'A')
        {
            j = i;
            while (j != d)
            {
                t = a[j];
                a[j] = a[j - 1];
                a[j - 1] = t;
                j--;
            }
            d++;
        }
        i++;
    }
}

void Caratteri_non_alfabetici_a_fine_stringa(char a[])
{
    int i = 0;
    int l = strlen(a);
    int n = l - 1;
    int j;
    int d = 0;
    char t;

    while (n >= 0)
    {
        if (a[i] > 'z' || a[i] < 'A')
        {
            j = n;
            while (j + 1 != l - d)
            {
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
                j++;
            }
            d++;
        }
        n--;
    }
}

void Elimina_caratteri_non_alfabetici(char a[])
{
    int i = 0;
    Caratteri_non_alfabetici_a_fine_stringa(a);
    while (a[i] != '\0')
    {
        if (a[i] > 'z' || a[i] < 'A')
        {
            a[i] = '\0';
        }
        i++;
    }
}

int Conta_caratteri_non_alfabetici_porzione(char a[], int p, int q)
{
    if (p >= strlen(a) - 1 q > strlen(a) - 1 q <= p)
    {
        p = 0;
        q = strlen(a) - 1;
    }
    int i = p;
    int j = 0;

    while (a[i] != '\0' && i <= q)
    {
        if (a[i] > 'z' || a[i] < 'A')
        {
            j++;
        }
        i++;
    }
    return j;
}