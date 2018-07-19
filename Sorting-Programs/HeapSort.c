#include<stdio.h>
#include<stdlib.h>

typedef struct HEAP                                //Heap Abstract Data Type
{
    int *Array;
    int count;
    int capacity;
}HEAP;

void HeapSort(int *,int);                          //perform Sorting
HEAP* createHeap(int);                             //create Heap Abstract Data Type
void buildHeap(HEAP *,int *,int);                  //build Heap
void Heapify(HEAP *,int);                          //Rearrange Heap
int leftChild(HEAP *,int);                         //Return Left Child of Root node
int rightChild(HEAP *,int);                        //Return Right Child of Root node

void main()
{
    int size,i;
    int *A;

    printf("Size of Heap:");
    scanf("%d",&size);

    A = (int *)malloc(sizeof(int)*size);

    printf("\nFeed %d Input\n",size);
    for(i=0;i<size;i++)
        scanf("%d",(A+i));

    printf("\nUnsorted Elements:\n");
    for(i=0;i<size;i++)
        printf(" %d",*(A+i));

    HeapSort(A,size);
}

void HeapSort(int *A,int n)
{
    int heapSize,i,temp;

    HEAP *h = createHeap(n);
    buildHeap(h,A,n);
    heapSize = h->count;
    for(i=0;i<n-1;i++)
    {
        temp = h->Array[0];
        h->Array[0] = h->Array[h->count-1];
        h->Array[h->count-1] = temp;
        h->count--;
        Heapify(h,0);
    }

    h->count=heapSize;
    printf("\n\nSorted Elements:\n");
    for(i=0;i<h->count;i++)
        printf(" %d",h->Array[i]);
}

HEAP* createHeap(int cap)
{
    HEAP *h = (HEAP *)malloc(sizeof(HEAP));
    h->count = 0;
    h->capacity = cap;
    h->Array = (int *)malloc(sizeof(int)*cap);
    return h;
}

void buildHeap(HEAP *h,int *A,int n)
{
    int i;

    for(i=0;i<n;i++)
        h->Array[i] = *(A+i);

    h->count = n;

    for(i=(n-1)/2;i>=0;i--)
        Heapify(h,i);
}

void Heapify(HEAP *h,int i)
{
    int max,temp,lchild,rchild;

    lchild = leftChild(h,i);
    rchild = rightChild(h,i);

    if(lchild != -1 && h->Array[lchild]>h->Array[i])
        max = lchild;
    else
        max = i;

    if(rchild != -1 && h->Array[rchild]>h->Array[max])
        max = rchild;

    if(max != i)
    {
        temp = h->Array[i];
        h->Array[i] = h->Array[max];
        h->Array[max] = temp;
        Heapify(h,max);
    }
}

int leftChild(HEAP *h,int i)
{
    int leftchild = 2*i+1;

    if(leftchild>=h->count)
        return -1;

    return leftchild;
}

int rightChild(HEAP *h,int i)
{
    int rightchild = 2*i+2;

    if(rightchild>=h->count)
        return -1;

    return rightchild;
}
