#include<stdlib.h>

#include "MiniScheduler.h"
#include "UserTasks.h"
#include "UserThreads.h" 

void CreatUserThread1(ThreadListTypeDef* ThreadList)
{
	void* CurrentTaskNode = NULL;
	ThreadTypeDef* NewThreadNode = CreatThreadNode(ThreadList);	//ѡ���߳����ȼ�����
	if (NewThreadNode == NULL)
	{
		return;
	}

	//Add Task1	�׽��
	{
		TaskNodeTypeDef_1A TaskNode = { 0 };	//��ʱ�������

		TaskNode.Task = Task_Print;
		TaskNode.LastNode = NULL;
		TaskNode.JumpDistance = 0;
		TaskNode.JumpTimesSet = 8;				//������������

		TaskNode.ARR_Parter1 = "Thread1 Hello!";		//д���������

		CurrentTaskNode = CreatTaskNode(&TaskNode, sizeof(TaskNode));		//����������
		if (CurrentTaskNode == NULL)			//����㴴��ʧ����ע���´����Ľ��̲��˳�
		{
			ThreadWriteOff(ThreadList, NewThreadNode);
			return;
		}

		NewThreadNode->TaskNode = CurrentTaskNode;		//�׽��	
	}

	//Add Task2	�ν��
	{
		TaskNodeTypeDef_1A TaskNode = { 0 };	//��ʱ�������

		TaskNode.Task = Task_Print;
		TaskNode.LastNode = CurrentTaskNode;
		TaskNode.JumpDistance = 0;
		TaskNode.JumpTimesSet = 4;				//������������

		TaskNode.ARR_Parter1 = "Thread1 \033[1;31mDelay\033[0m";		//д���������

		CurrentTaskNode = CreatTaskNode(&TaskNode, sizeof(TaskNode));		//����������
		if (CurrentTaskNode == NULL)			//����㴴��ʧ����ע���´����Ľ��̲��˳�
		{
			ThreadWriteOff(ThreadList, NewThreadNode);
			return;
		}
	}

	//Add Task3	�ν��
	{
		TaskNodeTypeDef_1A TaskNode3 = { 0 };	//��ʱ�������

		TaskNode3.Task = Task_Print;
		TaskNode3.LastNode = CurrentTaskNode;
		TaskNode3.JumpDistance = 0;
		TaskNode3.JumpTimesSet = 4;				//������������

		TaskNode3.ARR_Parter1 = "Thread1 Nice!";		//д���������

		CurrentTaskNode = CreatTaskNode(&TaskNode3, sizeof(TaskNode3));		//����������
		if (CurrentTaskNode == NULL)			//����㴴��ʧ����ע���´����Ľ��̲��˳�
		{
			ThreadWriteOff(ThreadList, NewThreadNode);
			return;
		}
	}

	//Add Task4	�ν��
	{
		TaskNodeTypeDef_Mini TaskNode4 = { 0 };	//��ʱ�������

		TaskNode4.Task = Task_Null;
		TaskNode4.LastNode = CurrentTaskNode;
		TaskNode4.JumpDistance = -3;
		TaskNode4.JumpTimesSet = -1;				//������������

		CurrentTaskNode = CreatTaskNode(&TaskNode4, sizeof(TaskNode4));		//����������
	}

	NewThreadNode->ThreadRunning = 1;	//�����߳�
}

void CreatUserThread2(ThreadListTypeDef* ThreadList)
{
	void* CurrentTaskNode = NULL;
	ThreadTypeDef* NewThreadNode = CreatThreadNode(ThreadList);	//ѡ���߳����ȼ�����
	if (NewThreadNode == NULL)
	{
		return;
	}

	//Add Task1	�׽��
	{
		TaskNodeTypeDef_1A TaskNode = { 0 };	//��ʱ�������

		TaskNode.Task = Task_Print;
		TaskNode.LastNode = NULL;
		TaskNode.JumpDistance = 0;
		TaskNode.JumpTimesSet = 3;				//������������

		TaskNode.ARR_Parter1 = "Thread2 �ߺ���";		//д���������

		CurrentTaskNode = CreatTaskNode(&TaskNode, sizeof(TaskNode));		//����������
		if (CurrentTaskNode == NULL)			//����㴴��ʧ����ע���´����Ľ��̲��˳�
		{
			ThreadWriteOff(ThreadList, NewThreadNode);
			return;
		}

		NewThreadNode->TaskNode = CurrentTaskNode;		//�׽��	
	}

	//Add Task2	�ν��
	{
		TaskNodeTypeDef_1A TaskNode = { 0 };	//��ʱ�������

		TaskNode.Task = Task_Print;
		TaskNode.LastNode = CurrentTaskNode;
		TaskNode.JumpDistance = 0;
		TaskNode.JumpTimesSet = 2;				//������������

		TaskNode.ARR_Parter1 = "Thread2 \033[1;31mDelay\033[0m";		//д���������

		CurrentTaskNode = CreatTaskNode(&TaskNode, sizeof(TaskNode));		//����������
		if (CurrentTaskNode == NULL)			//����㴴��ʧ����ע���´����Ľ��̲��˳�
		{
			ThreadWriteOff(ThreadList, NewThreadNode);
			return;
		}
	}

	//Add Task3	�ν��
	{
		TaskNodeTypeDef_1A TaskNode3 = { 0 };	//��ʱ�������

		TaskNode3.Task = Task_Print;
		TaskNode3.LastNode = CurrentTaskNode;
		TaskNode3.JumpDistance = 0;
		TaskNode3.JumpTimesSet = 1;				//������������

		TaskNode3.ARR_Parter1 = "Thread2 ����̫����";		//д���������

		CurrentTaskNode = CreatTaskNode(&TaskNode3, sizeof(TaskNode3));		//����������
		if (CurrentTaskNode == NULL)			//����㴴��ʧ����ע���´����Ľ��̲��˳�
		{
			ThreadWriteOff(ThreadList, NewThreadNode);
			return;
		}
	}

	//Add Task4	�ν��
	{
		TaskNodeTypeDef_Mini TaskNode4 = { 0 };	//��ʱ�������

		TaskNode4.Task = Task_Null;
		TaskNode4.LastNode = CurrentTaskNode;
		TaskNode4.JumpDistance = -3;
		TaskNode4.JumpTimesSet = -1;				//������������

		CurrentTaskNode = CreatTaskNode(&TaskNode4, sizeof(TaskNode4));		//����������
	}

	NewThreadNode->ThreadRunning = 1;	//�����߳�
}