/*Scrivere un programma che riceve per argomento un nome file; il file contiene il numero del
giorno, il nome del giorno e la temperatura (intera) in tale giorno.
Il programma deve: leggere i dati dal file, inserirli in una lista, visualizzare la lista, indicare la
lunghezza della lista, indicare la media, indicare il numero di nodi con temperatura sopra la
media, effettuare la ricerca delle temperature in base al nome del giorno e permettere la
cancellazione di un nodo in base al numero del giorno.
Scrivere quindi le seguenti funzioni:
1) lista_leggi_da_file: dato un puntatore a un file, crea una lista con i dati nel file e restituisce il
numero di nodi creati; la funzione deve essere iterativa;
2) lista_visualizza: visualizza la lista con i dati in forma tabulata; la funzione deve essere
ricorsiva;
3) lista_media_temperature: restituisce in una variabile per riferimento la media delle
temperature; la funzione deve essere ricorsiva;
4) lista_nodi_sopra_media: riceve in input la lista e la media; la funzione deve restituire il
numero di nodi che superano strettamente la media; la funzione deve essere ricorsiva;
5) liste_cerca_giorno: riceve in input la lista e il nome di un giorno (es. lunedi) e visualizza i
dati della lista quel giorno; la funzione deve essere ricorsiva;
6) lista_cancella_giorno: riceve in input la lista e il numero di un giorno (es. 1) e cancella dalla
lista il nodo di quel giorno; la funzione deve essere iterativa;
7) main: per gestire le funzioni di cui sopra e mostrare a video i risultati*/

#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct Node
{
    int numero;
    char nome[10];
    int temperatura;
    struct Node *next;
} node;
typedef node *LINK;

int crea(FILE *f, LINK *lista);
void inserisci(LINK *lista, int num, char nom[10], int tem);
void visualizza(LINK lista);
void media(LINK lista, float *s, float *c, float *m);
int sopra(LINK lista, float media);
void cerca(LINK lista, char gior[10]);
void cancella(LINK *lista, int n);
void delete (LINK *lista, LINK posizione);

int main(int argc, char *argv[])
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
            int cr, so, gior;
            float me, s1, c1;
            char ric[10];

            cr = crea(fp, &lis);
            printf("Lista creata con %d nodi.\n", cr);
            visualizza(lis);
            printf("\n");
            media(lis, &s1, &c1, &me);
            so = sopra(lis, me);
            printf("La media delle temperature è: %.1f.\nAl di sopra di questa media ci sono %d giorni.\n\n", me, so);
            printf("Seleziona un giorno da ricercare: ");
            scanf("%s", ric);
            cerca(lis, ric);
            printf("\nSelezionare il numero del giorno da eliminare: ");
            scanf("%d", &gior);
            cancella(&lis, gior);
            printf("\nGiorno selezionato cancellato.\n");
            visualizza(lis);
        }
    }
    return 0;
}

int crea(FILE *f, LINK *lista)
{
    int n = 0;
    int nu, te;
    char no[10];

    while (fscanf(f, "%d %s %d", &nu, no, &te) != EOF)
    {
        inserisci(lista, nu, no, te);
        n++;
    }
    return n;
}

void inserisci(LINK *lista, int num, char nom[10], int tem)
{
    LINK p = (LINK)malloc(sizeof(node));
    LINK temp = *lista;

    if (p == NULL)
    {
        printf("Errore nella creazione del nodo.\n");
        return;
    }
    else
    {
        p->numero = num;
        strcpy(p->nome, nom);
        p->temperatura = tem;
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
        printf("\n\n");
    }
    else
    {
        printf("%d\t  %s\t  %d\n", lista->numero, lista->nome, lista->temperatura);
        visualizza(lista->next);
    }
}

void media(LINK lista, float *s, float *c, float *m)
{
    if (lista != NULL)
    {
        (*s) += lista->temperatura;
        (*c)++;

        (*m) = (*s) / (*c);
        media(lista->next, s, c, m);
    }
}

int sopra(LINK lista, float media)
{
    int n = 0;

    if (lista != NULL)
    {
        if (lista->temperatura > media)
        {
            return 1 + sopra(lista->next, media);
        }
        else
        {
            return sopra(lista->next, media);
        }
    }
}

void cerca(LINK lista, char gior[10])
{
    if (lista != NULL)
    {
        if (strcmp(lista->nome, gior) == 0)
        {
            printf("%d\t | %s\t | %d\n", lista->numero, lista->nome, lista->temperatura);
        }
        cerca(lista->next, gior);
    }
}

void cancella(LINK *lista, int n)
{
    LINK t1 = *lista;
    LINK t2 = NULL;

    while (t1 != NULL)
    {
        if (t1->numero == n)
        {
            t2 = t1;
            t1 = t1->next;
            delete (lista, t2);
        }
        else
        {
            t1 = t1->next;
        }
    }
}

void delete (LINK *lista, LINK posizione)
{
    LINK temp = *lista;
    LINK prev = NULL;

    if (*lista != NULL)
    {
        if (*lista == posizione)
        {
            *lista = temp->next;
            free(temp);
        }
        else
        {
            while (temp->next != NULL && temp != posizione)
            {
                prev = temp;
                temp = temp->next;
            }

            if (temp->next == NULL && temp == posizione)
            {
                prev->next = NULL;
                free(temp);
            }
            else
            {
                prev->next = temp->next;
                free(temp);
            }
        }
    }
}