/*
// Torre di Hanoi

Ci sono 3 torri, lo scopo è spostare tutti i dischi (di dimensione crescente) 
dalla torre A alla torre C, usando la torre B come temporaneo. 
Si può spostare 1 solo disco per volta e un disco grande non può stare sopra ad uno
Più piccolo

Funzione ricorsiva:
Passi base: se n(n° di dischi)==1 si sposta il disco della torre A alla C
Passo ricorsivo: se n>1: si spostano n-1 dischi da A a B con C come supporto, si sposta 
                il disco più grande da A a C, si spostano n-1 dischi da B a C. 
                Con A come supporto.

//funzione

void move(int n, char*A, char*B, char*C)
{
    if(n==1)
    {
        printf("Moving disci %d from tower %s to %s.\n", n, A, C);
    }
    else
    {
        move(n-1, A, C, B);
        printf("Moving disc %d from tower %s to %s.\n", n, A, C);
        move(n-1, B, A, C);
    }
}

2^(n) -1 chiamate -> complessità in tempo O(2^n)
Altezza max dell'albero: n-> complessità in spazio O(n)

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Merge Sort
Spota il lavoro sul Merge, la partition divide l'array in 2, 
il merge combina i due segmenti.

//Funzione

#define DIM 0                           // inserito a solo scopo dimostrativo, non da inserire all'esame
void MergeSort(int A[], int p, int r)
{
    int q;

    if(p<r)
    {
        q=(p+r)/2;
        MergeSort(A, p, q);
        MergeSort(A, q+1, r);
        Merge(A, p, q, r);
    }
}

void Merge(int A[], int p, int q, int r)
{
    int B[DIM];
    int i=p;
    int j=q+1;
    int k=p;

    while(i<=q && j<=r)
    {
        if(A[i]<A[j])
        {
            B[k++]=A[i++];
        }
        else
        {
            B[k++]=A[j++];
        }
    }
    while(i<=q)
    {
        B[k++]=A[i++];
    }
    while(j<=r)
    {
        B[k++]=A[j++];
    }
    for(k=p; k<=r; k++)
    {
        A[k]=B[k];
    }
}

n confronti per ogni livello, l'altezza dell'albero è log2n -> complessità in tempo O(nlog2n)
ad ogni chiamata n si dimezza, l'altezza dell'albero è log2n-> complessità in spazio O(log2n)

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Pattern di ordinamento ricorsivo

void Recsort(int A[], int p, int r)
{
    int q;

    if(p<r)
    {
        q=Partition(A, p, r);
        Recsort(A, p, q);
        Recsort(A, q+1, r);
        Merge(A, p, q, r);
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Quick Sort

Sposta il lavoro sul Partition (si sceglie un X1, 
a sinistra vanno tutti i numedi <x ed 
a destra tutti quelli >=x)

// funzione

void QuickSort(int A[], int p, int r)
{
    int q;

    if(p<r)
    {
        q=Partition(A, p, r);
        QuickSort(A, p, q-1);
        QuickSort(A, q+1, r);
    }
}

int Partition (int A[], int p, int r)
{
    int i;
    int pivot;
    int pivotpos;

    swap(p, (p+r)/2, A);
    pivot=A[p];
    pivotpos=p;

    for(i=p+1; i<=r; i++)
    {
        if(A[i]<pivot)
        {
            swap(++pivotpos, i, A);
        }
    }
    swap(p, pivotpos, A);
    return pivotpos;
}

void swap(int i, int j, int A[])
{
    int tmp;
    tmp=A[i];
    A[i]=A[j];
    A[j]=tmp;
}

Complessità in spazio:
    - C migliore: O(Log2n)
    - C peggiore: O(n)

Complessità in tempo:
    - C migliore: O(nlog2n) [n, (2*n)/2, (4*n)/4, [...]]
    - C peggiore: O(n^2)    [n+(n-1)+(n-2) [...]-> n(n+1)/2]

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Stack

Struttura last in first out. 
le opeazioni tipiche sono:
    - Push          ->      Inserire 1 elemento in testa
    - Pop           ->      Rimuovere 1 elemento in testa
    - Top           ->      Visualizzare 1 elemento in testa
    - IsEmpty       ->      è vuoto?
    - IsFull        ->      è pieno?
    - Initialize    ->      Inizializzazione


// Implementazione dell'Array
#define MAX_LEN 1000             // Lunghezza massima

typedef struct Stack
{
    int s[MAX_LEN];
    int top;
}stack;

// Implementazione della lista
typedef struct Stack
{
    node*top;
    int cnt;
}stack;

// Queve

Struttura First in first out
Le operazioni tipiche sono:
    - Enqueve       ->      Inserisce in coda
    - Dequeve       ->      Rimuove dal front
    - Initialize    ->      Inizializza
    - front         ->      Recupera il primo valore
    - isEmpty       ->      è vuoto?
    - IsFull        ->      è pieno?

// codice

typedef struct Queve
{
    node*front;
    node*rear;
    int cnt;
}queve;
*/