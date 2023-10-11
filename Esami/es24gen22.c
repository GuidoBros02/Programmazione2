/*Scrivere un programma che riceve per argomento un nome file; il file di testo ricevuto per argomento
contiene una serie di numeri interi (positivi e negativi). Il programma deve leggere i dati nel file,
salvarli in una lista, visualizzarla, calcolare la media dei valori pari (considerando lo 0 come pari),
creare una seconda lista con i soli nodi negativi.
Sviluppare quindi le seguenti funzioni:
1) int lista_leggi_file: dato un puntatore al file e il riferimento a una lista, crea una lista con i dati
contenuti nel file e restituisce il numero di nodi creati; la funzione deve essere iterativa;
2) void lista_visualizza: visualizza la lista; la funzione deve essere ricorsiva;
3) double media_pari: data la testa della lista, restituisce la media dei valori pari contenuti nella
lista; la funzione deve essere ricorsiva;
4) int lista_negativi: data la testa della prima lista, crea una seconda lista con i soli nodi negativi;
la funzione deve restituire il numero di nodi creati; la funzione deve essere iterativa.
5) int main: per richiamare le funzioni di cui sopra e mostrare a video i risultati.
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int d;
    struct Node*next;
}node;
typedef node*LINK;

int crea(FILE*f, LINK*lista);
void inserisci(LINK*lista, int valore);
void visualizza(LINK lista);
double media(LINK lista, double*s, double*c);
int negativi(LINK lista, LINK*lista2);

int main(int argc, char*argv[])
{
    if(argc!=2)
    {
        printf("Errore, inserire nome del file.\n");
        return 1;
    }
    else
    {
        FILE*fp=fopen(argv[1], "r");

        if(fp==NULL)
        {
            printf("Errore nell'apertura del file.\n");
            return 1;
        }
        else
        {
            LINK lis1=NULL;
            LINK lis2=NULL;
            int cr, ne;
            double me=0, me1=0, me2=0;

            cr=crea(fp, &lis1);
            printf("\nLista creata con %d nodi.\n", cr);
            visualizza(lis1);
            me=media(lis1, &me1, &me2);
            printf("\nLa media della lista è %f\n", me);
            ne=negativi(lis1, &lis2);
            printf("\nLista con i numeri negativi generata con %d nodi.\n", ne);
            visualizza(lis2);
            printf("\n");
        }
    }
    return 0;
}

int crea(FILE*f, LINK*lista)
{
    int n=0;
    int v;

    while(fscanf(f, "%d", &v)!=EOF)
    {
        inserisci(lista, v);
        n++;
    }
    return n;
}

void inserisci(LINK*lista, int valore)
{
    LINK i1=(LINK)malloc(sizeof(node));
    LINK i2=*lista;

    if(i1==NULL)
    {
        printf("Errore nella creazione del nodo.\n");
        return;
    }
    else
    {
        i1->d=valore;
        i1->next=NULL;

        if(*lista==NULL)
        {
            *lista=i1;
        }
        else
        {
            while(i2->next!=NULL)
            {
                i2=i2->next;
            }
            i2->next=i1;
        }
    }
}

void visualizza(LINK lista)
{
    if(lista==NULL)
    {
        printf("NULL\n");
    }
    else
    {
        printf("%d -> ", lista->d);
        visualizza(lista->next);
    }
}

double media(LINK lista, double*s, double*c)
{
    if(lista!=NULL)
    {
        if((lista->d)%2==0)
        {
            (*s)+=lista->d;
            (*c)++;
        }
        media(lista->next, s, c);
    }
    else
    {
        return (*s)/(*c);
    }
}

int negativi(LINK lista, LINK*lista2)
{
    LINK n1=lista;
    int n=0;

    while(n1!=NULL)
    {
        if((n1->d)<0)
        {
            inserisci(lista2, n1->d);
            n++;
            n1=n1->next;
        }
        else
        {
            n1=n1->next;
        }
    }
    return n;
}
