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

	while (1)	//ģ�ⶨʱ���ж� Ҳ��ֱ�Ӷ�����ѭ��
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