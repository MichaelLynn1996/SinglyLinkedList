#include"SinglyLinkedList.h"

int main()
{
	PNODE pHead = NULL;     //PNODE�ȼ���struct Node *

	printf(" * * * * * * * * * * * * * * * * * * * * �������ʵ�� * * * * * * * * * * * * * * * * * * * * \n\n");

	pHead = createLinkList();       //����һ����ѭ�������������������ͷ����ַ����pHead
	printLinkList(pHead);       //���ô�ӡ����ĺ���
	while (1)		//��whileѭ��������Ϊ(1)ʹ����ѡ��ѭ������
	{
		menu(pHead);
	}

	return 0;
}