/*
Scrivere un programma che riceve come argomento il nome di un file di testo; il file di testo ricevuto
per argomento contiene una serie di nomi (stringhe), uno per riga; la dimensione di ogni stringa può
essere al massimo di 64 caratteri. Il programma deve leggere i dati nel file, salvarli in una lista,
visualizzarla, contare il numero di vocali presenti, salvare in un file di testo chiamato “risultati.txt” il
risultato.
Scrivere quindi le seguenti funzioni:
1) int lista_leggi_file: dato un puntatore al file e il riferimento a una lista, crea una lista con i dati
contenuti nel file e restituisce il numero di nodi creati; la funzione deve essere iterativa;
2) void lista_visualizza: visualizza la lista; la funzione deve essere ricorsiva;
3) int lista_vocali: data la testa della lista, conta il numero di vocali presenti; la funzione deve essere
ricorsiva;
suggerimento: richiamare la funzione lista_vocali per cercare prima le ‘A’ (‘a’), poi le ‘E’ (‘e’), ecc…
4) void salva_risultati: salva il risultato ottenuto dalla funzione 3) in un file chiamato “risultati.txt”. La
funzione deve essere iterativa e salvare i risultati nella forma vocale: contatore, una per linea.
5) int main: per richiamare le funzioni di cui sopra e mostrare a video i risultati.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node
{
    char parola[65];
    struct Node*next;
}node;
typedef node*LINK;

int crea(FILE*f, LINK*lista);
void inserisci(LINK*lista, char stringa[65]);
void visualizza(LINK lista);
int vocali(LINK lista, char vocale, char Vocale);
void salva(FILE*f, int a, int e, int i, int o, int u);

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
            printf("Errore nel'apertura del file.\n");
            return 1;
        }
        else
        {
            LINK lis=NULL;
            int cr, vo;
            int numa, nume, numi, numo, numu;
            cr=crea(fp, &lis);
            printf("\nLista creata con %d nodi.\n", cr);
            visualizza(lis);

            numa=vocali(lis, 'a', 'A');
            nume=vocali(lis, 'e', 'E');
            numi=vocali(lis, 'i', 'I');
            numo=vocali(lis, 'o', 'O');
            numu=vocali(lis, 'u', 'U');

            FILE*fp2=fopen("risultati.txt", "w");

            if(fp2==NULL)
            {
                printf("Errore nell'apertura del file.\n");
                return 1;
            }
            else
            {
                salva(fp2, numa, nume, numi, numo, numu);
            }
            
        }
    }
    return 0;
}

int crea(FILE*f, LINK*lista)
{
    int n=0;
    char s[65];

    while(fscanf(f, "%s", s)!=EOF)
    {
        inserisci(lista, s);
        n++;
    }
    return n;
}

void inserisci(LINK*lista, char stringa[65])
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
        strcpy(i1->parola, stringa);
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
        printf("%s -> ", lista->parola);
        visualizza(lista->next);
    }
}

int vocali(LINK lista, char vocale, char Vocale)
{
    if(lista!=NULL)
    {
        int i=0;
        int cnt=0;

        while(lista->parola[i]!='\0')
        {
            if(lista->parola[i]==vocale || lista->parola[i]==Vocale)
            {
                cnt++;
            }
            i++;
        }
        return cnt+vocali(lista->next, vocale, Vocale);
    }
    else
    {
        return 0;
    }
}

void salva(FILE*f, int a, int e, int i, int o, int u)
{
    fprintf(f, "Vocali 'a': %d\n", a);
    fprintf(f, "Vocali 'e': %d\n", e);
    fprintf(f, "Vocali 'i': %d\n", i);
    fprintf(f, "Vocali 'o': %d\n", o);
    fprintf(f, "Vocali 'u': %d\n", u);
}