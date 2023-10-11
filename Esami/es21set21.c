/*Scrivere un programma che riceve per argomento un nome file; il file di testo ricevuto per
argomento contiene una serie di numeri interi. Il programma deve leggere i dati nel file, salvarli in
una lista, visualizzare la lista, generare una seconda lista con i numeri pari della prima lista (0
compreso) e visualizzare la somma degli elementi della seconda lista.
Scrivere quindi le seguenti funzioni, rispettando nomi delle funzioni ed i parametri specificati:
1) lista_leggi_file: dato un puntatore a file e la testa della prima lista per riferimento, crea la lista
con i dati nel file e restituisce il numero di nodi creati; la funzione deve essere iterativa;
2) lista_visualizza: data la testa di una lista, visualizza tale lista lista separando i valori dei nodi con
->; la funzione deve essere ricorsiva;
3) lista_pari: data la testa della prima lista, crea una nuova lista contenente i valori pari (0
compreso) della prima lista e restituisce la testa della nuova lista; la funzione deve essere iterativa.
4) lista_pari_somma: data la testa della seconda lista (con i valori pari), restituisce la somma dei
valori contenuti nella lista. La funzione deve essere ricorsiva.
5) main: per gestire le funzioni di cui sopra e mostrare a video i risultati.*/

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
LINK pari(LINK lista);
int somma(LINK lista);

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

            int cr, so;

            cr=crea(fp, &lis1);
            printf("\nLista creata con %d nodi.\n", cr);
            visualizza(lis1);
            lis2=pari(lis1);
            printf("\nLista con soli numeri pari generata.\n");
            visualizza(lis2);
            so=somma(lis2);
            printf("\nLa somma della lista con i numeri pari è %d\n\n", so);
        }
    }
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

LINK pari(LINK lista)
{
    LINK testa=NULL;

    while(lista!=NULL)
    {
        if(lista->d%2==0)
        {
            inserisci(&testa, lista->d);
        }
        lista=lista->next;
    }
    return testa;
}

int somma(LINK lista)
{
    if(lista==NULL)
    {
        return 0;
    }
    else
    {
        return lista->d + somma(lista->next);
    }
}

