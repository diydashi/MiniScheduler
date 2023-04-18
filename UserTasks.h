#ifndef _USERTASKS_H_
#define _USERTASKS_H_

//通用任务
void Task_Null(void* Parameters);		//空任务

void Task_Delay_ms(void* Parameters);	//延时

void Task_Print(void* Parameters);		//输出

void Task_ConstVarCmp(void* Parameters);//判断满足关系

void Task_VarVarCmp(void* Parameters);	//判断满足关系

#endif
