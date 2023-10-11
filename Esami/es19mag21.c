/*Scrivere un programma che riceve per argomento un nome file; il file di testo contiene il
codice esame (al massimo 5 caratteri), il voto (da 18 a 31 - che rappresenta il 30 e lode -) e
il peso in CFU degli esami sostenuti da uno studente.
Il programma deve: leggere i dati dal file, inserirli in una lista, visualizzare la lista, indicare la
lunghezza della lista (ovvero il numero di esami sostenuti dallo studente), visualizzare la
media pesata (sommatoria(voto * cfu) / sommatoria(cfu)), riportare una seconda lista degli
esami con lode, permettere la ricerca di un esame tramite codice.
Scrivere quindi le seguenti funzioni:
1) lista_leggi_da_file: dati un puntatore a un file e la testa della lista per riferimento, crea
una lista con i dati nel file e restituisce il numero di nodi creati; la funzione deve essere
iterativa;
2) lista_visualizza: visualizza la lista con i dati in forma tabulata; la funzione deve essere
ricorsiva;
3) lista_media: data la testa della lista, calcola la media pesata (sommatoria(voto * cfu) /
sommatoria(cfu)); la funzione deve restituire la media in formato float; la funzione deve
essere ricorsiva;
4) lista_lodi: data la testa della lista, la funzione restituisce una seconda lista contenente gli
esami con la lode; la funzione deve essere iterativa;
5) lista_cerca_esame: data la testa della lista e una stringa contenente il codice esame,
visualizza tutti i dati dell’esame; se l’esame non viene trovato, visualizza la scritta “Esame
non trovato / non ancora sostenuto”; la funzione deve essere iterativa;
6) main: per gestire le funzioni di cui sopra e mostrare a video i risultati.*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define DIM 6

typedef struct Node
{
    char mat[DIM];
    int voto;
    int cfu;
    struct Node*next;
}node;
typedef node*LINK;

int crea(FILE*f, LINK*lista);
void inserisci(LINK*lista, char m[DIM], int v, int c);
void visualizza(LINK lista);
float media(LINK lista, float*s, float*c);
void lodi(LINK lista, LINK*lista2);
void ricerca(LINK lista, char ricer[DIM]);

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
            int cr, ri;
            float me, me1, me2;
            char ric[DIM];
            cr=crea(fp, &lis1);
            printf("\nLista creata con %d nodi.\n", cr);
            visualizza(lis1);
            printf("\n");
            me=media(lis1, &me1, &me2);
            printf("La media pesata dei voti è %.1f\n", me);
            lodi(lis1, lis2);
            printf("Creazione delle liste con le lodi in corso...\n");
            visualizza(lis2);
            printf("Inserire una matricola da ricercare: ");
            scanf("%s", ric);
            ricerca(lis1, ric);
            if(ri==1)
            {
                printf("L'esame richiesto non è stato svolto.\n");
                return 1;
            }
            else
            {
                printf("L'esame ricercato con %s matricola è presente.\n");
            }
        }
    }
    return 0;
}

int crea(FILE*f, LINK*lista)
{
    int n=0;
    char str[DIM];
    int vo, cr;

    while(fscanf(f, "%s %d %d", str, &vo, &cr)!=EOF)
    {
        inserisci(lista, str, vo, cr);
        n++;
    }
    return n;
}

void inserisci(LINK*lista, char m[DIM], int v, int c)
{
    LINK p=(LINK)malloc(sizeof(node));
    LINK temp=*lista;

    if(p==NULL)
    {
        printf("Errore nella creazione del nodo\n");
        return;
    }
    else
    {
        strcpy(p->mat, m);
        p->voto=v;
        p->cfu=c;

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
        printf("%s\t | %d\t | %d\t ", lista->mat, lista->voto, lista->cfu);
        visualizza(lista->next);
    }
}

float media(LINK lista, float*s, float*c)
{
    
}

void lodi(LINK lista, LINK*lista2)
{
    LINK l1=lista;
    LINK l2=NULL;

    while(lista!=NULL)
    {
        if((lista->voto)>30)
        {
            l2=l1;
            l1=l1->next;
            inserisci(lista2, lista->mat, lista->voto, lista->cfu);
        }
        else
        {
            l1=l1->next;
        }
    }
}

void ricerca(LINK lista, char ricer[DIM])
{
    while(lista!=NULL)
    {
        if(strcmp((lista->mat), ricer)==0)
        {
            printf("%s\t %d\t %d\n", lista->mat, lista->voto, lista->cfu);
        }
        else
        {
            printf("Esame non trovato.\n");
        }
    }
}
