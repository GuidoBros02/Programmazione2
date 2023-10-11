/*Scrivere un programma che riceve per argomento un nome file; il file di testo ricevuto per argomento
contiene una serie di numeri interi tra -10 e +10 (estremi inclusi). Il programma deve leggere i dati nel
file, salvarli in una lista, visualizzare la lista, generare due nuove liste (una con i numeri maggiori o
uguali a 0 e una con i numeri strettamente minori di 0), visualizzare le nuove liste e salvare su due
file di testo chiamati lista1.txt e lista2.txt rispettivamente la lista con i numeri positivi e quella
con i numeri negativi.
Scrivere quindi le seguenti funzioni:
1) lista_leggi_file: dato un puntatore al file e la testa della lista per riferimento, crea una lista con i
dati nel file stesso e restituisce il numero di nodi creati; la funzione deve essere iterativa;
2) lista_visualizza: visualizza la lista con i dati in forma tabulata; la funzione deve essere ricorsiva;
3) lista_dividi: data la testa della lista iniziale, crea una nuova lista contenente i valori positivi (o
negativi) della prima lista; la funzione deve essere iterativa.
Suggerimento: utilizzare la stessa funzione per creare le due liste, passando un parametro per
determinare se è necessario estrarre i nodi positivi o negativi.
4) lista_scrivi_file: data la testa di una lista e il puntatore a un file, scrive la lista sul file, un nodo per
riga. La funzione deve essere iterativa.
5) main: per gestire le funzioni di cui sopra e mostrare a video i risultati.
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int d;
    struct Node*next;
}node;
typedef node*LINK;

int crea(FILE*f, LINK*lista);
void inserisci(LINK*lista, int valori);
void visualizza(LINK lista);
void dividi(LINK lista, LINK*lista2);
void salva(FILE*f, LINK lista);

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
            int cr=0;
            LINK lis1=NULL;
            LINK lis2=NULL;
            cr=crea(fp, &lis1);
            printf("\nLista generata con %d nodi.\n", cr);
            visualizza(lis1);
            dividi(lis1, &lis2);
            printf("\nVisualizzazione della lista senza numeri negativi\n");
            visualizza(lis2);
            FILE*fp2=fopen("risultati.txt", "w");
            salva(fp2, lis1);
            printf("\nLista salvata sul file risultati.txt\n\n");
        }
    }
    return 0;
}

int crea(FILE*f, LINK*lista)
{
    int n=0;
    int v=0;

    while(fscanf(f, "%d", &v)!=EOF)
    {
        inserisci(lista, v);
        n++;
    }
    return n;
}

void inserisci(LINK*lista, int valori)
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
        i1->d=valori;
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
        printf("NULL\n");
    }
    else
    {
        printf("%d -> ", lista->d);
        visualizza(lista->next);
    }
}

void dividi(LINK lista, LINK*lista2)
{
    while(lista!=NULL)
    {
        if((lista->d)>0)
        {
            inserisci(lista2, lista->d);
            lista=lista->next;
        }
        else
        {
            lista=lista->next;
        }
    }
}

void salva(FILE*f, LINK lista)
{
    while(lista!=NULL)
    {
        fprintf(f, "%d\n", lista->d);
        lista=lista->next;
    }
}