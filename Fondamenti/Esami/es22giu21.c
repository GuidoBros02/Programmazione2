/*Esercizio 1
Scrivere una funzione iterativa che data una lista in input e un intero k, calcoli la media dei primi k nodi nella
lista. Si analizzi e motivi la complessità in spazio e in tempo.
Es:     5->3->7->1>2->NULL 
        k = 3 
        output 5
*/
#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int d;
    struct Node*next;
}node;
typedef node*LINK;

int media(LINK lista, int k)
{
    int somma=0;
    int media=0;
    int pos=0;

    while(lista!=NULL)
    {
        if(pos<k)
        {
            somma=somma+lista->d;
            pos++;
        }
        lista=lista->next;
    }
    media=somma/pos;
    return media;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*Esercizio2
Scrivere una funzione ricorsiva che prenda in input una lista e un intero k positivo e che cancelli dalla lista tutti
i nodi a valore k, solo se sono in una posizione pari. Si analizzi e motivi la complessità in spazio e in tempo.
Es: 5->3->7->1->3->NULL 
    k = 3 
    Risultato 5->7->1->3->NULL
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int d;
    struct Node*next;
}node;
typedef node*LINK;

void funzione(LINK*lista, int k, int pos)
{
    LINK p;
    if(*lista!=NULL)
    {
        if((*lista)->d==k && pos%2==0)
        {
            p=*lista;
            (*lista)=(*lista)->next;
            free(p);
            funzione(&(*lista), k, pos+1);
        }
        else
        {
            funzione(&(*lista)->next, k, pos+1);
        }
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*Esercizio 3
Descrivere l’algoritmo di ordinamento QuickSort, analizzando gli aspetti relativi al funzionamento e la sua
complessità.
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int d;
    struct Node*next;
}node;
typedef node*LINK;

void QuickSort(int A[], int p, int r)
{
    int q;

    if(p<r)
    {
        q=Partition(A, p, r);
        QuickSort(A, p, q-1);
        QuickSort(A, q+1, r);
    }
}

int Partition (int A[], int p, int r)
{
    int i;
    int pivot;
    int pivotpos;

    swap(p, (p+r)/2, A);
    pivot=A[p];
    pivotpos=p;

    for(i=p+1; i<=r; i++)
    {
        if(A[i]<pivot)
        {
            swap(++pivotpos, i, A);
        }
    }
    swap(p, pivotpos, A);
    return pivotpos;
}

void swap(int i, int j, int A[])
{
    int tmp;
    tmp=A[i];
    A[i]=A[j];
    A[j]=tmp;
}

/*
Complessità in spazio:
    - C migliore: O(Log2n)
    - C peggiore: O(n)

Complessità in tempo:
    - C migliore: O(nlog2n) [n, (2*n)/2, (4*n)/4, [...]]
    - C peggiore: O(n^2)    [n+(n-1)+(n-2) [...]-> n(n+1)/2]
*/