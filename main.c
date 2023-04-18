#include<stdio.h>
#include<Windows.h>
#include<Time.h>
#include<stdlib.h>
#include<string.h>

#include "UserThreads.h" 

int i = 1;

int main()
{
	CreatUserThread2(&HighPriorityThreadList);

	CreatUserThread1(&HighPriorityThreadList);

	while (1)	//模拟定时器中断 也可直接丢进主循环
	{
		printf("T = %d\t", i);

		ThreadScheduler(&HighPriorityThreadList);
		//ThreadScheduler(&MidPriorityThreadList);
		//ThreadScheduler(&LowPriorityThreadList);

		Sleep(200);	
		printf("\n");
		i++;
	}
}