#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "MiniScheduler.h"

ThreadListTypeDef HighPriorityThreadList = {NULL};	//高优先线程队列
ThreadListTypeDef MidPriorityThreadList = { NULL};	//中优先线程队列
ThreadListTypeDef LowPriorityThreadList = { NULL};	//低优先线程队列

void ThreadHandle(ThreadListTypeDef* ThreadList, ThreadTypeDef* Thread)		//线程运行
{
	TaskNodeTypeDef_Mini* CurrentTaskNode = (TaskNodeTypeDef_Mini*)Thread->TaskNode;
	
	if (Thread->ThreadRunning)	//线程运行中
	{
		(*(CurrentTaskNode->Task))((void*)CurrentTaskNode);	//运行任务

		if (CurrentTaskNode->TaskComplete)	//当前任务节点完成
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
			if (CurrentTaskNode->JumpCount < 0)	//溢出
			{
				CurrentTaskNode->JumpCount = 0;
			}
			CurrentTaskNode->TaskComplete = 0;	//重置任务状态
		}
	}
}

void ThreadWriteOff(ThreadListTypeDef* ThreadList, ThreadTypeDef* ThreadNode)	//注销线程
{
	ThreadTypeDef* ThreadListSearchNode = ThreadList->HeadThread;
	TaskNodeTypeDef_Mini* CurrentTaskNode = NULL;
	TaskNodeTypeDef_Mini* NextTaskNode = NULL;
	TaskNodeTypeDef_Mini* LastTaskNode = NULL;
	int ThreadNodeExist = 0;

	while (ThreadListSearchNode != NULL)	//清理线程链表结点
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
		free(ThreadNode);		//释放线程链表结点空间
	}
	else
	{
		return;
	}

	if (CurrentTaskNode != NULL)			//是否存在至少一个结点
	{
		LastTaskNode = CurrentTaskNode->LastNode;
	}
	else
	{
		return;
	}

	while (CurrentTaskNode != NULL)			//清后面任务链表结点
	{
		NextTaskNode = (TaskNodeTypeDef_Mini*)CurrentTaskNode->NextNode;
		free(CurrentTaskNode);
		CurrentTaskNode = NextTaskNode;
	}

	while (LastTaskNode != NULL)			//清前面任务链表结点
	{
		CurrentTaskNode = LastTaskNode;
		LastTaskNode = (TaskNodeTypeDef_Mini*)CurrentTaskNode->LastNode;
		free(CurrentTaskNode);
	}
}

void ThreadScheduler(ThreadListTypeDef* ThreadList)		//线程调度器
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
	ThreadTypeDef Thread = {0, NULL, NULL , NULL};	//定义一个Thread

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
	SourceNode->JumpCount = 0;	//初始设定

	NextTaskNodeArr = malloc(NodeSize);
	
	if (NextTaskNodeArr == NULL)
	{
		return NULL;
		//malloc_error("CreatTaskNode");
	}

	memcpy(NextTaskNodeArr, TaskNode, NodeSize);	//写入内存块
	
	if (SourceNode->LastNode != NULL)
	{
		((TaskNodeTypeDef_Mini*)SourceNode->LastNode)->NextNode = NextTaskNodeArr;
	}
	
	return NextTaskNodeArr;
}

