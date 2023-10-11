// Leggere un file contenente nomi di persone (dati.txt)
// Salvare i nomi in una lista
// Visualizzare la lista (ricorsivamente)
// Per ogni nodo (quindi per ogni stringa), contare le vocali
// Andrea: 3 -> Maria: 3 -> Gianna: 3 -> Susanna: 3 -> ...
// Scrivere una funzione specifica che ritorna il numero di vocali di una stringa
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define DIM 100

typedef struct Node
{
    char nome[DIM];
    struct Node *next;
} node;

node *crea1(FILE *fp, int *nodi);
void crea2(FILE *fp, int *nodi, node **t);
void visualizza(node *t);
void vocali(node *t);
int conta(char *s);

int main()
{
    FILE *fp = NULL;
    node *t = NULL;
    int nodi = 0;

    fp = fopen("esF121.txt", "r");

    if (fp != NULL)
    {
        t = crea1(fp, &nodi);
        printf("\n");
        printf("Lista creata: \n");
        visualizza(t);
        printf("\n");
        vocali(t);
        printf("\n");
    }
    else
    {
        printf("Impossibile leggere il file.\n\n");
        return 1;
    }
    return 0;
}

node *crea1(FILE *fp, int *nodi)
{
    node *t = NULL;
    node *temp = NULL;
    char nome[DIM];
    int n;

    while (n = fscanf(fp, "%s", nome) != EOF)
    {
        printf("Nome letto dal file: %s\n", nome);

        if (t == NULL)
        {
            t = (node *)malloc(sizeof(node));
            if (t != NULL)
            {
                strcpy(t->nome, nome);
                t->next = NULL;
                temp = t;
                (*nodi)++;
            }
        }
        else
        {
            temp->next = (node *)malloc(sizeof(node));
            if (temp != NULL)
            {
                temp = temp->next;
                strcpy(temp->nome, nome);
                temp->next = NULL;
                (*nodi)++;
            }
        }
    }
    return t;
}

void crea2(FILE *fp, int *nodi, node **t)
{
    node *temp = NULL;
    char nome[DIM];
    int n;

    while (n = fscanf(fp, "%s", nome) != EOF)
    {
        printf("Nome letto dal file: %s\n", nome);
        if (t == NULL)
        {
            *t = (node *)malloc(sizeof(node));
            if (t != NULL)
            {
                strcpy((*t)->nome, nome);
                (*t)->next = NULL;
                temp = *t;
                (*nodi)++;
            }
        }
        else
        {
            temp->next = (node *)malloc(sizeof(node));
            if (temp != NULL)
            {
                temp = temp->next;
                strcpy(temp->nome, nome);
                temp->next = NULL;
                (*nodi)++;
            }
        }
    }
    return t;
}

void visualizza(node *t)
{
    if(t==NULL)
    {
        printf("NULL\n");
        return;
    }
    else
    {
        printf("%s -> ", t->nome);
        visualizza(t->next);
    }
}

void vocali(node *t)
{
    while(t!=NULL)
    {
        printf("%s: %d -> ", t->nome, conta(t->nome));
        t=t->next;
    }
    printf("NULL\n");
}

int conta(char *s)
{
    int i=0;
    int conta=0; 

    while(s[i]!='\0')
    {
        if(s[i]=='A' || s[i]=='a' || s[i]=='E' || s[i]=='e' || 
            s[i]=='I' || s[i]=='i' || s[i]=='O' || s[i]=='o' || 
            s[i]=='U' || s[i]=='u')
            {
                conta++;
            }
            i++;
    }
    return conta;
}

