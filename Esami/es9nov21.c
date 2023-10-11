/*Scrivere un programma che riceve per argomento un nome file; il file di testo ricevuto per argomento
contiene una serie di numeri interi (positivi e negativi). Il programma deve leggere i dati nel file, salvarli
in una lista, visualizzarla, cancellare i numeri negativi dalla lista e calcolare la media dei numeri pari
contenuti nella lista (considerando lo 0 come pari).
Scrivere quindi le seguenti funzioni:
1) int lista_leggi_file: dato un puntatore al file e il riferimento a una lista, crea una lista con i dati
contenuti nel file e restituisce il numero di nodi creati; la funzione deve essere iterativa;
2) void lista_visualizza: visualizza la lista; la funzione deve essere ricorsiva;
3) int lista_negativi: data la testa della lista per riferimento, cancella dalla lista i nodi contenenti
numeri negativi e restituisce il numero di nodi cancellati; la funzione deve essere iterativa;
4) float lista_pari: data la testa della lista, calcola la media dei nodi contenenti valori pari
(considerando lo 0 come pari). La funzione deve essere ricorsiva.
5) int main: per richiamare le funzioni di cui sopra e mostrare a video i risultati.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int d;
    struct Node *next;
} node;
typedef node *LINK;

int crea(FILE *f, LINK *lista);
void inserisci(LINK *lista, int valore);
void visualizza(LINK lista);
int negativi(LINK *lista);
void cancella(LINK *lista, LINK posizione);
float pari(LINK lista, float *s, float *c);

int main(int argc, char *argv[1])
{
    if (argc != 2)
    {
        printf("Errore, inserire il nome di un file.\n");
        return 1;
    }
    else
    {
        FILE *fp = fopen(argv[1], "r");

        if (fp == NULL)
        {
            printf("Errore nell'apertura del file.\n");
            return 1;
        }
        else
        {
            LINK lis = NULL;
            int cr = 0;
            int ne = 0;
            float me = 0, s1 = 0, c1 = 0;
            cr = crea(fp, &lis);
            printf("\nLista creata con %d nodi al suo interno.\n", cr);
            visualizza(lis);
            ne = negativi(&lis);
            printf("\nValore negativi (%d) cancellati dalla lista.\n", ne);
            visualizza(lis);
            me = pari(lis, &s1, &c1);
            printf("\nLa media dei valori pari nella lista è %1.f\n\n", me);
        }
    }
    return 0;
}

int crea(FILE *f, LINK *lista)
{
    int n = 0;
    int v;

    while (fscanf(f, "%d", &v) != EOF)
    {
        n++;
        inserisci(lista, v);
    }
    return n;
}

void inserisci(LINK *lista, int valore)
{
    LINK p = (LINK)malloc(sizeof(LINK));
    LINK temp = *lista;

    if (p == NULL)
    {
        printf("Errore nella creazione del nodo.\n");
        return;
    }
    else
    {
        p->d = valore;
        p->next = NULL;

        if (*lista == NULL)
        {
            *lista = p;
        }
        else
        {
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = p;
        }
    }
}

void visualizza(LINK lista)
{
    if (lista == NULL)
    {
        printf("NULL\n");
    }
    else
    {
        printf("%d -> ", lista->d);
        visualizza(lista->next);
    }
}

int negativi(LINK *lista)
{
    int n = 0;
    LINK n1 = *lista;
    LINK n2 = NULL;

    while (n1 != NULL)
    {
        if ((n1->d) < 0)
        {
            n2 = n1;
            n1 = n1->next;
            cancella(lista, n2);
            n++;
        }
        else
        {
            n1 = n1->next;
        }
    }
    return n;
}

void cancella(LINK *lista, LINK posizione)
{
    LINK c1 = *lista;
    LINK c2 = NULL;
    
    if (c1 == posizione)
    {
        c1 = c1->next;
        free(c1);
    }
    else
    {
        while (c1->next != NULL && c1 != posizione)
        {
            c2 = c1;
            c1 = c1->next;
        }
        if (c1->next == NULL && c1 == posizione)
        {
            c2->next = NULL;
            free(c1);
        }
        else
        {
            c2->next = c1->next;
            free(c1);
        }
    }
}

float pari(LINK lista, float *s, float *c)
{
    if (lista == NULL)
    {
        return (*s) / (*c);
    }
    else
    {
        if ((lista->d) % 2 == 0)
        {
            (*s) += lista->d;
            (*c)++;
            return pari(lista->next, s, c);
        }
        else
        {
            return pari(lista->next, s, c);
        }
    }
}