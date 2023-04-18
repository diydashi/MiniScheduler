#ifndef _MINISCHEDULER_H_
#define _MINISCHEDULER_H_

typedef struct
{
	void* HeadThread;	//���̵߳�ַ
}ThreadListTypeDef;		//�߳��������

ThreadListTypeDef HighPriorityThreadList;					//�������̶߳���
ThreadListTypeDef MidPriorityThreadList;					//�������̶߳���
ThreadListTypeDef LowPriorityThreadList;					//�������̶߳���

typedef struct
{
	int ThreadRunning;	//�߳�����״̬
	void* TaskNode;		//��ǰ����ڵ��׵�ַ
	void* LastThread;	//��һ���߳��׵�ַ
	void* NextThread;	//��һ���߳��׵�ַ
}ThreadTypeDef;			//�߳̽�㶨��


/*---------�̵߳������ֱ�������ռ���ȼ���ͬ�Ķ�ʱ���ж���-------------------------*/
void ThreadScheduler(ThreadListTypeDef*	ThreadList);							//�̵߳�����

void ThreadHandle(ThreadListTypeDef* ThreadList, ThreadTypeDef* Thread);			//�߳�����

void ThreadWriteOff(ThreadListTypeDef* ThreadList, ThreadTypeDef* ThreadNode);	//ע���߳�

ThreadTypeDef* CreatThreadNode(ThreadListTypeDef* ThreadList);					//�����߳̽��

void* CreatTaskNode(void* TaskNode, unsigned int NodeSize);						//����������
//	Task ������
//	NodeSize	����ֽڴ�С	

typedef struct
{
	int TaskComplete;	//�����Ƿ����
	void (*Task)(void*);//������
	void* LastNode;		//��һ������ַ
	void* NextNode;		//��һ������ַ
	int JumpDistance;	//������ɺ���ת�Ľڵ��� ��������ת 0������������ת�� ��������ת Ĭ��1������һ���ڵ㣬��Ĭ��ֵֻ����JumpTimesSet��0ʱ��Ч���ɱ������д��ʵ��ѭ��
	int JumpCount;		//����ת�������� ��ʵ��ѭ�����޴�
	int JumpTimesSet;	//Ŀ����ת��������0����JumpCount���ʱ JumpDistance��1��-1��ѭ��
	//newmember2
	//newmember3
}TaskNodeTypeDef_Mini;

typedef struct
{
	int TaskComplete;	//�����Ƿ����
	void (*Task)(void*);//������
	void* LastNode;		//��һ������ַ
	void* NextNode;		//��һ������ַ
	int JumpDistance;	//������ɺ���ת�Ľڵ��� ��������ת 0������������ת�� ��������ת Ĭ��1������һ���ڵ㣬��Ĭ��ֵֻ����JumpTimesSet��0ʱ��Ч���ɱ������д��ʵ��ѭ��
	int JumpCount;		//����ת�������� ��ʵ��ѭ�����޴�
	int JumpTimesSet;	//Ŀ����ת��������0����JumpCount���ʱ JumpDistance��1��-1��ѭ��
	//newmember2
	//newmember3
/*------������� int��--------------*/
	int INT_Parter1;
}TaskNodeTypeDef_1I;

typedef struct
{
	int TaskComplete;	//�����Ƿ����
	void (*Task)(void*);//������
	void* LastNode;		//��һ������ַ
	void* NextNode;		//��һ������ַ
	int JumpDistance;	//������ɺ���ת�Ľڵ��� ��������ת 0������������ת�� ��������ת Ĭ��1������һ���ڵ㣬�ɱ������д��ʵ��ѭ��
	int JumpCount;		//��ת���� ��ʵ��ѭ�����޴�
	int JumpTimesSet;
	//newmember2
	//newmember3
/*------������� int��--------------*/
	int INT_Parter1;
	int INT_Parter2;
}TaskNodeTypeDef_2I;

typedef struct
{
	int TaskComplete;	//�����Ƿ����
	void (*Task)(void*);//������
	void* LastNode;		//��һ������ַ
	void* NextNode;		//��һ������ַ
	int JumpDistance;	//������ɺ���ת�Ľڵ��� ��������ת 0������������ת�� ��������ת Ĭ��1������һ���ڵ㣬�ɱ������д��ʵ��ѭ��
	int JumpCount;		//��ת���� ��ʵ��ѭ�����޴�
	int JumpTimesSet;
	//newmember2
	//newmember3
/*------������� int��--------------*/
	int INT_Parter1;
	int INT_Parter2;
	int INT_Parter3;
}TaskNodeTypeDef_3I;

typedef struct
{
	int TaskComplete;	//�����Ƿ����
	void (*Task)(void*);//������
	void* LastNode;		//��һ������ַ
	void* NextNode;		//��һ������ַ
	int JumpDistance;	//������ɺ���ת�Ľڵ��� ��������ת 0������������ת�� ��������ת Ĭ��1������һ���ڵ㣬�ɱ������д��ʵ��ѭ��
	int JumpCount;		//��ת���� ��ʵ��ѭ�����޴�
	int JumpTimesSet;
	//newmember2
	//newmember3
/*------������� int��--------------*/
	int INT_Parter1;
	int INT_Parter2;
	int INT_Parter3;
	int INT_Parter4;
	int INT_Parter5;
}TaskNodeTypeDef_5I;

typedef struct
{
	int TaskComplete;	//�����Ƿ����
	void (*Task)(void*);//������
	void* LastNode;		//��һ������ַ
	void* NextNode;		//��һ������ַ
	int JumpDistance;	//������ɺ���ת�Ľڵ��� ��������ת 0������������ת�� ��������ת Ĭ��1������һ���ڵ㣬�ɱ������д��ʵ��ѭ��
	int JumpCount;		//��ת���� ��ʵ��ѭ�����޴�
	int JumpTimesSet;
	//newmember2
	//newmember3
/*------������� int��--------------*/
	int INT_Parter1;
	int INT_Parter2;
	int INT_Parter3;
	int INT_Parter4;
	int INT_Parter5;
	int INT_Parter6;
	int INT_Parter7;
	int INT_Parter8;
	int INT_Parter9;
	int INT_Parter10;
}TaskNodeTypeDef_10I;

typedef struct
{
	int TaskComplete;	//�����Ƿ����
	void (*Task)(void*);//������
	void* LastNode;		//��һ������ַ
	void* NextNode;		//��һ������ַ
	int JumpDistance;	//������ɺ���ת�Ľڵ��� ��������ת 0������������ת�� ��������ת Ĭ��1������һ���ڵ㣬�ɱ������д��ʵ��ѭ��
	int JumpCount;		//��ת���� ��ʵ��ѭ�����޴�
	int JumpTimesSet;
	//newmember2
	//newmember3
/*------������� ָ����--------------*/
	void* ARR_Parter1;
}TaskNodeTypeDef_1A;

typedef struct
{
	int TaskComplete;	//�����Ƿ����
	void (*Task)(void*);//������
	void* LastNode;		//��һ������ַ
	void* NextNode;		//��һ������ַ
	int JumpDistance;	//������ɺ���ת�Ľڵ��� ��������ת 0������������ת�� ��������ת Ĭ��1������һ���ڵ㣬�ɱ������д��ʵ��ѭ��
	int JumpCount;		//��ת���� ��ʵ��ѭ�����޴�
	int JumpTimesSet;
	//newmember2
	//newmember3
/*------������� ָ����--------------*/
	void* ARR_Parter1;
	void* ARR_Parter2;
}TaskNodeTypeDef_2A;

typedef struct
{
	int TaskComplete;	//�����Ƿ����
	void (*Task)(void*);//������
	void* LastNode;		//��һ������ַ
	void* NextNode;		//��һ������ַ
	int JumpDistance;	//������ɺ���ת�Ľڵ��� ��������ת 0������������ת�� ��������ת Ĭ��1������һ���ڵ㣬�ɱ������д��ʵ��ѭ��
	int JumpCount;		//��ת���� ��ʵ��ѭ�����޴�
	int JumpTimesSet;
	//newmember2
	//newmember3
/*------������� ָ����--------------*/
	void* ARR_Parter1;
	void* ARR_Parter2;
	void* ARR_Parter3;
}TaskNodeTypeDef_3A;

typedef struct
{
	int TaskComplete;	//�����Ƿ����
	void (*Task)(void*);//������
	void* LastNode;		//��һ������ַ
	void* NextNode;		//��һ������ַ
	int JumpDistance;	//������ɺ���ת�Ľڵ��� ��������ת 0������������ת�� ��������ת Ĭ��1������һ���ڵ㣬�ɱ������д��ʵ��ѭ��
	int JumpCount;		//��ת���� ��ʵ��ѭ�����޴�
	int JumpTimesSet;
	//newmember2
	//newmember3
/*------������� ָ����--------------*/
	void* ARR_Parter1;
	void* ARR_Parter2;
	void* ARR_Parter3;
	void* ARR_Parter4;
	void* ARR_Parter5;
}TaskNodeTypeDef_5A;

typedef struct
{
	int TaskComplete;	//�����Ƿ����
	void (*Task)(void*);//������
	void* LastNode;		//��һ������ַ
	void* NextNode;		//��һ������ַ
	int JumpDistance;	//������ɺ���ת�Ľڵ��� ��������ת 0������������ת�� ��������ת Ĭ��1������һ���ڵ㣬�ɱ������д��ʵ��ѭ��
	int JumpCount;		//��ת���� ��ʵ��ѭ�����޴�
	int JumpTimesSet;
	//newmember2
	//newmember3
/*------������� ָ����--------------*/
	void* ARR_Parter1;
	void* ARR_Parter2;
	void* ARR_Parter3;
	void* ARR_Parter4;
	void* ARR_Parter5;
	void* ARR_Parter6;
	void* ARR_Parter7;
	void* ARR_Parter8;
	void* ARR_Parter9;
	void* ARR_Parter10;
}TaskNodeTypeDef_10A;

typedef struct
{
	int TaskComplete;	//�����Ƿ����
	void (*Task)(void*);//������
	void* LastNode;		//��һ������ַ
	void* NextNode;		//��һ������ַ
	int JumpDistance;	//������ɺ���ת�Ľڵ��� ��������ת 0������������ת�� ��������ת Ĭ��1������һ���ڵ㣬��Ĭ��ֵֻ����JumpTimesSet��0ʱ��Ч���ɱ������д��ʵ��ѭ��
	int JumpCount;		//����ת�������� ��ʵ��ѭ�����޴�
	int JumpTimesSet;	//Ŀ����ת��������0����JumpCount���ʱ JumpDistance��1��-1��ѭ��
	//newmember2
	//newmember3
/*------������� int��--------------*/
	int INT_Parter1;
/*------������� ָ����--------------*/
	void* ARR_Parter1;
}TaskNodeTypeDef_1I_1A;

typedef struct
{
	int TaskComplete;	//�����Ƿ����
	void (*Task)(void*);//������
	void* LastNode;		//��һ������ַ
	void* NextNode;		//��һ������ַ
	int JumpDistance;	//������ɺ���ת�Ľڵ��� ��������ת 0������������ת�� ��������ת Ĭ��1������һ���ڵ㣬�ɱ������д��ʵ��ѭ��
	int JumpCount;		//��ת���� ��ʵ��ѭ�����޴�
	int JumpTimesSet;
	//newmember2
	//newmember3
/*------������� int��--------------*/
	int INT_Parter1;
	int INT_Parter2;
/*------������� ָ����--------------*/
	void* ARR_Parter1;
	void* ARR_Parter2;
}TaskNodeTypeDef_2I_2A;

typedef struct
{
	int TaskComplete;	//�����Ƿ����
	void (*Task)(void*);//������
	void* LastNode;		//��һ������ַ
	void* NextNode;		//��һ������ַ
	int JumpDistance;	//������ɺ���ת�Ľڵ��� ��������ת 0������������ת�� ��������ת Ĭ��1������һ���ڵ㣬�ɱ������д��ʵ��ѭ��
	int JumpCount;		//��ת���� ��ʵ��ѭ�����޴�
	int JumpTimesSet;
	//newmember2
	//newmember3
/*------������� int��--------------*/
	int INT_Parter1;
	int INT_Parter2;
	int INT_Parter3;
/*------������� ָ����--------------*/
	void* ARR_Parter1;
	void* ARR_Parter2;
	void* ARR_Parter3;
}TaskNodeTypeDef_3I_3A;

typedef struct
{
	int TaskComplete;	//�����Ƿ����
	void (*Task)(void*);//������
	void* LastNode;		//��һ������ַ
	void* NextNode;		//��һ������ַ
	int JumpDistance;	//������ɺ���ת�Ľڵ��� ��������ת 0������������ת�� ��������ת Ĭ��1������һ���ڵ㣬�ɱ������д��ʵ��ѭ��
	int JumpCount;		//��ת���� ��ʵ��ѭ�����޴�
	int JumpTimesSet;
	//newmember2
	//newmember3
/*------������� int��--------------*/
	int INT_Parter1;
	int INT_Parter2;
	int INT_Parter3;
	int INT_Parter4;
	int INT_Parter5;
/*------������� ָ����--------------*/
	void* ARR_Parter1;
	void* ARR_Parter2;
	void* ARR_Parter3;
	void* ARR_Parter4;
	void* ARR_Parter5;
}TaskNodeTypeDef_5I_5A;

typedef struct
{
	int TaskComplete;	//�����Ƿ����
	void (*Task)(void*);//������
	void* LastNode;		//��һ������ַ
	void* NextNode;		//��һ������ַ
	int JumpDistance;	//������ɺ���ת�Ľڵ��� ��������ת 0������������ת�� ��������ת Ĭ��1������һ���ڵ㣬�ɱ������д��ʵ��ѭ��
	int JumpCount;		//��ת���� ��ʵ��ѭ�����޴�
	int JumpTimesSet;
	//newmember2
	//newmember3
/*------������� int��--------------*/
	int INT_Parter1;
	int INT_Parter2;
	int INT_Parter3;
	int INT_Parter4;
	int INT_Parter5;
	int INT_Parter6;
	int INT_Parter7;
	int INT_Parter8;
	int INT_Parter9;
	int INT_Parter10;
/*------������� ָ����--------------*/
	void* ARR_Parter1;
	void* ARR_Parter2;
	void* ARR_Parter3;
	void* ARR_Parter4;
	void* ARR_Parter5;
	void* ARR_Parter6;
	void* ARR_Parter7;
	void* ARR_Parter8;
	void* ARR_Parter9;
	void* ARR_Parter10;
}TaskNodeTypeDef_10I_10A;

						
#endif
