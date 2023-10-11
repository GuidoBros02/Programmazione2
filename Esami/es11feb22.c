/*Scrivere un programma che riceve per argomento un nome file; il file di testo ricevuto per argomento
contiene una serie di numeri interi (positivi e negativi). Il programma deve leggere i dati nel file,
salvarli in una lista, visualizzarla, calcolare la media dei numeri positivi della lista, creare una
seconda lista con i nodi che superano tale media.
Sviluppare quindi le seguenti funzioni:
1) int lista_leggi_file: dato un puntatore al file e il riferimento a una lista, crea una lista con i dati
contenuti nel file e restituisce il numero di nodi creati; la funzione deve essere iterativa;
2) void lista_visualizza: visualizza la lista; la funzione deve essere ricorsiva;
3) void media_positivi: data la testa della lista, calcola la media dei valori positivi contenuti nella
lista; la funzione deve essere ricorsiva; si noti che lo 0 non è un numero positivo;
4) int lista_oltre_media: data la testa della prima lista, crea una seconda lista con i soli nodi positivi
che superano strettamente la media calcolata al punto 3); la funzione deve restituire il numero di
nodi creati; la funzione deve essere iterativa.
5) int main: per richiamare le funzioni di cui sopra e mostrare a video i risultati*/

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
float media(LINK lista, float*s, float*c);
int oltre(LINK lista, LINK*lista2, int med);

int main(int argc, char*argv[])
{
    if(argc!=2)
    {
        printf("Inserire nome del file.\n");
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

            int cr=0, ol=0;
            float me=0, me1=0, me2=0;

            cr=crea(fp, &lis1);
            printf("\nLista creata con %d nodi.\n", cr);
            visualizza(lis1);
            me=media(lis1, &me1, &me2);
            printf("\nLa media della lista è %f\n", me);
            ol=oltre(lis1, &lis2, me);
            printf("\nEliminati %d valori oltre la media.\n", ol);
            printf("\nVisualizzazione della lista aggiornata: ");
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
    LINK p=(LINK)malloc(sizeof(node));
    LINK temp=*lista;

    if(p==NULL)
    {
        printf("Errore nella creazione del nodo.\n");
        return;
    }
    else
    {
        p->d=valore;
        p->next=NULL;

        if(*lista==NULL)
        {
            *lista=p;
        }
        else
        {
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=p;
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

float media(LINK lista, float*s, float*c)
{
    if(lista==NULL)
    {
        return(*s)/(*c);
    }
    else
    {
        if((lista->d)>0)
        {
            (*s)+=lista->d;
            (*c)++;
            return media(lista->next, s, c);
        }
    }
}

int oltre(LINK lista, LINK*lista2, int med)
{
    int n=0;

    while(lista!=NULL)
    {
        if((lista->d)>med)
        {
            inserisci(lista2, lista->d);
            n++;
        }
        lista=lista->next;
    }
    return n;
}
