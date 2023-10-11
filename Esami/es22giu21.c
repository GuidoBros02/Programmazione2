/*Scrivere un programma che riceve per argomento un nome file; il file di testo ricevuto per
argomento contiene il codice scuola (al massimo 5 caratteri), il nome della scuola (al
massimo 32 caratteri) e la temperatura misurata nel mese corrente (un numero in virgola
mobile).
Il programma deve quindi: leggere i dati dal file, inserirli in una lista, visualizzare la lista,
indicare la lunghezza della lista, visualizzare la temperatura massima e cancellare dalla lista
i nodi con temperatura strettamente inferiore a 20.
Scrivere quindi le seguenti funzioni:
1) lista_leggi_da_file: dato un puntatore al file e la testa della lista per riferimento, crea una
lista con i dati nel file stesso e restituisce il numero di nodi creati; la funzione deve essere
iterativa;
2) lista_visualizza: visualizza la lista con i dati in forma tabulata; la funzione deve essere
ricorsiva;
3) lista_massimo: data la testa della lista, determina il valore massimo; la funzione deve
essere ricorsiva;
4) lista_cancella: data la testa della lista per riferimento, la funzione cancella i nodi con
valori strettamente inferiori a 20;
5) main: per gestire le funzioni di cui sopra e mostrare a video i risultati.*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Node
{
    char codice[6];
    char nome[33];
    float temperatura;
    struct Node*next;
}node;
typedef node*LINK;

int crea(FILE*f, LINK*lista);
void inserisci(LINK*lista, char cod[], char nom[], float tem);
void visualizza(LINK lista);
void massimo(LINK lista, float*max);
void cancella(LINK*lista);
void delete(LINK*lista, LINK pos);

int main(int argc, char*argv[])
{
    if(argc!=2)
    {
        printf("Errore, inserire nome di un file.\n");
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
            LINK lis=NULL;
            int cr=0;
            float m;

            cr=crea(fp, &lis);
            printf("\nLista creata con %d nodi.\n", cr);
            visualizza(lis);
            massimo(lis, &m);
            printf("\nIl valore massimo della lista è %1.f\n", m);
            cancella(&lis);
            printf("\nLista senza temperature sotto i 20 gradi\n");
            visualizza(lis);
            printf("\n");
        }
    }
    return 0;
}

int crea(FILE*f, LINK*lista)
{
    int n=0;
    char co[6];
    char no[33];
    float te;

    while(fscanf(f, "%s %s %f", co, no, &te)!=EOF)
    {
        inserisci(lista, co, no, te);
        n++;
    }
    return n;
}

void inserisci(LINK*lista, char cod[], char nom[], float tem)
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
        strcpy(i1->codice, cod);
        strcpy(i1->nome, nom);
        i1->temperatura=tem;
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
        printf("\n");
    }
    else
    {
        printf("%s %s %.1f\n", lista->codice, lista->nome, lista->temperatura);
        visualizza(lista->next);
    }
}

void massimo(LINK lista, float*max)
{
    if(lista!=NULL)
    {
        if((lista->temperatura)>(*max))
        {
            *max=lista->temperatura;
        }
        massimo(lista->next, max);
    }
}

void cancella(LINK*lista)
{
    LINK c1=*lista;
    LINK c2=NULL;

    while(c1!=NULL)
    {
        if((c1->temperatura)<20)
        {
            c2=c1;
            c1=c1->next;
            delete(lista, c2);
        }
        else
        {
            c1=c1->next;
        }
    }
}

void delete(LINK*lista, LINK pos)
{
    LINK d1=*lista;
    LINK d2=NULL;

    if(*lista!=NULL)
    {
        if (*lista==pos)
        {
            *lista=d1->next;
            free(d1);
        }
        else
        {
            while(d1->next!=NULL && d1!=pos)
            {
                d2=d1;
                d1=d1->next;
            }
            if (d1->next==NULL && d1==pos)
            {
                d2->next=NULL;
                free(d1);
            }
            else
            {
                d2->next=d1->next;
                free(d1);
            }
        }
    }
}