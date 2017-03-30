#include"SinglyLinkedList.h"

int main()
{
	PNODE pHead = NULL;     //PNODE等价于struct Node *

	printf(" * * * * * * * * * * * * * * * * * * * * 单链表的实现 * * * * * * * * * * * * * * * * * * * * \n\n");

	pHead = createLinkList();       //创建一个非循环单链表，并将该链表的头结点地址赋给pHead
	printLinkList(pHead);       //调用打印链表的函数
	while (1)		//用while循环，条件为(1)使功能选择循环进行
	{
		menu(pHead);
	}

	return 0;
}