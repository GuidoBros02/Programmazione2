/*Scrivere un programma che riceve come argomenti un nome file e un numero che deve essere
compreso tra 1 e 9; il file di testo ricevuto per argomento contiene una serie di numeri interi. Il
programma deve leggere i dati nel file, salvarli in una lista, visualizzare la lista, cancellare dalla lista
tutti i nodi contenenti valori divisibili per il numero ricevuto come argomento e visualizzare la lista
aggiornata.
Scrivere quindi le seguenti funzioni:
1) lista_leggi_file: dato un puntatore a file, crea una lista con i dati nel file stesso; la funzione deve
essere iterativa;
2) lista_visualizza: visualizza la lista; la funzione deve essere ricorsiva;
3) lista_divisibili: data la testa della lista e un numero, cancella dalla lista i nodi contenenti valori
divisibili per il numero ricevuto (0 compreso); la funzione deve essere iterativa.
4) main: per gestire gli argomenti del programma, le funzioni di cui sopra e mostrare a video i risultati.
Suggerimento: utilizzare la funzione int atoi(char *str) per convertire il secondo argomento
del programma in numero intero.*/

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
int divisibili(LINK*lista, int x);
void cancella(LINK*lista, LINK posizione);

int main(int argc, char*argv[])
{
    if(argc!=2)
    {
        printf("Errore, inserire il nome di un file.\n");
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
            int val=0;
            int div=0;
            cr=crea(fp, &lis);
            printf("\nLista creata con %d nodi.\n", cr);
            visualizza(lis);
            printf("\nInserire valore: ");
            scanf("%d", &val);
            div=divisibili(&lis, val);
            printf("\nEliminazione di %d valori divisibili di %d eseguita.\n", div, val);
            visualizza(lis);
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
        printf("Errore nella creazione della lista.\n");
        return;
    }
    else
    {
        p->d=valore;
        p->next;

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

int divisibili(LINK*lista, int x)
{
    int n=0;
    LINK d1=*lista;
    LINK d2=NULL;

    while(d1!=NULL)
    {
        if((d1->d)%x==0)
        {
            d2=d1;
            d1=d1->next;
            cancella(lista, d2);
            n++;
        }
        else
        {
            d1=d1->next;
        }
    }
    return n;
}

void cancella(LINK*lista, LINK posizione)
{
    LINK c1=*lista;
    LINK c2=NULL;

    if(*lista!=NULL)
    {
        if(c1==posizione)
        {
            *lista=c1->next;
            free(c1);
        }
        else
        {
            while(c1->next!=NULL && c1!=posizione)
            {
                c2=c1;
                c1=c1->next;
            }
            if(c1->next==NULL && c1==posizione)
            {
                c2->next=NULL;
                free(c1);
            }
            else
            {
                c2->next = c1->next;
                free(c1);
            }
        }
    }
}