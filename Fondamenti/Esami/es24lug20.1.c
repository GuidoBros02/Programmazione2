// Primo turno esame 24 luglio 2020

/* Esercizio1

Scrivere una funzione iterativa che prende in input restituisce la lunghezza della sequenza più lunga.
Analizzare la complessita in tempo ed in spazio della funzione proposta.

Esempio:
L1: 1->2->1->7->1->1->2->2->2->1->2->1->1->1->1->1->8

output 5
*/

// funzione

#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int d;
    struct Node *next;
}node;
typedef node* LINK;

int f1(LINK lista)
{
    int cnt, current, max;
    cnt = 0;
    max = 0;

    if (lista != NULL) // Inizializzazione
    {
        current = lista->d;
        cnt = 1;
        lista = lista->next;
    }
    while (lista != NULL) // Passo iterativo
    {
        if (lista->d == current)
        {
            cnt++;
        }
        else
        {
            if (cnt >= max)
            {
                max = cnt;
            }
            current = lista->d;
            cnt = 1;
        }
        lista = lista->next;
    }

    if (cnt >= max) // se gli ultimi elementi sono quelli di maggiore numerosità
    {
        max = cnt;
    }
    return max;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

/* Esercizio2

Srivere una funzione ricorsiva che prende in input una lista e un intero k positivo, cancelli dalla lista il nodo in posizione K se esiste.
Analizzare la complessità in tempo e in spazio della funzione proposta

Esempio:
L1: 11->1->3->9->7->1->4
K=6

l1= 11->1->3->9->7->4
*/

// Funzione

typedef struct Node
{
    int d;
    struct Node *next;
}node;
typedef node*LINK;

void f2(LINK*lista, int k, int cnt)
{
    LINK p;
    if (*lista != NULL)
    {
        if (k == 1)
        {
            p = *lista;
            (*lista) = (*lista)->next;
            free(p);
        }
        else
        {
            if (cnt == k - 1 && (*lista)->next != NULL)
            {
                p = (*lista)->next;
                (*lista)->next = (*lista)->next->next;
                free(p);
            }
            else
            {
                f2(&((*lista)->next), k, cnt+1);
            }
        }
    }
}