#include<stdlib.h>

#include "MiniScheduler.h"
#include "UserTasks.h"
#include "UserThreads.h" 

void CreatUserThread1(ThreadListTypeDef* ThreadList)
{
	void* CurrentTaskNode = NULL;
	ThreadTypeDef* NewThreadNode = CreatThreadNode(ThreadList);	//选择线程优先级分组
	if (NewThreadNode == NULL)
	{
		return;
	}

	//Add Task1	首结点
	{
		TaskNodeTypeDef_1A TaskNode = { 0 };	//临时参数结点

		TaskNode.Task = Task_Print;
		TaskNode.LastNode = NULL;
		TaskNode.JumpDistance = 0;
		TaskNode.JumpTimesSet = 8;				//设置任务属性

		TaskNode.ARR_Parter1 = "Thread1 Hello!";		//写入任务参数

		CurrentTaskNode = CreatTaskNode(&TaskNode, sizeof(TaskNode));		//创建任务结点
		if (CurrentTaskNode == NULL)			//若结点创建失败则注销新创建的进程并退出
		{
			ThreadWriteOff(ThreadList, NewThreadNode);
			return;
		}

		NewThreadNode->TaskNode = CurrentTaskNode;		//首结点	
	}

	//Add Task2	次结点
	{
		TaskNodeTypeDef_1A TaskNode = { 0 };	//临时参数结点

		TaskNode.Task = Task_Print;
		TaskNode.LastNode = CurrentTaskNode;
		TaskNode.JumpDistance = 0;
		TaskNode.JumpTimesSet = 4;				//设置任务属性

		TaskNode.ARR_Parter1 = "Thread1 \033[1;31mDelay\033[0m";		//写入任务参数

		CurrentTaskNode = CreatTaskNode(&TaskNode, sizeof(TaskNode));		//创建任务结点
		if (CurrentTaskNode == NULL)			//若结点创建失败则注销新创建的进程并退出
		{
			ThreadWriteOff(ThreadList, NewThreadNode);
			return;
		}
	}

	//Add Task3	次结点
	{
		TaskNodeTypeDef_1A TaskNode3 = { 0 };	//临时参数结点

		TaskNode3.Task = Task_Print;
		TaskNode3.LastNode = CurrentTaskNode;
		TaskNode3.JumpDistance = 0;
		TaskNode3.JumpTimesSet = 4;				//设置任务属性

		TaskNode3.ARR_Parter1 = "Thread1 Nice!";		//写入任务参数

		CurrentTaskNode = CreatTaskNode(&TaskNode3, sizeof(TaskNode3));		//创建任务结点
		if (CurrentTaskNode == NULL)			//若结点创建失败则注销新创建的进程并退出
		{
			ThreadWriteOff(ThreadList, NewThreadNode);
			return;
		}
	}

	//Add Task4	次结点
	{
		TaskNodeTypeDef_Mini TaskNode4 = { 0 };	//临时参数结点

		TaskNode4.Task = Task_Null;
		TaskNode4.LastNode = CurrentTaskNode;
		TaskNode4.JumpDistance = -3;
		TaskNode4.JumpTimesSet = -1;				//设置任务属性

		CurrentTaskNode = CreatTaskNode(&TaskNode4, sizeof(TaskNode4));		//创建任务结点
	}

	NewThreadNode->ThreadRunning = 1;	//启动线程
}

void CreatUserThread2(ThreadListTypeDef* ThreadList)
{
	void* CurrentTaskNode = NULL;
	ThreadTypeDef* NewThreadNode = CreatThreadNode(ThreadList);	//选择线程优先级分组
	if (NewThreadNode == NULL)
	{
		return;
	}

	//Add Task1	首结点
	{
		TaskNodeTypeDef_1A TaskNode = { 0 };	//临时参数结点

		TaskNode.Task = Task_Print;
		TaskNode.LastNode = NULL;
		TaskNode.JumpDistance = 0;
		TaskNode.JumpTimesSet = 3;				//设置任务属性

		TaskNode.ARR_Parter1 = "Thread2 芜湖！";		//写入任务参数

		CurrentTaskNode = CreatTaskNode(&TaskNode, sizeof(TaskNode));		//创建任务结点
		if (CurrentTaskNode == NULL)			//若结点创建失败则注销新创建的进程并退出
		{
			ThreadWriteOff(ThreadList, NewThreadNode);
			return;
		}

		NewThreadNode->TaskNode = CurrentTaskNode;		//首结点	
	}

	//Add Task2	次结点
	{
		TaskNodeTypeDef_1A TaskNode = { 0 };	//临时参数结点

		TaskNode.Task = Task_Print;
		TaskNode.LastNode = CurrentTaskNode;
		TaskNode.JumpDistance = 0;
		TaskNode.JumpTimesSet = 2;				//设置任务属性

		TaskNode.ARR_Parter1 = "Thread2 \033[1;31mDelay\033[0m";		//写入任务参数

		CurrentTaskNode = CreatTaskNode(&TaskNode, sizeof(TaskNode));		//创建任务结点
		if (CurrentTaskNode == NULL)			//若结点创建失败则注销新创建的进程并退出
		{
			ThreadWriteOff(ThreadList, NewThreadNode);
			return;
		}
	}

	//Add Task3	次结点
	{
		TaskNodeTypeDef_1A TaskNode3 = { 0 };	//临时参数结点

		TaskNode3.Task = Task_Print;
		TaskNode3.LastNode = CurrentTaskNode;
		TaskNode3.JumpDistance = 0;
		TaskNode3.JumpTimesSet = 1;				//设置任务属性

		TaskNode3.ARR_Parter1 = "Thread2 鸡你太美！";		//写入任务参数

		CurrentTaskNode = CreatTaskNode(&TaskNode3, sizeof(TaskNode3));		//创建任务结点
		if (CurrentTaskNode == NULL)			//若结点创建失败则注销新创建的进程并退出
		{
			ThreadWriteOff(ThreadList, NewThreadNode);
			return;
		}
	}

	//Add Task4	次结点
	{
		TaskNodeTypeDef_Mini TaskNode4 = { 0 };	//临时参数结点

		TaskNode4.Task = Task_Null;
		TaskNode4.LastNode = CurrentTaskNode;
		TaskNode4.JumpDistance = -3;
		TaskNode4.JumpTimesSet = -1;				//设置任务属性

		CurrentTaskNode = CreatTaskNode(&TaskNode4, sizeof(TaskNode4));		//创建任务结点
	}

	NewThreadNode->ThreadRunning = 1;	//启动线程
}