					/*Naive String Matching Algorithm Implementation*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int length(char *);
char* getMainString();
char* getSubString();
void patternMatch(char *,char *);
void getIndex();

static int count=0;
int index[10];

void main()
{
    char *MainStr, *SubStr;
    clrscr();

    MainStr=getMainString();
    SubStr=getSubString();
    patternMatch(MainStr,SubStr);
    getch();
}

int length(char *p)
{
   int i;
   for(i=0;*(p+i);i++);
   return (i);
}

char* getMainString()
{
	int len;
	char *MainStr;

	printf("Length of Main String: ");
	scanf("%d",&len);
	MainStr=(char*)malloc(sizeof(char)*len);
	printf("Enter Main String\n");
	fflush(stdin);
	gets(MainStr);
	return(MainStr);
}

char* getSubString()
{
	int len;
	char *SubStr;

	printf("\nLength of Substring: ");
	scanf("%d",&len);
	SubStr=(char*)malloc(sizeof(char)*len);
	printf("Enter Substring\n");
	fflush(stdin);
	gets(SubStr);
	return(SubStr);
}

void patternMatch(char *MS,char *SS)
{
      int i,j,k,x=0;

      for(i=0;i<=(length(MS)-length(SS));i++)
      {
	 k=i;

	 for(j=0;j<length(SS);j++)
	 {
	     if(*(SS+j)==*(MS+k))
	      k++;
	     else
	       break;
	 }

	 if(j==length(SS))
	  {
	    count++;
	    while(index[x])
		x++;
	    index[x]=i;
	    index[x+1]='\0';

	  }
      }
      getIndex();
}

void getIndex()
{
     int i;

     if(index[0]=='\0')
	printf("\nNot Found !!!");
     else
     {
	 printf("\nFound %d times at index: ",count);
	 for(i=0;index[i];i++)
	    printf(" %d",index[i]);
     }
}
