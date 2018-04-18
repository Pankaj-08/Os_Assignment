#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<pthread.h>

int main()
{
	int i =1,N,arr[100],j=0,count=0,temp,last;
	pid_t p;
	p=fork();

	if(p==1)
		printf("------Process Not created---------");
	else if(p==0)
	{
	
				G :
					printf("\n-------Enter the starting number for Sequence :- ");
					scanf("%d",&N);
					if(N<=0)
					{
						printf("\n-------Entered number should be graeater than 0 ---------\n \t Try again :(");
						goto G;
					}
					else
					{
						printf("\n--------------------------------------------------------------\n");
						printf(" \tThe sequence is :- ");
						while(i<=N)
						{
							if(i<N)
							{
								arr[j]=i;
								i=i*2;
								j=j+1;
								count = count+1;
							}
							if(i>=N)
							{
								arr[j] = N;
								count++;
								break;
							}
						}
					}
					last = count-1;
					for(i=0;i<count/2;i++)
					{
						temp = arr[i];
						arr[i]=arr[last];
						arr[last]=temp;
						last = last-1;
					}
					for(i=0;i<count;i++)
					{
						printf("%d\t",arr[i]);
					}
					printf("\n");
		
	}
	else
		wait();
	

}
