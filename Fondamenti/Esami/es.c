/* Esercizio1
Funzine iterativa che restituisce la somma pesata per posizione dei 
numeri Della lista in posizione multipla di x

Esempio

L1: 3->2->5->3->6->7->4->2
x=2
Output=2*2+3*4+7*6+2*8=74
*/

// Codice
#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int d;
    struct Node*next;
}node;
typedef node*LINK;

int f1(LINK lista, int x)
{
    int pos;
    int sum;

    pos=1;
    sum=0;

    while(lista!=NULL)
    {
        if(pos%x==0)
        {
            sum=sum+(lista->d)*pos;
        }
        pos++;
        lista=lista->next;
    }
    return sum;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

/* Esercizio2

Funzione iterativa che restituisca, data una lista L1 in input, 
la differenza fra la somma dei nodi nelle prime n posizioni e 
quelli da posizione n+1 a posizione m(m>n) della lista.

Esempio
L1: 3->2->5->3->6->7->4->2
n: 3
m: 5
output: (3+2+5)-(3+6)=1
*/

// Codice
#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int d;
    struct Node*next;
}node;
typedef node*LINK;

int f2(LINK lista, int n)
{
    int pos=1;
    int prima=0;
    int dopo=0;

    while(lista!=NULL)
    {
        if(pos<=n)
        {
            prima+= lista->d;
        }
        else
        {
            dopo+= lista->d;
        }
        pos++;
        lista=lista->next;
    }
    return prima-dopo;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

/* Esercizio3

Funzione iterativa che, data una lista L1 ed un numero x, 
restituisce inoutput il numero di volte in cui x 
occorre tre volte di fila

Esempio
L1: 3->3->3->3->1->3->3->6->2->3->3->3->8
x=3
Output 3

nota: una sequenza di quattro conta come 2 sequenze lunghe 2, e così via.
*/

// Codice
#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int d;
    struct Node*next;
}node;
typedef node*LINK;

int f3(LINK lista, int x)
{
    int n;
    n=0;

    if(lista==NULL)
    {
        return 0;
    }
    else if(lista->next==NULL)
    {
        return 0;
    }
    else if(lista->next->next==NULL)
    {
        return 0;
    }

    while(lista->next->next!=NULL)
    {
        if((lista->d==x) && (lista->next->d==x) && (lista->next->next->d==x))
        {
            n++;
        }
        lista=lista->next;
    }
    return n;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

/* Esercizio4

Funzione iterativa che, data una lista l1, un intero x ed una 
posizione n, inserisca in L1 una duplicazione di tutti i nodi 
contenuti x che sono in posizione multipla di n (in l1)

Esempio
L1: 2->3->1->6->1->2->2->6->1->5
x=1;
n:3;
Output L1: 2->3->1->1->6->1->2->2->6->1->1->5
*/

// Codice
#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int d;
    struct Node*next;
}node;
typedef node*LINK;

void f4(LINK lista, int x, int n)
{
    int pos=1;
    LINK p;

    while((lista)!=NULL)
    {
        if((lista->d==x) && (pos%n==0))
        {
            p=new();
            p->d=x;
            p->next=(lista)->next;
            lista->next=p;
            lista=lista->next->next;
        }
        else
        {
            lista=(lista)->next;
        }
        pos++;
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

/* Esercizio5 ricorsivo

Data una lista L1 definire una funzione ricorsiva in C che restituisca 
il numero di occorrenze del valore massimo della lista 
(se la lista è vuota, restituire 0).
si discuta la complessità in spazio ed in tempo della funzione

Esempio
L1: 4->4->23->8->6->23->86->86->86->4->86

Output 4
*/

// Codice
#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int d;
    struct Node*next;
}node;
typedef node*LINK;

int f5(LINK l1, int n, int max)
{
    if(l1==NULL)
    {
        return n;
    }
    else if(l1->d<max)
    {
        return f5(l1->next, n, max);
    }
    else if(l1->d==max)
    {
        return f5(l1->next, n+1, max);
    }
    else
    {
        return f5(l1->next, 1, l1->d);
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*Esercizio6 ricorsivo

Data una lista L1 definire una funzione ricorsiva in C che 1 se 
la lista è ordinata in modo strettamente crescente  
(ovvero u elemento è minore del successivo) altrimenti 0.

Esempio
L1: 4->5->23->80->86->86
Output 0

*/

// Codice
#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int d;
    struct Node*next;
}node;
typedef node*LINK;

int f6(LINK l1)
{
    if(l1==NULL)
    {
        return 1;
    }
    else if(l1->next==NULL)
    {
        return 1;
    }
    else if(l1->d<l1->next->d)
    {
        return f6(l1->next);
    }
    else
    {
        return 0;
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*Esercizio7 ricorsivo

Date due liste L1 e L2, definire una sequenza ricorsiva in C che 
calcoli il  numero di elementi uguali nella strassa posizione. 
Si discuti la complessità in spazio e tempo della funzione.

Esempio
L1: 3->42->23->17->8->16->1
L2: 3->42->20->17->2->1->2->16->7->2

Output 3

*/

// Codice
#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int d;
    struct Node*next;
}node;
typedef node*LINK;

int f7(LINK l1, LINK l2)
{
    int flag;
    if(l1!=NULL && l2!=NULL)
    {
        if(l1->d==l2->d)
        {
            return 1 + f7(l1->next, l2->next);
        }
        else
        {
            return f7(l1->next, l2->next);
        }
    }
    else
    {
        return 0;
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*Esercizio8 ricorsivo

Date due liste L1 e L2 definire una funzione ricorsiva in C 
(fino alla fine della più corta) che restituisca in in output 
una nuova lista (si utilizzi la funzione newnode) contentente, 
posizione per posizione, la differenza del nodo di L1 e di L2,
ma solo se tale valore è multipolo della posizione dei nodi

Esempio
L1: 3->4->3->7->8->6->1
L2: 1->4->2->7->2->12->2->16->7->2

Output: 2->0->0->6

*/

// Codice
#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int d;
    struct Node*next;
}node;
typedef node*LINK;

LINK f8(LINK l1, LINK l2, int pos)
{
    LINK p;
    int diff;

    if(l1!=NULL && l2!=NULL)
    {
        diff=l1->d - l1->d;
        if(diff%pos==0)
        {
            p=new();
            p->d=diff;
            p->next=f8(l1->next, l2->next, pos+1);
            return p;
        }
        else
        {
            return f8(l1->next, l2->next, pos+1);
        }
    }
    else
    {
        return NULL;
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*Eercizio 9 ricorsivo

Date due liste L1 ed L2 definire una funzione ricorsiva in C che 
restituisca in output una nuova lista, si utilizzi la funzione 
newelement. Posizione per posizione, il prodotto del nodo di L1 e L2, 
ma solo se la loro somma è multipla della posizione dei nodi.

Esempio
L1: 3->4->2->7->5->6->11->16->7->2
L2: 0->2->2->6->2->12->2

Output 0->8->10->72

*/

// Codice
#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int d;
    struct Node*next;
}node;
typedef node*LINK;

LINK f9(LINK l1, LINK l2, int pos)
{
    LINK p;
    if(l1!=NULL && l2!=NULL)
    {
        if((l1->d + l2->d)% pos==0)
        {
            p=new();
            p->d=l1->d*l1->d;
            p->next=f9(l1->next, l2->next, pos+1);
            return p;
        }
        else
        {
            return f9(l1->next, l2->next, pos+1);
        }
    }
    else
    {
        return NULL;
    }
}