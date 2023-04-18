#include "MiniScheduler.h"
#include "UserTasks.h"

/*-----任务中禁止使用static静态变量 禁止软件延时 禁止死循环（任何情况下都要能快速退出）--------*/

void Task_Null(void* Parameters)		//空任务
{
	TaskNodeTypeDef_Mini* TaskNode = (TaskNodeTypeDef_Mini*)Parameters;
	int* TaskComplete = &(TaskNode->TaskComplete);	//标志位

	(*TaskComplete) = 1;	//退出
}

void Task_Print(void* Parameters)
{
	TaskNodeTypeDef_1A* TaskNode = (TaskNodeTypeDef_1A*)Parameters;
	const char* String = TaskNode->ARR_Parter1;

	int* TaskComplete = &(TaskNode->TaskComplete);	//标志位

	printf("%s\t\t", String);
	(*TaskComplete) = 1;
}

void Task_Delay_ms(void* Parameters)	//延时 DelayTime_ms 毫秒后结束任务
{
	TaskNodeTypeDef_3I* TaskNode = (TaskNodeTypeDef_3I*)Parameters;
	int Delay_ms = TaskNode->INT_Parter1;		//参数1 类型int
	int Freq = TaskNode->INT_Parter2;		//参数2 类型int
	int* Count = &(TaskNode->INT_Parter3);	//参数3 类型int
	int* TaskComplete = &(TaskNode->TaskComplete);	//标志位

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

void Task_ConstVarCmp(void* Parameters)	//arr1与arr2地址对应值 关系为 Type地址对应字符串时，任务结束
{
	TaskNodeTypeDef_2I_2A* TaskNode = (TaskNodeTypeDef_2I_2A*)Parameters;
	int Const = TaskNode->INT_Parter1;			//参数1 类型int
	int* VarArr = TaskNode->ARR_Parter1;		//参数2 类型int地址
	const char* Type = TaskNode->ARR_Parter2;	//参数3 类型char地址

	int* TaskComplete = &(TaskNode->TaskComplete);	//标志位

	if (strcmp(Type, "==") == 0)	//*arr1 = *arr2 情况下通过
	{
		if (Const == *VarArr)
		{
			(*TaskComplete) = 1;
		}
		return;
	}

	if (strcmp(Type, "!=") == 0)	//*arr1 ≠ *arr2 情况下通过
	{
		if (Const != *VarArr)
		{
			(*TaskComplete) = 1;
		}
		return;
	}

	if (strcmp(Type, ">") == 0)		//*arr1 > *arr2 情况下通过
	{
		if (Const > *VarArr)
		{
			(*TaskComplete) = 1;
		}
		return;
	}

	if (strcmp(Type, "<") == 0)		//*arr1 < *arr2 情况下通过
	{
		if (Const < *VarArr)
		{
			(*TaskComplete) = 1;
		}
		return;
	}

	if (strcmp(Type, ">=") == 0)	//*arr1 ≥ *arr2 情况下通过
	{
		if (Const > *VarArr)
		{
			(*TaskComplete) = 1;
		}
		return;
	}
	   
	if (strcmp(Type, "<=") == 0)	//*arr1 ≤ *arr2 情况下通过
	{
		if (Const < *VarArr)
		{
			(*TaskComplete) = 1;
		}
		return;
	}
}

void Task_VarVarCmp(void* Parameters)	//arr1与arr2地址对应值 关系为 Type地址对应字符串时，任务结束
{
	TaskNodeTypeDef_3A* TaskNode = (TaskNodeTypeDef_3A*)Parameters;
	int* VarArr1 = TaskNode->ARR_Parter1;		//参数1 类型int地址
	int* VarArr2 = TaskNode->ARR_Parter2;		//参数1 类型int地址
	const char* Type = TaskNode->ARR_Parter3;	//参数3 类型char地址

	int* TaskComplete = &(TaskNode->TaskComplete);	//标志位

	printf("%s\n", Type);

	if (strcmp(Type, "==") == 0)	//*arr1 = *arr2 情况下通过
	{
		if (*VarArr1 == *VarArr2)
		{
			(*TaskComplete) = 1;
		}
		return;
	}

	if (strcmp(Type, "!=") == 0)	//*arr1 ≠ *arr2 情况下通过
	{
		if (*VarArr1 != *VarArr2)
		{
			(*TaskComplete) = 1;
		}
		return;
	}

	if (strcmp(Type, ">") == 0)		//*arr1 > *arr2 情况下通过
	{
		if (*VarArr1 > *VarArr2)
		{
			(*TaskComplete) = 1;
		}
		return;
	}

	if (strcmp(Type, "<") == 0)		//*arr1 < *arr2 情况下通过
	{
		if (*VarArr1 < *VarArr2)
		{
			(*TaskComplete) = 1;
		}
		return;
	}

	if (strcmp(Type, ">=") == 0)	//*arr1 ≥ *arr2 情况下通过
	{
		if (*VarArr1 > *VarArr2)
		{
			(*TaskComplete) = 1;
		}
		return;
	}

	if (strcmp(Type, "<=") == 0)	//*arr1 ≤ *arr2 情况下通过
	{
		if (*VarArr1 < *VarArr2)
		{
			(*TaskComplete) = 1;
		}
		return;
	}
}



