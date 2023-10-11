/*
Scrivere un programma che riceve per argomento un nome file e un carattere.
Il file di testo ricevuto in input contiene una serie di nomi la cui dimensione massima può essere
42 caratteri.
Il contenuto del file deve essere inserito in una lista, visualizzato, quindi sarà necessario
eliminare dalla lista i nodi le cui stringhe iniziano con il carattere ricevuto per argomento e
scrivere un nuovo file con la lista senza le stringhe cancellate.
Scrivere quindi le seguenti funzioni:
1) lista_crea: dato un puntatore a un file, restituisce una lista con le stringhe nel file; la funzione
deve essere iterativa;
2) lista_visualizza: visualizza la lista; la funzione deve essere ricorsiva;
3) lista_lunghezza: restituisce il numero di nodi nella lista; la funzione deve essere ricorsiva;
4) lista_cancella: riceve in input la lista e il carattere; la funzione deve cancellare tutti i nodi le
cui stringhe iniziano per il carattere ricevuto; la funzione deve essere iterativa;
5) lista_scrivi: riceve in input la lista e la scrive sul file; la funzione deve essere iterativa;
6) main: per gestire le funzioni di cui sopra e mostrare a video i risultati.
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define DIM 43

typedef struct Node
{
    char parola[DIM];
    struct Node*next;
}node;
typedef node*LINK;

void crea(FILE*f, LINK*lista);
void inserisci(LINK*lista, char stringa[DIM]);
void visualizza(LINK lista);
int lunghezza(LINK lista);
void cancella(LINK*lista, char iniziale);
void delete(LINK*lista, LINK posizione);
void scrivi(FILE*f, LINK lista);

int main(int argc, char*argv[])
{
    if(argc!=2)
    {
        printf("Errore iserire nome di un file.\n");
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
            int lun=0;
            char ini;
            LINK lis=NULL;
            crea(fp, &lis);
            printf("\nLista creata.\n");
            visualizza(lis);
            lun=lunghezza(lis);
            printf("\nLa lista è lunga %d nodi.\n", lun);
            printf("\nInserire un iniziale per la cancellazione: ");
            scanf("%c", &ini);
            cancella(&lis, ini);
            printf("\nParole con iniziale %c cancellate.\n", ini);
            visualizza(lis);
            FILE*fp2=fopen("risultati.txt", "w");
            scrivi(fp2, lis);
            printf("\nLista aggiornata stampata sul file.\n");
        }
    }
    return 0;
}

void crea(FILE*f, LINK*lista)
{
    char str[DIM];

    while(fscanf(f, "%s", str)!=EOF)
    {
        inserisci(lista, str);
    }
}

void inserisci(LINK*lista, char stringa[DIM])
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
        strcpy(p->parola, stringa);
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
        printf("%s -> ", lista->parola);
        visualizza(lista->next);
    }
}

int lunghezza(LINK lista)
{
    int n=0;

    while(lista!=NULL)
    {
        {
            n++;
        }
        lista=lista->next;
    }
    return n;
}

void cancella(LINK*lista, char iniziale)
{
    LINK t1=*lista;
    LINK t2=NULL;

    while(t1!=NULL)
    {
        if((t1->parola[0])==iniziale)
        {
            t2=t1;
            t1=t1->next;
            delete(lista, t2);
        }
        else
        {
            t1=t1->next;
        }
    }
}

void delete(LINK*lista, LINK posizione)
{
    LINK d1=*lista;
    LINK d2=NULL;

    if(*lista!=NULL)
    {
        if(*lista==posizione)
        {
            *lista=d1->next;
            free(d1);
        }
        else
        {
            while(d1->next!=NULL && d1!=posizione)
            {
                d2=d1;
                d1=d1->next;
            }
            if(d1->next==NULL && d1==posizione)
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

void scrivi(FILE*f, LINK lista)
{
    while(lista!=NULL)
    {
        fprintf(f, "%s\n", lista->parola);
        lista=lista->next;
    }
}
