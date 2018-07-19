#include<stdio.h>

void get_Weight_Profit(float [],float [],int);
void get_pwRatio(float [],float [],float [],int); //profit/weight Ratio
void arrange(float [],float [],float [],int);
void KNAPSACK(float [],float [],int, float);

void main()
{

   float Weight[20],Profit[20],Ratio[20],capacity;
   int num;

    printf("Enter number of items\n");
    scanf("%d",&num);

    printf("Capacity of the Knapsack\n");
    scanf("%f",&capacity);

   get_Weight_Profit(Weight,Profit,num);
   get_pwRatio(Weight,Profit,Ratio,num);
   arrange(Weight,Profit,Ratio,num);
   KNAPSACK(Weight,Profit,num,capacity);

}

void get_Weight_Profit(float Weight[],float Profit[],int num)
{
   int i;
   printf("Enter Weight and Profit of %d items\n",num);
   for(i=0;i<num;i++)
    scanf("%f %f",&Weight[i],&Profit[i]);
}

void get_pwRatio(float Weight[],float Profit[],float Ratio[],int num)
{
    int i;
    for(i=0;i<num;i++)
         Ratio[i] = Profit[i]/Weight[i];
}

void arrange(float Weight[],float Profit[],float Ratio[],int num)
{
    int i,j,flag;
    float temp;

    for(i=0;i<num-1;i++)
     {

        for(j=i+1;j<num;j++)
         {
            if(Ratio[i]<Ratio[j])
            {
               temp = Ratio[i];
               Ratio[i] = Ratio[j];
               Ratio[j] = temp;

               temp = Weight[i];
               Weight[i] = Weight[j];
               Weight[j] = temp;

               temp = Profit[i];
               Profit[i] = Profit[j];
               Profit[j] = temp;


            }
         }

     }
}

void KNAPSACK(float Weight[],float Profit[],int num,float capacity)
{

  float cap,solVector[20],maxProfit=0.0;
  int i;

  cap = capacity;


   for(i=0;i<num;i++)
    solVector[i] = 0.0;

    for(i=0;i<num;i++)
    {
      if(Weight[i]>=cap)
         break;
     else
        {
          solVector[i] = 1.0;
          cap = cap - Weight[i];
        }
    }
    if(i<=num)
    {
      solVector[i] = cap/Weight[i];
    }

    for(i=0;i<num;i++)
       maxProfit = maxProfit + (solVector[i]*Profit[i]);

    printf("\nSolution Vector is\n");
    for(i=0;i<num;i++)
      printf("%f ",solVector[i]);

    printf("\n Maximum Profit is %f: ",maxProfit);

}
