#ifndef __SINGLYLINKEDLIST_H__
#define __SINGLYLINKEDLIST_H__

#include<stdio.h>		////����printf��scanf�Ⱥ���
#include<stdlib.h>		//������̬�����ڴ�Ⱥ�������
#include<time.h>        //�����������


					//�������һ������а����������������ݺ�ָ����һ����ָ��
typedef struct Node		//����������
{
	int Value;      //����
	struct Node * Next;        //ָ����һ����ָ��
}NODE, *PNODE;     //NODE�ȼ���struct Node, PNODE�ȼ���struct Node *


					//��������
PNODE createLinkList(void);     //���������Ӻ���
void printLinkList(PNODE pHead);     //��ӡ�����Ӻ���
void insertNode(PNODE pHead);		//�������Ӻ���
void deleteNode(PNODE pHead);		//ɾ������Ӻ���
void modifyNode(PNODE pHead);		//�޸Ľ�㺯��
void menu(PNODE pHead);		//����ѡ��Ŀ¼�Ӻ���
int getLength(PNODE pHead);		//��ȡ�������Ӻ���

#endif