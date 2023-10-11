/*Scrivere un programma che riceve per argomento un file contenente i codici di regione (tre
lettere), le dosi di vaccino anti Covid-19 effettivamente somministrate e il totale di quelle
disponibili a magazzino.
Il programma deve:
1) generare una lista con i tre dati presenti nel file; la funzione deve essere iterativa;
2) visualizzare la lista in forma tabulata; la funzione deve essere ricorsiva;
3) generare una seconda lista contenente il codice regione e la percentuale di
somministrazioni svolte (dosi somministrate / dosi disponibili * 100); la funzione deve
essere iterativa;
4) sulla base della seconda lista, determinare la regione che, in percentuale, ha
somministrato più dosi (compresa del valore); la funzione deve essere ricorsiva;
5) calcolare la media delle somministrazioni dalla prima lista; la funzione deve essere
ricorsiva;
6) cancellare dalla prima lista i valori strettamente superiori alla media delle
somministrazioni; la funzione deve essere iterativa.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define DIM 4

typedef struct Node
{
    char codice[DIM];
    int som;
    int disp;
    struct Node*next;
}node;

typedef struct Node2
{
    char codice[DIM];
    float perc;
    struct Node2*next;
}node2;

void crea(FILE*f, node**lista);
void inserisci(node**testa, char s[], int x, int y);
void visualizza(node*lista);
node2*percentuale(node*lista);
void inserisci2(node2**testa, char s[], float x);
void visualizza2(node2*lista);
void maggiore(node2*lista, float*max, char c[]);
float media(node*lista, float*s, float*c);
void cancella(node**lista, float m);

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
            node*list=NULL;
            crea(fp, &list);
            visualizza(list);
            printf("\n\n");
            node2*percent=percentuale(list);
            visualizza2(percent);
            char stringa[DIM];
            float massimo;
            printf("\n\n");
            maggiore(percent, &massimo, stringa);
            printf("Regione con percentuale maggiore\n%s %.2f\n\n", stringa, massimo);
            float somma=0;
            float cnt=0;
            float med=media(list, &somma, &cnt);
            printf("Media somministrazioni: %.2f\n\n", med);
            cancella(&list, med);
            visualizza(list);
            printf("\n\n");
        }
    }
    return 0;
}

void crea(FILE*f, node**lista)
{
    char c[DIM];
    int s, d;

    while(fscanf(f, "%s %d %d", c, &s, &d)!=EOF)
    {
        inserisci(lista, c, s, d);
    }
}

void inserisci(node**testa, char s[], int x, int y)
{
    node*p=(node*)malloc(sizeof(node));

    if(p==NULL)
    {
        printf("Errore nella creazione del nodo\n");
        return;
    }
    else
    {
        strcpy(p->codice, s);
        p->som=x;
        p->disp=y;
        p->next=NULL;

        if(*testa==NULL)
        {
            *testa=p;
        }
        else
        {
            node*temp=*testa;

            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=p;
        }
    }
}

void visualizza(node*lista)
{
    if(lista==NULL)
    {
        printf("NULL\n");
    }
    else
    {
        printf("%s %d %d\n", lista->codice, lista->som, lista->disp);
        visualizza(lista->next);
    }
}

node2*percentuale(node*lista)
{
    node2*testa=NULL;
    float r;

    while(lista!=NULL)
    {
        r=(float)(lista->som)/(float)(lista->disp)*100;
        inserisci2(&testa, lista->codice, r);
        lista=lista->next;
    }
    return testa;
}

void inserisci2(node2**testa, char s[], float x)
{
    node2*p=(node2*)malloc(sizeof(node2));

    if(p==NULL)
    {
        printf("Errore nella creazione del nodo\n");
        return;
    }
    else
    {
        strcpy(p->codice, s);
        p->perc=x;
        p->next=NULL;

        if(*testa==NULL)
        {
            *testa=p;
        }
        else
        {
            node2*temp=*testa;
            
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=p;
        }
    }
}

void visualizza2(node2*lista)
{
    if(lista==NULL)
    {
        printf("NULL\n");
    }
    else
    {
        printf("%s %.2f\n", lista->codice, lista->perc);
        visualizza2(lista->next);
    }
}

void maggiore(node2*lista, float*max, char c[])
{
    if(lista!=NULL)
    {
        if((lista->perc)>(*max))
        {
            *max=lista->perc;
            strcpy(c, lista->codice);
        }
        maggiore(lista->next, max, c);
    }
}

float media(node*lista, float*s, float*c)
{
    if(lista==NULL)
    {
        return(*s)/(*c);
    }
    else
    {
        (*s)+=(float)lista->som;
        (*c)++;
        return media(lista->next, s, c);
    }
}

void cancella(node**lista, float m)
{
    if(*lista!=NULL)
    {
        if(((*lista)->som)>m)
        {
            node*temp=*lista;
            *lista=(*lista)->next;
            free(temp);
            cancella(lista, m);
        }
        else
        {
            cancella(&((*lista)->next), m);
        }
    }
}
