#include<stdio.h>
#include<stdlib.h>

typedef struct EDGE
{
    int srcVtx;
    int destVtx;
    int weight;
}EDGE;

typedef struct GRAPH
{
    int No_Of_Vtx;
    int No_Of_Edg;
    EDGE *edge;
}GRAPH;

GRAPH* createGraph();
int findParent(int,int[]);              //return the parent vertex for avoiding cycle
void kruskal(GRAPH *);
void HeapSort(GRAPH *);                 //arrange edges in ascending order according to their weight
void buildHeap(GRAPH *);
void Heapify(GRAPH *,int);
int leftChild(GRAPH *,int);
int rightChild(GRAPH *,int);


void main()
{
    GRAPH *g = createGraph();
    kruskal(g);
}

GRAPH* createGraph()
{
    int i;
    GRAPH *g = (GRAPH *)malloc(sizeof(GRAPH));

    printf("Feed No. of Vertex & No. of Edges:");
    scanf("%d%d",&g->No_Of_Vtx,&g->No_Of_Edg);

    g->edge = (EDGE *)malloc(sizeof(EDGE)*g->No_Of_Edg);
    printf("Feed Graph Data:-\n");
    printf("S D W\n");
    for(i=0;i<g->No_Of_Edg;i++)
        scanf("%d%d%d",&g->edge[i].srcVtx,&g->edge[i].destVtx,&g->edge[i].weight);
    return g;
}

void kruskal(GRAPH *g)
{
    int count=0,i=0,Parent[g->No_Of_Vtx];
    int srcPrnt,destPrnt;
    EDGE minCostEdge;
    EDGE *minSpanTree = (EDGE *)malloc(sizeof(EDGE)*(g->No_Of_Vtx-1));

    HeapSort(g);

   for(i=0;i<g->No_Of_Vtx;i++)
        Parent[i] = i;

        i=0;

    while(count < g->No_Of_Vtx-1)
    {
        minCostEdge = g->edge[i];
        srcPrnt = findParent(minCostEdge.srcVtx,Parent);
        destPrnt = findParent(minCostEdge.destVtx,Parent);

        if(srcPrnt != destPrnt)
            {
             minSpanTree[count] = minCostEdge;
             count++;
             Parent[srcPrnt] = destPrnt;
            }
        i++;
        }


    for(i=0;i<g->No_Of_Vtx-1;i++)
    {
        if(minSpanTree[i].srcVtx<minSpanTree[i].destVtx)
            printf("%d %d %d\n",minSpanTree[i].srcVtx,minSpanTree[i].destVtx,minSpanTree[i].weight);
        else
             printf("%d %d %d\n",minSpanTree[i].destVtx,minSpanTree[i].srcVtx,minSpanTree[i].weight);
    }

}

int findParent(int vtx,int Parent[])
{
    if(Parent[vtx] == vtx)
        return vtx;
    return findParent(Parent[vtx],Parent);
}

void HeapSort(GRAPH *g)
{
    int heapSize,i;
    EDGE temp;
    buildHeap(g);

    heapSize = g->No_Of_Edg;

    for(i=0;i<g->No_Of_Edg;i++)
        {
            temp = g->edge[0];
            g->edge[0] = g->edge[g->No_Of_Edg-1];
            g->edge[g->No_Of_Edg-1] = temp;
            g->No_Of_Edg--;
            Heapify(g,0);
        }

     g->No_Of_Edg=heapSize;

}


void buildHeap(GRAPH *g)
{
    int i;
    for(i=(g->No_Of_Edg-1)/2;i>=0;i--)
        Heapify(g,i);
}


void Heapify(GRAPH *g,int i)
{
    int max,lchild,rchild;
    EDGE temp;

    lchild = leftChild(g,i);
    rchild = rightChild(g,i);

    if(lchild != -1 && g->edge[lchild].weight>g->edge[i].weight)
        max = lchild;
    else
        max = i;

    if(rchild != -1 && g->edge[rchild].weight>g->edge[max].weight)
        max = rchild;

    if(max != i)
    {
        temp = g->edge[i];
        g->edge[i] = g->edge[max];
        g->edge[max] = temp;
        Heapify(g,max);
    }
}

int leftChild(GRAPH *g,int i)
{
    int leftchild = 2*i+1;

    if(leftchild>=g->No_Of_Edg)
        return -1;

    return leftchild;
}

int rightChild(GRAPH *g,int i)
{
    int rightchild = 2*i+2;

    if(rightchild>=g->No_Of_Edg)
        return -1;

    return rightchild;
}

