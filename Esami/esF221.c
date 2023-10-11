// Chiedere in input nel main una lettere
// Es. M
// Cancellare dalla lista tutti i nodi che hanno una stringa che inizia per la lettera letta in input
// Visualizzare la lista
// Andrea -> Gianna -> Susanna
// Scrivere la lista aggiornata sul file dati_aggiornati.txt

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define DIM 50

typedef struct Node
{
    char parola[50];
    struct Node*next;
}node;
typedef node*LINK;

int crea(FILE*f, LINK*lista);
void inserisci(LINK*lista, char s[DIM]);
void visualizza(LINK lista);
void cancella(LINK*lista, char l);
void delete(LINK*lista, LINK elimina);
void scrivi(FILE*f, LINK lista);

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
            printf("Errore con l'apertura del file.\n");
            return 1;
        }
        else
        {
            LINK lis=NULL;
            int cr;
            char iniziale;
            cr=crea(fp,&lis);
            printf("Lista creata con %d nodi.\n", cr);
            visualizza(lis);
            printf("Inserire iniziale per la cancellazione: ");
            scanf("%s", &iniziale);
            cancella(&lis, iniziale);
            printf("Lista aggiornata...\n");
            visualizza(lis);
            FILE*fp2=fopen("Risultati.txt", "w");
            scrivi(fp2, lis);
        }
    }
    return 0;
}

int crea(FILE*f, LINK*lista)
{
    char stringa[50];
    int n=0;

    while(fscanf(f, "%s", stringa)!=EOF)
    {
        inserisci(lista, stringa);
        n++;
    }
    return n++;
}

void inserisci(LINK*lista, char s[DIM])
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
        strcpy(p->parola, s);
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

void cancella(LINK*lista, char l)
{
    LINK t1=*lista;
    LINK t2=NULL;

    while(t1!=NULL)
    {
        if(t1->parola[0]==l)
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

void delete(LINK*lista, LINK elimina)
{
    LINK temp=*lista;
    LINK prev=NULL;

    if(temp!=NULL)
    {
        if(*lista==elimina)
        {
            *lista=temp->next;
            free(temp);
        }
        else
        {
            while(temp->next!=NULL && temp!=elimina)
            {
                prev=temp;
                temp=temp->next;
            }
            if(temp->next==NULL && temp==elimina)
            {
                prev->next=NULL;
                free(temp);
            }
            else
            {
                prev->next=temp->next;
                free(temp);
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
