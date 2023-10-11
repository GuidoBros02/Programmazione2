// Esame prima sessione 2020, primo turno

/* Esercizio 1

Scrivere una funzione in iterazione che presa in input una lista e 
un intero x. Cancellare tutti i nodi che hanno valore multiplo di x 
e restituisca come output il numero di nodi cancellati

Si analizzi la complessità in tempo e spazio della funzione proposta

Esempio: 
L1: 2->2->5->6->7->9
X 2
Viene modificata in: L1 5->7->9
output 3
*/

// Funzione

#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int d;
    struct Node*next;
}node;
typedef node*LINK;

int f1(LINK *lista, int x)
{
    int cnt=0;
    LINK p;
    LINK q;
    int flag=0;

    while(*lista!=NULL && flag==0)
    {
        if((*lista)->d%x==0)
        {
            p=*lista;
            *lista=(*lista)->next;
            free(p);
            cnt++;
        }
        else
        {
            flag=1;
        }
    }
    p=*lista;

    if(p!=NULL)
    {
        while(p->next!=NULL)
        {
            if(p->next->d%x==0)
            {
                q=p->next;
                p->next=q->next;
                free(p);
                cnt++;
            }
            else
            {
                p=p->next;
            }
        }
    }
    return cnt;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*  Esercizio 2

Scrivere una funzione in ricorsione che prende in input due liste e 
un intero n. Calcoli se dopo la posizione n le due liste sono  uguali
(cioè hanno in nodi corrispondenti la stessa parte dati). 
Restituisca 1 in caso affermativo o 0 in negativo.

Si analizzi la complessità in tempo e spazio della funzine

Esempio
L1 2->2->5->6->7->9
L2 2->51->16->6->7->9
N 3
Output 1
*/

// Funzione

#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int d;
    struct Node*next;
}node;
typedef node*LINK;

LINK f2(LINK l1, LINK l2)
{
    LINK p;
    LINK testa=NULL; 
    LINK coda=NULL;

    while((l1!=NULL) && (l2!=NULL))
    {
        p=new();
        {
            p->d=l1->d+l1->d;
            p->next=NULL;

            if(testa==NULL)
            {
                testa=p;
                coda=p;
            }
            else
            {
                coda->next=p;
                coda=p;
            }
            l1=l1->next;
            l2=l2->next;
        }
    }
    while(l1!=NULL)
    {
        p=new();
        p->d=l1->d;
        p->next=NULL;

        if(testa==NULL)
        {
            testa=p;
            coda=p;
        }
        else
        {
            coda->next=p;
            coda=p;
        }
        l1=l1->next;
    }
    while(l2!=NULL)
    {
        p=new();
        p->d=l2->d;
        p->next=NULL;

        if(testa==NULL)
        {
            testa=p;
            coda=p;
        }
        else
        {
            coda->next=p;
            coda=p;
        }
        l2=l2->next;
    }
    return testa;
}