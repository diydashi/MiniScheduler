#include "MiniScheduler.h"
#include "UserTasks.h"

/*-----�����н�ֹʹ��static��̬���� ��ֹ�����ʱ ��ֹ��ѭ�����κ�����¶�Ҫ�ܿ����˳���--------*/

void Task_Null(void* Parameters)		//������
{
	TaskNodeTypeDef_Mini* TaskNode = (TaskNodeTypeDef_Mini*)Parameters;
	int* TaskComplete = &(TaskNode->TaskComplete);	//��־λ

	(*TaskComplete) = 1;	//�˳�
}

void Task_Print(void* Parameters)
{
	TaskNodeTypeDef_1A* TaskNode = (TaskNodeTypeDef_1A*)Parameters;
	const char* String = TaskNode->ARR_Parter1;

	int* TaskComplete = &(TaskNode->TaskComplete);	//��־λ

	printf("%s\t\t", String);
	(*TaskComplete) = 1;
}

void Task_Delay_ms(void* Parameters)	//��ʱ DelayTime_ms ������������
{
	TaskNodeTypeDef_3I* TaskNode = (TaskNodeTypeDef_3I*)Parameters;
	int Delay_ms = TaskNode->INT_Parter1;		//����1 ����int
	int Freq = TaskNode->INT_Parter2;		//����2 ����int
	int* Count = &(TaskNode->INT_Parter3);	//����3 ����int
	int* TaskComplete = &(TaskNode->TaskComplete);	//��־λ

	int CountSet = Delay_ms * Freq / 1000;

	if ((*Count) >= CountSet)
	{
		(*Count) = 1;
		(*TaskComplete) = 1;
	}
	else
	{
		(*Count)++;
	}
}

void Task_ConstVarCmp(void* Parameters)	//arr1��arr2��ַ��Ӧֵ ��ϵΪ Type��ַ��Ӧ�ַ���ʱ���������
{
	TaskNodeTypeDef_2I_2A* TaskNode = (TaskNodeTypeDef_2I_2A*)Parameters;
	int Const = TaskNode->INT_Parter1;			//����1 ����int
	int* VarArr = TaskNode->ARR_Parter1;		//����2 ����int��ַ
	const char* Type = TaskNode->ARR_Parter2;	//����3 ����char��ַ

	int* TaskComplete = &(TaskNode->TaskComplete);	//��־λ

	if (strcmp(Type, "==") == 0)	//*arr1 = *arr2 �����ͨ��
	{
		if (Const == *VarArr)
		{
			(*TaskComplete) = 1;
		}
		return;
	}

	if (strcmp(Type, "!=") == 0)	//*arr1 �� *arr2 �����ͨ��
	{
		if (Const != *VarArr)
		{
			(*TaskComplete) = 1;
		}
		return;
	}

	if (strcmp(Type, ">") == 0)		//*arr1 > *arr2 �����ͨ��
	{
		if (Const > *VarArr)
		{
			(*TaskComplete) = 1;
		}
		return;
	}

	if (strcmp(Type, "<") == 0)		//*arr1 < *arr2 �����ͨ��
	{
		if (Const < *VarArr)
		{
			(*TaskComplete) = 1;
		}
		return;
	}

	if (strcmp(Type, ">=") == 0)	//*arr1 �� *arr2 �����ͨ��
	{
		if (Const > *VarArr)
		{
			(*TaskComplete) = 1;
		}
		return;
	}
	   
	if (strcmp(Type, "<=") == 0)	//*arr1 �� *arr2 �����ͨ��
	{
		if (Const < *VarArr)
		{
			(*TaskComplete) = 1;
		}
		return;
	}
}

void Task_VarVarCmp(void* Parameters)	//arr1��arr2��ַ��Ӧֵ ��ϵΪ Type��ַ��Ӧ�ַ���ʱ���������
{
	TaskNodeTypeDef_3A* TaskNode = (TaskNodeTypeDef_3A*)Parameters;
	int* VarArr1 = TaskNode->ARR_Parter1;		//����1 ����int��ַ
	int* VarArr2 = TaskNode->ARR_Parter2;		//����1 ����int��ַ
	const char* Type = TaskNode->ARR_Parter3;	//����3 ����char��ַ

	int* TaskComplete = &(TaskNode->TaskComplete);	//��־λ

	printf("%s\n", Type);

	if (strcmp(Type, "==") == 0)	//*arr1 = *arr2 �����ͨ��
	{
		if (*VarArr1 == *VarArr2)
		{
			(*TaskComplete) = 1;
		}
		return;
	}

	if (strcmp(Type, "!=") == 0)	//*arr1 �� *arr2 �����ͨ��
	{
		if (*VarArr1 != *VarArr2)
		{
			(*TaskComplete) = 1;
		}
		return;
	}

	if (strcmp(Type, ">") == 0)		//*arr1 > *arr2 �����ͨ��
	{
		if (*VarArr1 > *VarArr2)
		{
			(*TaskComplete) = 1;
		}
		return;
	}

	if (strcmp(Type, "<") == 0)		//*arr1 < *arr2 �����ͨ��
	{
		if (*VarArr1 < *VarArr2)
		{
			(*TaskComplete) = 1;
		}
		return;
	}

	if (strcmp(Type, ">=") == 0)	//*arr1 �� *arr2 �����ͨ��
	{
		if (*VarArr1 > *VarArr2)
		{
			(*TaskComplete) = 1;
		}
		return;
	}

	if (strcmp(Type, "<=") == 0)	//*arr1 �� *arr2 �����ͨ��
	{
		if (*VarArr1 < *VarArr2)
		{
			(*TaskComplete) = 1;
		}
		return;
	}
}



