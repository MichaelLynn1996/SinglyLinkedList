#include"SinglyLinkedList.h"

PNODE createLinkList(void)
{
	int i;
	int len;        //有效结点的长度
	int value;     //用来存放用户输入的结点的值

	PNODE pHead = (PNODE)malloc(sizeof(NODE));		//创建了一个不存放有效数据的头结点,并为其动态分配内存
	if (NULL == pHead)
	{
		printf("内存分配失败，程序退出！\n");
		exit(-1);
	}
	PNODE pTail = pHead;        //pTail始终指向尾结点
	pTail->Next = NULL;     //清空指针域
	printf("请输入需要创建链表结点的个数：len = ");
	scanf_s("%d", &len);
	while (len<1)		//确保输入的值有效
	{
		printf("Enter error\n");
		printf("请输入需要创建链表结点的个数：len = ");
		scanf_s("%d", &len);
	}

	srand((unsigned)time(NULL));        //随机种子

	for (i = 0; i<len; i++)
	{
		value = rand() % 100;
		PNODE pNew = (PNODE)malloc(sizeof(NODE));
		if (NULL == pHead)
		{
			printf("内存分配失败，程序退出！\n");
			exit(-1);		//exit(-1)代表非正常退出
		}
						//一个结点只知道下一个结点的地址。最后的结点，指针值为NULL
		pNew->Value = value;        //向新结点中放入值
		pTail->Next = pNew;     //将尾结点指向新结点
		pNew->Next = NULL;      //将新结点的指针域清空
		pTail = pNew;       //将新结点赋给pTail,使pTail始终指向为尾结点
	}
	return pHead;		//返回头结点pHead
}

void printLinkList(PNODE pHead)
{
	PNODE p = pHead->Next;		//指向首结点
	while (NULL != p)		//逐个读取并打印结点的值
	{
		printf("%d\t", p->Value);
		p = p->Next;		//p指向下一结点
	}
	printf("\n");
	return;
}

void insertNode(PNODE pHead)
{
	int j = 0;
	int value,pos;
	int len = getLength(pHead);		//获取链表长度
	PNODE p, s;
	p = pHead;

	printf("\n请输入需要将新结点插入的位置：pos = ");
	scanf_s("%d", &pos);
	while (pos<1 || pos>len + 1)		//确保输入的值有效
	{
		printf("Enter error\n");
		printf("请输入需要将新结点插入的位置：pos = ");
		scanf_s("%d", &pos);
	}
	printf("\n插入新结点的值为：value = ");
	scanf_s("%d", &value);

	while (p && j < pos - 1)		//确定插入结点的位置
	{
		p = p->Next;		//p指向下一结点
		j++;		//每读取一个结点j自加1
	}
	if (!p || j > pos - 1)
	{
		exit(-1);		//exit(-1)代表非正常退出
	}
	s = (PNODE)malloc(sizeof(NODE));		//为每个结点动态分配内存
	s->Value = value;
	s->Next = p->Next;
	p->Next = s;
	printf("\n插入新结点后的链表为：\n");
	printLinkList(pHead);
}

void deleteNode(PNODE pHead)
{
	int i = 0;
	int pos;
	int len = getLength(pHead);		//获取链表长度
	PNODE p = pHead;

	printf("\n请输入需要删除的结点的位置 pos = ");
	scanf_s("%d", &pos);
	while (pos<1 || pos>len)		//确保输入的值有效
	{
		printf("Enter error\n");
		printf("请输入需要删除的结点的位置：pos = ");
		scanf_s("%d", &pos);
	}

	//判断p是否为空并且使p最终指向pos结点
	while (NULL != p->Next && i<pos - 1)
	{
		p = p->Next;
		i++;
	}

	printf("\n删除的结点的值是：%d\n", p->Next->Value);

	//删除p后面的结点
	PNODE q = p->Next;
	p->Next = p->Next->Next;
	free(q);
	q = NULL;
	printf("\n删除结点后的链表为：\n");
	printLinkList(pHead);
}

void modifyNode(PNODE pHead)
{
	int i = 0;
	int pos, value;
	int len = getLength(pHead);		//获取链表长度
	PNODE p = pHead;

	printf("\n请输入需要修改的结点的位置 pos = ");
	scanf_s("%d", &pos);
	while (pos<1 || pos>len)		//确保输入的值有效
	{
		printf("Enter error\n");
		printf("请输入需要修改的结点的位置：pos = ");
		scanf_s("%d", &pos);
	}
	printf("\n请输入需要修改的结点的值 value = ");
	scanf_s("%d", &value);

	//判断p是否为空并且使p最终指向pos结点
	while (NULL != p->Next && i<pos - 1)
	{
		p = p->Next;
		i++;
	}

	p->Next->Value = value;

	printf("\n修改结点后的链表为：\n");
	printLinkList(pHead);
	printf("\n");
}

void menu(PNODE pHead)
{
	int i;
	printf("\n1.新插入1个结点到指定的位置。\t2.删除1个指定的位置结点。\t3.修改1个指定的位置结点的数据值。\t4.退出系统\n");
	printf("\n请输入相应的序号选择功能：");
	scanf_s("%d",&i);
	switch (i)
	{
	case 1:insertNode(pHead); break;
	case 2:deleteNode(pHead); break;
	case 3: modifyNode(pHead); break;
	case 4: printf("退出系统成功\n\n"); exit(0); break;
	default:printf("Enter error\n");
		break;
	}
}

int getLength(PNODE pHead)
{
	PNODE p = pHead->Next;		//指向首结点
	int len = 0;     //记录链表长度的变量
	while (NULL != p)
	{
		len++;
		p = p->Next;		//p指向下一结点
	}
	return len;
}