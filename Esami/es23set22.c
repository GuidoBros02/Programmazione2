/*Scrivere un programma che riceve come argomento il nome di un file di testo; il file di testo ricevuto
in input contiene una serie di caratteri, uno per riga. Il programma deve leggere i dati nel file, salvarli
in una lista, visualizzarla, indicare la lunghezza della lista, indicare il numero di vocali e consonanti
presenti nella lista e infine creare una seconda lista di sole vocali.
Scrivere quindi le seguenti funzioni:
1) int lista_leggi_file: dato un puntatore al file e il riferimento a una lista, crea una lista con i dati
contenuti nel file e restituisce il numero di nodi creati; la funzione deve essere iterativa;
2) void lista_visualizza: visualizza la lista; la funzione deve essere ricorsiva;
3) void lista_conta: data la testa della lista, conta il numero di vocali e consonanti presenti nella lista;
la funzione deve essere ricorsiva;
Suggerimento: void lista_conta(Node * lista, int * n_vocali, int * n_consonanti);
4) void lista_vocali: data la testa della prima lista, crea una seconda lista con i soli nodi di tipo vocale;
la funzione deve essere iterativa.
5) int main: per richiamare le funzioni di cui sopra e mostrare a video i risultati.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    char caratteri;
    struct Node *next;
} node;
typedef node *LINK;

int crea(FILE *f, LINK *lista);
void inserisci(LINK *lista, char car);
void visualizza(LINK lista);
void conta(LINK lista, int *consonanti, int *vocali);
void vocali(LINK*lista, LINK *lista2);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Errore, inserire nome di un file.\n");
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
            LINK lis1 = NULL;
            LINK lis2 = NULL;

            int cr = 0, con = 0, voc = 0;
            cr = crea(fp, &lis1);
            printf("\nLista generata con %d nodi al suo interno.\n", cr);
            visualizza(lis1);
            conta(lis1, &con, &voc);
            printf("\nLe consonanti e le vocali presenti nella lista sono %d e %d.\n", con, voc);
            vocali(&lis1, &lis2);
            printf("\nLista con sole vocali generata.\n");
            visualizza(lis2);
        }
    }
    return 0;
}

int crea(FILE *f, LINK *lista)
{
    int n = 0;
    char c;

    while (fscanf(f, "%c", &c) != EOF)
    {
        if (c != '\n')
        {
            inserisci(lista, c);
            n++;
        }
    }
    return n;
}

void inserisci(LINK *lista, char car)
{
    LINK i1 = (LINK)malloc(sizeof(node));
    LINK i2 = *lista;

    if (i1 == NULL)
    {
        printf("Errore nella creazione del nodo.\n");
        return;
    }
    else
    {
        i1->caratteri = car;
        i1->next = NULL;

        if (*lista == NULL)
        {
            *lista = i1;
        }
        else
        {
            while (i2->next != NULL)
            {
                i2 = i2->next;
            }
            i2->next = i1;
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
        printf("%c -> ", lista->caratteri);
        visualizza(lista->next);
    }
}

void conta(LINK lista, int *consonanti, int *vocali)
{
    *vocali = 0;
    *consonanti = 0;

    while (lista != NULL)
    {
        if (lista->caratteri == 'A' || lista->caratteri == 'E' || lista->caratteri == 'I' || lista->caratteri == 'O' || lista->caratteri == 'U' || lista->caratteri == 'a' || lista->caratteri == 'e' || lista->caratteri == 'i' || lista->caratteri == 'o' || lista->caratteri == 'u')
        {
            (*vocali)++;
        }
        else if (lista->caratteri == 'Q' || lista->caratteri == 'W' || lista->caratteri == 'R' || lista->caratteri == 'T' || lista->caratteri == 'P' || lista->caratteri == 'S' || lista->caratteri == 'D' || lista->caratteri == 'F' || lista->caratteri == 'G' || lista->caratteri == 'H' || lista->caratteri == 'J' || lista->caratteri == 'K' || lista->caratteri == 'L' || lista->caratteri == 'Z' || lista->caratteri == 'X' || lista->caratteri == 'C' || lista->caratteri == 'V' || lista->caratteri == 'B' || lista->caratteri == 'N' || lista->caratteri == 'M' || lista->caratteri == 'q' || lista->caratteri == 'w' || lista->caratteri == 'r' || lista->caratteri == 't' || lista->caratteri == 'p' || lista->caratteri == 's' || lista->caratteri == 'd' || lista->caratteri == 'f' || lista->caratteri == 'g' || lista->caratteri == 'h' || lista->caratteri == 'j' || lista->caratteri == 'k' || lista->caratteri == 'l' || lista->caratteri == 'z' || lista->caratteri == 'x' || lista->caratteri == 'c' || lista->caratteri == 'v' || lista->caratteri == 'b' || lista->caratteri == 'n' || lista->caratteri == 'm')
        {
            (*consonanti)++;
        }
        lista = lista->next;
    }
}

void vocali(LINK*lista, LINK *lista2)
{
    LINK v1 =*lista;

    while (v1 != NULL)
    {
        if (v1->caratteri == 'A' || v1->caratteri == 'E' || v1->caratteri == 'I' 
            || v1->caratteri == 'O' || v1->caratteri == 'U' || v1->caratteri == 'a' || v1->caratteri == 'e' || v1->caratteri == 'i' || v1->caratteri == 'o' || v1->caratteri == 'u')
        {
            inserisci(lista2, v1->caratteri);
        }
        v1=v1->next;
    }
}