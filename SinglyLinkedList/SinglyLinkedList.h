#ifndef __SINGLYLINKEDLIST_H__
#define __SINGLYLINKEDLIST_H__

#include<stdio.h>		////包括printf、scanf等函数
#include<stdlib.h>		//包括动态分配内存等函数定义
#include<time.h>        //包括随机函数


					//单链表的一个结点中包含两个变量：数据和指向下一结点的指针
typedef struct Node		//定义链表结点
{
	int Value;      //数据
	struct Node * Next;        //指向下一结点的指针
}NODE, *PNODE;     //NODE等价于struct Node, PNODE等价于struct Node *


					//函数声明
PNODE createLinkList(void);     //创建链表子函数
void printLinkList(PNODE pHead);     //打印链表子函数
void insertNode(PNODE pHead);		//插入结点子函数
void deleteNode(PNODE pHead);		//删除结点子函数
void modifyNode(PNODE pHead);		//修改结点函数
void menu(PNODE pHead);		//功能选择目录子函数
int getLength(PNODE pHead);		//获取链表长度子函数

#endif