#include <stdio.h>
#include<conio.h>
#define MAX 100

typedef struct Job
{
	char id[5];
	int deadline;
	int profit;
}Job;

void jobScheduling(Job [], int);

void main()
{

	int i, j;       //variables
	Job jobs[100]; /*= { {"j1", 3,  80}, {"j2", 2, 110}, {"j3", 1,  40}, {"j4", 4,  60}, {"j5", 2,  100}}; //jobs with deadline and profit*/
	Job temp;       //temp
	int n ;//= 5;      //number of jobs

    printf("\nFeed Number of Jobs: ");
    scanf("%d",&n);
    printf("\nFeed Jobname,Deadline & Profit(e.g:- J1 1 10)\n");
    for(i = 0; i < n; i++)
        scanf("%s %d %d",&jobs[i].id,&jobs[i].deadline,&jobs[i].profit);

	for(i = 1; i < n; i++)           //sort the jobs profit wise in descending order
        {
		for(j = 0; j < n - i; j++)
            {
			if(jobs[j+1].profit > jobs[j].profit)
			 {
				temp = jobs[j+1];
				jobs[j+1] = jobs[j];
				jobs[j] = temp;
			}
		}
	}

	printf("\n%10s %10s %10s\n", "Job", "Deadline", "Profit");

	for(i = 0; i < n; i++)
		printf("%10s %8i %10i\n", jobs[i].id, jobs[i].deadline, jobs[i].profit);


	jobScheduling(jobs, n);

}

int minValue(int x, int y)
{
	if(x < y) return x;
	return y;
}

void jobScheduling(Job jobs[], int n)
{

	int i, j, k=0, maxprofit;           //variables
	int timeslot[MAX];               //free time slots
	int filledTimeSlot = 0;         //filled time slots
    int dmax = 0;                  //find max deadline value

	for(i = 0; i < n; i++)
        {
		 if(jobs[i].deadline > dmax)
			    dmax = jobs[i].deadline;
        }


	for(i = 0; i < dmax; i++)      //free time slots initially set to -1 [-1 denotes EMPTY]
		   timeslot[i] = -1;


	printf(" \n\tdmax: %d\n", dmax);

	for(i = 1; i <= n; i++)
        {
		   k = minValue(dmax, jobs[i - 1].deadline);
		   while(k >= 0)
		    {
			  if(timeslot[k] == -1)
			   {
				timeslot[k] = i-1;
				filledTimeSlot++;
				break;
			   }
			  k--;
		    }


		if(filledTimeSlot == dmax)      //if all time slots are filled then stop
                break;

	}


	printf("\nRequired Jobs: ");            //required jobs
	for(i = 0; i < dmax; i++)
        {
		   printf("%s", jobs[timeslot[i]].id);

          if(i < dmax-1)
			 printf(" --> ");

        }


	maxprofit = 0;                              //required profit
	for(i = 0; i < dmax; i++)
		maxprofit += jobs[timeslot[i]].profit;

	 printf("\nMax Profit: %d\n", maxprofit);
}
