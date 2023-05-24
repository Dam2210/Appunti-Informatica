#include <stdio.h>

struct punto /* Creo un 'ogetto' punto tramite la funzione struct al cui interno sono memorizzati vari campi*/
{
    /* elenco dei campi */
    char nome;
    float x, y;
    float z;
};

/* typedef int intero; Definisco un nuovo tipo di dato per 'int', posso usare 'intero' al posto di 'int' */
typedef struct punto punto; /* Posso usare 'punto' al posto di 'struct punto' */


void print_punto (punto p)
{
    printf("%c: (%f, %f, %f)\n", p.nome, p.x, p.y, p.z);
}

void main()
{

    struct punto p0, p2 = {'C', 0, 0, 0}; /* Creo p0 e p1 con tipo struct punto */
    /* intero a = 2; Uso il tipo definito da me intero al posto di int 
    int b = 6; Uso int normalmente 
    printf("%d, %d\n", a, b); */

    punto p1;
    punto *pp = &p0; /* Assegno al puntatore pp l'indirizzo occupato dalla variabile p0 di tipo punto */
                     /* pp prende esattamente gli stessi valori di p0, pp punta ai valori memorizzati in p0 */
                     /* *pp è proprio p0 */

    p0.nome = 'A'; /* Modifico il campo nome della struct p0 */
    p0.x = 3.14;
    p0.y = 2.71;
    p0.z = 0;

    p1 = p0;
    p1.nome = 'B';
    p1.z = 1;

    print_punto(p0);
    print_punto(p1);
    print_punto(p2);
    /* p3 = {'D', 1, 2, 3}; questa definizione dei campi si può fare solo nell'inizializzazione della struct*/

    /* Accesso ai campi utilizzando puntatore a struct */
    printf("pp campo x: %f; pp campo y: %f\n", (*pp).x, pp->y); 

}