#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "MiniScheduler.h"

ThreadListTypeDef HighPriorityThreadList = {NULL};	//�������̶߳���
ThreadListTypeDef MidPriorityThreadList = { NULL};	//�������̶߳���
ThreadListTypeDef LowPriorityThreadList = { NULL};	//�������̶߳���

void ThreadHandle(ThreadListTypeDef* ThreadList, ThreadTypeDef* Thread)		//�߳�����
{
	TaskNodeTypeDef_Mini* CurrentTaskNode = (TaskNodeTypeDef_Mini*)Thread->TaskNode;
	
	if (Thread->ThreadRunning)	//�߳�������
	{
		(*(CurrentTaskNode->Task))((void*)CurrentTaskNode);	//��������

		if (CurrentTaskNode->TaskComplete)	//��ǰ����ڵ����
		{
			int i, CurrentJumpDistance = CurrentTaskNode->JumpDistance;
			TaskNodeTypeDef_Mini* TargetTaskNode = CurrentTaskNode;

			CurrentTaskNode->JumpCount++;

			if (CurrentTaskNode->JumpTimesSet >= 0)
			{
				if (CurrentTaskNode->JumpCount >= CurrentTaskNode->JumpTimesSet)
				{
					CurrentJumpDistance = 1;
					CurrentTaskNode->JumpCount = 0;
				}
			}
			
			if (CurrentJumpDistance < 0)
			{
				for (i = 0; i > CurrentJumpDistance; i--)
				{
					if (TargetTaskNode->LastNode != NULL)
					{
						TargetTaskNode = (TaskNodeTypeDef_Mini*)TargetTaskNode->LastNode;
					}
					else
					{
						ThreadWriteOff(ThreadList, Thread);
						return;
					}
				}
			}
			else if (CurrentJumpDistance > 0)
			{
				for (i = 0; i < CurrentJumpDistance; i++)
				{
					if (TargetTaskNode->NextNode != NULL)
					{
						TargetTaskNode = (TaskNodeTypeDef_Mini*)TargetTaskNode->NextNode;
					}
					else
					{
						ThreadWriteOff(ThreadList, Thread);
						return;
					}
				}
			}
			Thread->TaskNode = (void*)TargetTaskNode;
			if (CurrentTaskNode->JumpCount < 0)	//���
			{
				CurrentTaskNode->JumpCount = 0;
			}
			CurrentTaskNode->TaskComplete = 0;	//��������״̬
		}
	}
}

void ThreadWriteOff(ThreadListTypeDef* ThreadList, ThreadTypeDef* ThreadNode)	//ע���߳�
{
	ThreadTypeDef* ThreadListSearchNode = ThreadList->HeadThread;
	TaskNodeTypeDef_Mini* CurrentTaskNode = NULL;
	TaskNodeTypeDef_Mini* NextTaskNode = NULL;
	TaskNodeTypeDef_Mini* LastTaskNode = NULL;
	int ThreadNodeExist = 0;

	while (ThreadListSearchNode != NULL)	//�����߳�������
	{
		if (ThreadListSearchNode == ThreadNode)
		{
			ThreadTypeDef* LastThreadNode = ThreadNode->LastThread;
			if (LastThreadNode == NULL)
			{
				ThreadList->HeadThread = ThreadNode->NextThread;
			}
			else
			{
				LastThreadNode->NextThread = ThreadNode->NextThread;
			}
			ThreadNodeExist = 1;
			break;
		}
		ThreadListSearchNode = ThreadListSearchNode->NextThread;
	}

	if (ThreadNodeExist)
	{
		CurrentTaskNode = ThreadNode->TaskNode;
		free(ThreadNode);		//�ͷ��߳�������ռ�
	}
	else
	{
		return;
	}

	if (CurrentTaskNode != NULL)			//�Ƿ��������һ�����
	{
		LastTaskNode = CurrentTaskNode->LastNode;
	}
	else
	{
		return;
	}

	while (CurrentTaskNode != NULL)			//���������������
	{
		NextTaskNode = (TaskNodeTypeDef_Mini*)CurrentTaskNode->NextNode;
		free(CurrentTaskNode);
		CurrentTaskNode = NextTaskNode;
	}

	while (LastTaskNode != NULL)			//��ǰ������������
	{
		CurrentTaskNode = LastTaskNode;
		LastTaskNode = (TaskNodeTypeDef_Mini*)CurrentTaskNode->LastNode;
		free(CurrentTaskNode);
	}
}

void ThreadScheduler(ThreadListTypeDef* ThreadList)		//�̵߳�����
{
	ThreadTypeDef* CurrentThread = ThreadList->HeadThread;
	ThreadTypeDef* NextThread = NULL;
	while (CurrentThread != NULL)
	{
		NextThread = CurrentThread->NextThread;
		ThreadHandle(ThreadList, CurrentThread);
		CurrentThread = NextThread;
	}
}

ThreadTypeDef* CreatThreadNode(ThreadListTypeDef* ThreadList)
{
	void* ThreadArr = NULL;
	ThreadTypeDef Thread = {0, NULL, NULL , NULL};	//����һ��Thread

	Thread.NextThread = ThreadList->HeadThread;

	ThreadArr = malloc(sizeof(ThreadTypeDef));

	if (ThreadArr == NULL)
	{
		return NULL;
		//malloc_error("CreatThread");
	}

	memcpy(ThreadArr, &Thread, sizeof(ThreadTypeDef));

	ThreadList->HeadThread = ThreadArr;

	return (ThreadTypeDef*)ThreadArr;
}

void* CreatTaskNode(void* TaskNode, unsigned int NodeSize)
{
	void* NextTaskNodeArr = NULL;
	TaskNodeTypeDef_Mini* SourceNode = (TaskNodeTypeDef_Mini*)TaskNode;
	
	SourceNode->TaskComplete = 0;
	SourceNode->NextNode = NULL;
	SourceNode->JumpCount = 0;	//��ʼ�趨

	NextTaskNodeArr = malloc(NodeSize);
	
	if (NextTaskNodeArr == NULL)
	{
		return NULL;
		//malloc_error("CreatTaskNode");
	}

	memcpy(NextTaskNodeArr, TaskNode, NodeSize);	//д���ڴ��
	
	if (SourceNode->LastNode != NULL)
	{
		((TaskNodeTypeDef_Mini*)SourceNode->LastNode)->NextNode = NextTaskNodeArr;
	}
	
	return NextTaskNodeArr;
}

