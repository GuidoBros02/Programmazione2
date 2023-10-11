//ESAME 24 LUGLIO 2020, secondo turno

// Esercizio 1

/*
Scrivere una funzione iterativa che prende in input due liste. Costruisca e restituisca in output una nuova lista ocntenente i nodi in eccedenza
Della lista più lunga. Se sono di uguale lunghezza, si restituisca una lista vuota.

Analizzare la complessità in tempo e spazio della funzione proposta

Esenpio:
L1: 1->1->2->1->7->1->2
l2> 2->2->1->2->1->1->1->1->1->8

output L3: 1->1->8
*/

//codice

#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int d;
    struct Node*next;
}node;
typedef node*LINK;

LINK f1(LINK l1, LINK l2)
{
    LINK testa, coda, temp;
    testa=NULL;
    coda=NULL;

    while(l1!=NULL && l2!=NULL)
    {
        l1=l1->next;
        l2=l2->next;
    }
    while(l2!=NULL)
    {
        temp=new();
        temp->d=l2->d;
        temp->next=NULL;

        if(testa==NULL)
        {
            testa=temp;
            coda=temp;
        }
        else
        {
            coda->next=temp;
            coda=coda->next;
        }
        l2=l2->next;
    }
    while(l1!=NULL)
    {
        temp=new();
        temp->d=l1->d;
        temp->next=NULL;

        if(testa==NULL)
        {
            testa=temp;
            coda=temp;
        }
        else
        {
            coda->next=temp;
            coda=coda->next;
        }
        l1=l1->next;
    }
    return testa;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Esercizio 2

/*
Scrivere una funzione ricorsiva che prende in input una lista e un intero k. Si cancelli dalla lista
il primo nodo che ha valore k se esiste nella lista.

Analizzare la complessità in tempo e spazio della funzione proposta

Eemempio:
L1: 11->1->3->9->7->10->4
K:10

L1: 11->1->3->9->7->4
*/

//Codice

#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int d;
    struct Node*next;
}node;
typedef node*LINK;

void f2(LINK*lista, int k)
{
    LINK p;

    if(*lista!=NULL)
    {
        if((*lista)->d==k)
        {
            p=(*lista);
            (*lista)=(*lista)->next;
            free(p);
        }
        else
        {
            f2(&((*lista)->next), k);
        }
    }
}