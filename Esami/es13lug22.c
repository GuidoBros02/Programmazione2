/*Scrivere un programma che riceve come argomento il nome di un file di testo; il file di testo ricevuto
per argomento contiene una serie di numeri interi, uno per riga. Il programma deve leggere i dati nel
file, salvarli in una lista, visualizzarla, calcolare il fattoriale di ogni valore presente nel nodo e salvare
in un file chiamato “risultati.txt” i fattoriali ottenuti.
Scrivere quindi le seguenti funzioni:
1) int lista_leggi_file: dato un puntatore al file e il riferimento a una lista, crea una lista con i dati
contenuti nel file e restituisce il numero di nodi creati; la funzione deve essere iterativa;
2) void lista_visualizza: visualizza la lista; la funzione deve essere ricorsiva;
3) int fattoriale: dato un numero intero, restituisce il fattoriale di tale numero; la funzione deve essere
ricorsiva;
4) void salva_risultati: salva i risultati ottenuti dalla funzione 3) in un file chiamato “risultati.txt”.
5) int main: per richiamare le funzioni di cui sopra e mostrare a video i risultati.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int d;
    struct Node *next;
} node;
typedef node *LINK;

int crea(FILE *f, LINK *lista);
void inserisci(LINK *lista, int x);
void visualizza(LINK lista);
int fattoriale(int f);
void salva(FILE *f, LINK lista);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("errore, inserire un nome di un file.\n");
        return 1;
    }
    else
    {
        FILE *fp = fopen(argv[1], "r");
        if (fp == NULL)
        {
            printf("errore nell'apertura del file.\n");
            return 1;
        }
        else
        {
            LINK lis = NULL;
            int cr, sp, i=0;
            printf("Lista creata:\n");
            cr = crea(fp, &lis);
            visualizza(lis);
            printf("\n");
            printf("Nodi creati: %d\n", cr);
            int fat[cr];
            printf("\n");
            LINK temp=lis;
            while (temp != NULL)
            {
                fat[i]=fattoriale(temp->d);
                i++;
                temp = temp->next;
            }
            for(i=0; i<cr; i++)
            {
                printf("Fattoriale [%d]= %d\n", i, fat[i]);
            }
            FILE *fp2 = fopen("risultato.txt", "w");
            if (fp2 == NULL)
            {
                printf("Errore nell'apertura del file.\n");
                return 1;
            }
            else
            {
                salva(fp2, lis);
            }
            printf("Valori salvati in risultati.txt\n\n");
        }
    }
    return 0;
}

int crea(FILE *f, LINK *lista)
{
    int v, c;
    c = 0;

    while (fscanf(f, "%d", &v) != EOF)
    {
        inserisci(lista, v);
        c++;
    }
    return c;
}

void inserisci(LINK *lista, int x)
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
        p->d = x;
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
        printf("NULL\n");
    }
    else
    {
        printf("%d -> ", lista->d);
        visualizza(lista->next);
    }
}

int fattoriale(int f)
{
    if (f == 0)
    {
        return 1;
    }
    else
    {
        return (f * fattoriale(f - 1));
    }

}

void salva(FILE *f, LINK lista)
{
    while (lista != NULL)
    {
        fprintf(f, "%d\n", lista->d);
        lista = lista->next;
    }
}