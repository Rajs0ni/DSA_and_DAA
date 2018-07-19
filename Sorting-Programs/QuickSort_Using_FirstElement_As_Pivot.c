#include<stdio.h>

void quickSort(int [],int);
void quick(int [],int,int,int*);        //Partition the list

void main()
{
    int i,*A,num;

    printf("Number Of Elements:");
    scanf("%d",&num);

    A = (int *)malloc(sizeof(int)*num);

    printf("\nFeed %d Inputs\n",num);
    for(i=0;i<num;i++)
        scanf("%d",(A+i));

    printf("\nUnsorted Elements\n");
    for(i=0;i<num;i++)
        printf(" %d",*(A+i));

    quickSort(A,num);

    printf("\n\nSorted Elements\n");
    for(i=0;i<num;i++)
        printf(" %d",*(A+i));
}

void quickSort(int A[],int N)
{
    int TOP = -1,BEG,END,LOC;
    int LOWER[10],UPPER[10];
    if(N>1)
    {
        TOP++;
        LOWER[TOP] = 0;
        UPPER[TOP] = N-1;
    }
    while(TOP != -1)
    {
      BEG = LOWER[TOP];
      END = UPPER[TOP];
      TOP--;
      quick(A,BEG,END,&LOC);
      if(BEG<LOC-1)
      {
          TOP++;
          LOWER[TOP] = BEG;
          UPPER[TOP] = LOC - 1;
      }
      if(LOC+1<END)
      {
          TOP++;
          LOWER[TOP] = LOC + 1;
          UPPER[TOP] = END;
      }
    }
}

void quick(int A[],int BEG,int END,int *LOCPTR)
{
    int LEFT,RIGHT,temp;
    LEFT = BEG; RIGHT = END; *LOCPTR = BEG; //Using Last Element As a Pivot

step2:
    while(A[*LOCPTR]<A[RIGHT] && *LOCPTR != RIGHT)
        RIGHT--;
    if(*LOCPTR == RIGHT)
        return;
    if(A[*LOCPTR]>A[RIGHT])
    {
        temp = A[*LOCPTR];
        A[*LOCPTR] = A[RIGHT];
        A[RIGHT] = temp;
        *LOCPTR = RIGHT;
    }
    goto step3;

step3:
    while(A[LEFT]<A[*LOCPTR] && *LOCPTR != LEFT)
        LEFT++;
    if(*LOCPTR == LEFT)
        return;
    if(A[*LOCPTR]<A[LEFT])
    {
        temp = A[*LOCPTR];
        A[*LOCPTR] = A[LEFT];
        A[LEFT] =temp;
        *LOCPTR = LEFT;
    }
    goto step2;
}

