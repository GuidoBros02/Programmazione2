// ESAME 27 LUGLIO

// Esercizio 1

/*
Scrivere una funzione iterativa che prende in input una lista e due interi positivi n e m (m<n).
Cancelli se esistono i nodi compresi tra la posizione n e la posizione m se esistono.

Analizzare la complessità in tempo ed in spazio della funzione

Esempio

L1: 1->1->2->1->7->1->2

n:2
m:5

L1: 1->1->2
*/

// Codice

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int d;
    struct Node *next;
} node;
typedef node *LINK;

void f1(LINK *lista, int m, int n)
{
    int pos = 1;
    LINK p;
    LINK q;

    if (m == 1)
    {
        while (*lista != NULL && pos < n)
        {
            p = *lista;
            *lista = (*lista)->next;
            free(p);
            pos++;
        }
    }
    else
        p = *lista;
    while ((pos < (m - 1)) && p != NULL)
    {
        pos++;
        p = (p)->next;
    }
    if (p != NULL)
    {
        while (pos < n && p->next != NULL)
        {
            q = p->next;
            p->next = q->next;
            free(q);
            pos++;
        }
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Esercizio 2

/*
Scrivere una funzione ricorsiva che prende in imput due liste. Calcoli la somma degli elementi di
ciascuna e restituisca in output il valore massimo tra i due. In caso di ugualianza tra le due somme
restituisca quel valore

Analizzare la complessità in tempo ed in spazio della funzione

Esempio

L1: 11->1->3->9->7->10->4
L2: 100->1->-1->2
output 104
*/

// Codice

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int d;
    struct Node *next;
} node;
typedef node *LINK;

int f2(LINK l1, LINK l2, int *cnt1, int *cnt2)          // con puntatore
{
    if (l1 != NULL && l2 != NULL)
    {
        *cnt1 += l1->d;
        *cnt2 += l2->d;

        return f2(l1->next, l2->next, cnt1, cnt2);
    }
    else if (l1 != NULL && l2 == NULL)
    {
        *cnt1 += l1->d;
        return f2(l1->next, l2, cnt1, cnt2);
    }
    else if (l1 == NULL && l2 != NULL)
    {
        *cnt2+=l2->d;
        return f2(l1, l2->next, cnt1, cnt2);
    }
    else
    {
        if(*cnt1>=*cnt2)
        {
            return*cnt1;
        }
        else
        {
            return*cnt2;
        }
    }
}

int f2(LINK l1, LINK l2, int cnt1, int cnt2)            // Senza puntatore
{
    if(l1!=NULL && l1!=NULL)
    {
        return f2(l1->next, l2->next, cnt1+l1->d, cnt2+l2->d);
    }
    else if(l1!=NULL && l2==NULL)
    {
        return f2(l1->next, l2, cnt1+l1->d, cnt2);
    }
    else if(l1==NULL && l2!=NULL)
    {
        return f2(l1, l2->next, cnt1, cnt2+l2->d);
    }
    else
    {
        if(cnt1>=cnt2)
        {
            return cnt1;
        }
        else
        {
            return cnt2;
        }
    }
}