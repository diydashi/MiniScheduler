#ifndef _MINISCHEDULER_H_
#define _MINISCHEDULER_H_

typedef struct
{
	void* HeadThread;	//首线程地址
}ThreadListTypeDef;		//线程序列入口

ThreadListTypeDef HighPriorityThreadList;					//高优先线程队列
ThreadListTypeDef MidPriorityThreadList;					//中优先线程队列
ThreadListTypeDef LowPriorityThreadList;					//低优先线程队列

typedef struct
{
	int ThreadRunning;	//线程运行状态
	void* TaskNode;		//当前任务节点首地址
	void* LastThread;	//上一个线程首地址
	void* NextThread;	//下一个线程首地址
}ThreadTypeDef;			//线程结点定义


/*---------线程调度器分别置于抢占优先级不同的定时器中断中-------------------------*/
void ThreadScheduler(ThreadListTypeDef*	ThreadList);							//线程调度器

void ThreadHandle(ThreadListTypeDef* ThreadList, ThreadTypeDef* Thread);			//线程运行

void ThreadWriteOff(ThreadListTypeDef* ThreadList, ThreadTypeDef* ThreadNode);	//注销线程

ThreadTypeDef* CreatThreadNode(ThreadListTypeDef* ThreadList);					//创建线程结点

void* CreatTaskNode(void* TaskNode, unsigned int NodeSize);						//创建任务结点
//	Task 任务函数
//	NodeSize	结点字节大小	

typedef struct
{
	int TaskComplete;	//任务是否完成
	void (*Task)(void*);//任务函数
	void* LastNode;		//上一个结点地址
	void* NextNode;		//下一个结点地址
	int JumpDistance;	//任务完成后跳转的节点数 负向上跳转 0跳到自身（不跳转） 正向下跳转 默认1跳到下一个节点，非默认值只有在JumpTimesSet非0时有效，可被任务改写以实现循环
	int JumpCount;		//已跳转次数计数 以实现循环有限次
	int JumpTimesSet;	//目标跳转次数，≥0且与JumpCount相等时 JumpDistance置1，-1死循环
	//newmember2
	//newmember3
}TaskNodeTypeDef_Mini;

typedef struct
{
	int TaskComplete;	//任务是否完成
	void (*Task)(void*);//任务函数
	void* LastNode;		//上一个结点地址
	void* NextNode;		//下一个结点地址
	int JumpDistance;	//任务完成后跳转的节点数 负向上跳转 0跳到自身（不跳转） 正向下跳转 默认1跳到下一个节点，非默认值只有在JumpTimesSet非0时有效，可被任务改写以实现循环
	int JumpCount;		//已跳转次数计数 以实现循环有限次
	int JumpTimesSet;	//目标跳转次数，≥0且与JumpCount相等时 JumpDistance置1，-1死循环
	//newmember2
	//newmember3
/*------任务参数 int型--------------*/
	int INT_Parter1;
}TaskNodeTypeDef_1I;

typedef struct
{
	int TaskComplete;	//任务是否完成
	void (*Task)(void*);//任务函数
	void* LastNode;		//上一个结点地址
	void* NextNode;		//下一个结点地址
	int JumpDistance;	//任务完成后跳转的节点数 负向上跳转 0跳到自身（不跳转） 正向下跳转 默认1跳到下一个节点，可被任务改写以实现循环
	int JumpCount;		//跳转次数 以实现循环有限次
	int JumpTimesSet;
	//newmember2
	//newmember3
/*------任务参数 int型--------------*/
	int INT_Parter1;
	int INT_Parter2;
}TaskNodeTypeDef_2I;

typedef struct
{
	int TaskComplete;	//任务是否完成
	void (*Task)(void*);//任务函数
	void* LastNode;		//上一个结点地址
	void* NextNode;		//下一个结点地址
	int JumpDistance;	//任务完成后跳转的节点数 负向上跳转 0跳到自身（不跳转） 正向下跳转 默认1跳到下一个节点，可被任务改写以实现循环
	int JumpCount;		//跳转次数 以实现循环有限次
	int JumpTimesSet;
	//newmember2
	//newmember3
/*------任务参数 int型--------------*/
	int INT_Parter1;
	int INT_Parter2;
	int INT_Parter3;
}TaskNodeTypeDef_3I;

typedef struct
{
	int TaskComplete;	//任务是否完成
	void (*Task)(void*);//任务函数
	void* LastNode;		//上一个结点地址
	void* NextNode;		//下一个结点地址
	int JumpDistance;	//任务完成后跳转的节点数 负向上跳转 0跳到自身（不跳转） 正向下跳转 默认1跳到下一个节点，可被任务改写以实现循环
	int JumpCount;		//跳转次数 以实现循环有限次
	int JumpTimesSet;
	//newmember2
	//newmember3
/*------任务参数 int型--------------*/
	int INT_Parter1;
	int INT_Parter2;
	int INT_Parter3;
	int INT_Parter4;
	int INT_Parter5;
}TaskNodeTypeDef_5I;

typedef struct
{
	int TaskComplete;	//任务是否完成
	void (*Task)(void*);//任务函数
	void* LastNode;		//上一个结点地址
	void* NextNode;		//下一个结点地址
	int JumpDistance;	//任务完成后跳转的节点数 负向上跳转 0跳到自身（不跳转） 正向下跳转 默认1跳到下一个节点，可被任务改写以实现循环
	int JumpCount;		//跳转次数 以实现循环有限次
	int JumpTimesSet;
	//newmember2
	//newmember3
/*------任务参数 int型--------------*/
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
	int TaskComplete;	//任务是否完成
	void (*Task)(void*);//任务函数
	void* LastNode;		//上一个结点地址
	void* NextNode;		//下一个结点地址
	int JumpDistance;	//任务完成后跳转的节点数 负向上跳转 0跳到自身（不跳转） 正向下跳转 默认1跳到下一个节点，可被任务改写以实现循环
	int JumpCount;		//跳转次数 以实现循环有限次
	int JumpTimesSet;
	//newmember2
	//newmember3
/*------任务参数 指针型--------------*/
	void* ARR_Parter1;
}TaskNodeTypeDef_1A;

typedef struct
{
	int TaskComplete;	//任务是否完成
	void (*Task)(void*);//任务函数
	void* LastNode;		//上一个结点地址
	void* NextNode;		//下一个结点地址
	int JumpDistance;	//任务完成后跳转的节点数 负向上跳转 0跳到自身（不跳转） 正向下跳转 默认1跳到下一个节点，可被任务改写以实现循环
	int JumpCount;		//跳转次数 以实现循环有限次
	int JumpTimesSet;
	//newmember2
	//newmember3
/*------任务参数 指针型--------------*/
	void* ARR_Parter1;
	void* ARR_Parter2;
}TaskNodeTypeDef_2A;

typedef struct
{
	int TaskComplete;	//任务是否完成
	void (*Task)(void*);//任务函数
	void* LastNode;		//上一个结点地址
	void* NextNode;		//下一个结点地址
	int JumpDistance;	//任务完成后跳转的节点数 负向上跳转 0跳到自身（不跳转） 正向下跳转 默认1跳到下一个节点，可被任务改写以实现循环
	int JumpCount;		//跳转次数 以实现循环有限次
	int JumpTimesSet;
	//newmember2
	//newmember3
/*------任务参数 指针型--------------*/
	void* ARR_Parter1;
	void* ARR_Parter2;
	void* ARR_Parter3;
}TaskNodeTypeDef_3A;

typedef struct
{
	int TaskComplete;	//任务是否完成
	void (*Task)(void*);//任务函数
	void* LastNode;		//上一个结点地址
	void* NextNode;		//下一个结点地址
	int JumpDistance;	//任务完成后跳转的节点数 负向上跳转 0跳到自身（不跳转） 正向下跳转 默认1跳到下一个节点，可被任务改写以实现循环
	int JumpCount;		//跳转次数 以实现循环有限次
	int JumpTimesSet;
	//newmember2
	//newmember3
/*------任务参数 指针型--------------*/
	void* ARR_Parter1;
	void* ARR_Parter2;
	void* ARR_Parter3;
	void* ARR_Parter4;
	void* ARR_Parter5;
}TaskNodeTypeDef_5A;

typedef struct
{
	int TaskComplete;	//任务是否完成
	void (*Task)(void*);//任务函数
	void* LastNode;		//上一个结点地址
	void* NextNode;		//下一个结点地址
	int JumpDistance;	//任务完成后跳转的节点数 负向上跳转 0跳到自身（不跳转） 正向下跳转 默认1跳到下一个节点，可被任务改写以实现循环
	int JumpCount;		//跳转次数 以实现循环有限次
	int JumpTimesSet;
	//newmember2
	//newmember3
/*------任务参数 指针型--------------*/
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
	int TaskComplete;	//任务是否完成
	void (*Task)(void*);//任务函数
	void* LastNode;		//上一个结点地址
	void* NextNode;		//下一个结点地址
	int JumpDistance;	//任务完成后跳转的节点数 负向上跳转 0跳到自身（不跳转） 正向下跳转 默认1跳到下一个节点，非默认值只有在JumpTimesSet非0时有效，可被任务改写以实现循环
	int JumpCount;		//已跳转次数计数 以实现循环有限次
	int JumpTimesSet;	//目标跳转次数，≥0且与JumpCount相等时 JumpDistance置1，-1死循环
	//newmember2
	//newmember3
/*------任务参数 int型--------------*/
	int INT_Parter1;
/*------任务参数 指针型--------------*/
	void* ARR_Parter1;
}TaskNodeTypeDef_1I_1A;

typedef struct
{
	int TaskComplete;	//任务是否完成
	void (*Task)(void*);//任务函数
	void* LastNode;		//上一个结点地址
	void* NextNode;		//下一个结点地址
	int JumpDistance;	//任务完成后跳转的节点数 负向上跳转 0跳到自身（不跳转） 正向下跳转 默认1跳到下一个节点，可被任务改写以实现循环
	int JumpCount;		//跳转次数 以实现循环有限次
	int JumpTimesSet;
	//newmember2
	//newmember3
/*------任务参数 int型--------------*/
	int INT_Parter1;
	int INT_Parter2;
/*------任务参数 指针型--------------*/
	void* ARR_Parter1;
	void* ARR_Parter2;
}TaskNodeTypeDef_2I_2A;

typedef struct
{
	int TaskComplete;	//任务是否完成
	void (*Task)(void*);//任务函数
	void* LastNode;		//上一个结点地址
	void* NextNode;		//下一个结点地址
	int JumpDistance;	//任务完成后跳转的节点数 负向上跳转 0跳到自身（不跳转） 正向下跳转 默认1跳到下一个节点，可被任务改写以实现循环
	int JumpCount;		//跳转次数 以实现循环有限次
	int JumpTimesSet;
	//newmember2
	//newmember3
/*------任务参数 int型--------------*/
	int INT_Parter1;
	int INT_Parter2;
	int INT_Parter3;
/*------任务参数 指针型--------------*/
	void* ARR_Parter1;
	void* ARR_Parter2;
	void* ARR_Parter3;
}TaskNodeTypeDef_3I_3A;

typedef struct
{
	int TaskComplete;	//任务是否完成
	void (*Task)(void*);//任务函数
	void* LastNode;		//上一个结点地址
	void* NextNode;		//下一个结点地址
	int JumpDistance;	//任务完成后跳转的节点数 负向上跳转 0跳到自身（不跳转） 正向下跳转 默认1跳到下一个节点，可被任务改写以实现循环
	int JumpCount;		//跳转次数 以实现循环有限次
	int JumpTimesSet;
	//newmember2
	//newmember3
/*------任务参数 int型--------------*/
	int INT_Parter1;
	int INT_Parter2;
	int INT_Parter3;
	int INT_Parter4;
	int INT_Parter5;
/*------任务参数 指针型--------------*/
	void* ARR_Parter1;
	void* ARR_Parter2;
	void* ARR_Parter3;
	void* ARR_Parter4;
	void* ARR_Parter5;
}TaskNodeTypeDef_5I_5A;

typedef struct
{
	int TaskComplete;	//任务是否完成
	void (*Task)(void*);//任务函数
	void* LastNode;		//上一个结点地址
	void* NextNode;		//下一个结点地址
	int JumpDistance;	//任务完成后跳转的节点数 负向上跳转 0跳到自身（不跳转） 正向下跳转 默认1跳到下一个节点，可被任务改写以实现循环
	int JumpCount;		//跳转次数 以实现循环有限次
	int JumpTimesSet;
	//newmember2
	//newmember3
/*------任务参数 int型--------------*/
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
/*------任务参数 指针型--------------*/
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
