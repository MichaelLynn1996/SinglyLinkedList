#include"SinglyLinkedList.h"

PNODE createLinkList(void)
{
	int i;
	int len;        //��Ч���ĳ���
	int value;     //��������û�����Ľ���ֵ

	PNODE pHead = (PNODE)malloc(sizeof(NODE));		//������һ���������Ч���ݵ�ͷ���,��Ϊ�䶯̬�����ڴ�
	if (NULL == pHead)
	{
		printf("�ڴ����ʧ�ܣ������˳���\n");
		exit(-1);
	}
	PNODE pTail = pHead;        //pTailʼ��ָ��β���
	pTail->Next = NULL;     //���ָ����
	printf("��������Ҫ����������ĸ�����len = ");
	scanf_s("%d", &len);
	while (len<1)		//ȷ�������ֵ��Ч
	{
		printf("Enter error\n");
		printf("��������Ҫ����������ĸ�����len = ");
		scanf_s("%d", &len);
	}

	srand((unsigned)time(NULL));        //�������

	for (i = 0; i<len; i++)
	{
		value = rand() % 100;
		PNODE pNew = (PNODE)malloc(sizeof(NODE));
		if (NULL == pHead)
		{
			printf("�ڴ����ʧ�ܣ������˳���\n");
			exit(-1);		//exit(-1)����������˳�
		}
						//һ�����ֻ֪����һ�����ĵ�ַ�����Ľ�㣬ָ��ֵΪNULL
		pNew->Value = value;        //���½���з���ֵ
		pTail->Next = pNew;     //��β���ָ���½��
		pNew->Next = NULL;      //���½���ָ�������
		pTail = pNew;       //���½�㸳��pTail,ʹpTailʼ��ָ��Ϊβ���
	}
	return pHead;		//����ͷ���pHead
}

void printLinkList(PNODE pHead)
{
	PNODE p = pHead->Next;		//ָ���׽��
	while (NULL != p)		//�����ȡ����ӡ����ֵ
	{
		printf("%d\t", p->Value);
		p = p->Next;		//pָ����һ���
	}
	printf("\n");
	return;
}

void insertNode(PNODE pHead)
{
	int j = 0;
	int value,pos;
	int len = getLength(pHead);		//��ȡ������
	PNODE p, s;
	p = pHead;

	printf("\n��������Ҫ���½������λ�ã�pos = ");
	scanf_s("%d", &pos);
	while (pos<1 || pos>len + 1)		//ȷ�������ֵ��Ч
	{
		printf("Enter error\n");
		printf("��������Ҫ���½������λ�ã�pos = ");
		scanf_s("%d", &pos);
	}
	printf("\n�����½���ֵΪ��value = ");
	scanf_s("%d", &value);

	while (p && j < pos - 1)		//ȷ���������λ��
	{
		p = p->Next;		//pָ����һ���
		j++;		//ÿ��ȡһ�����j�Լ�1
	}
	if (!p || j > pos - 1)
	{
		exit(-1);		//exit(-1)����������˳�
	}
	s = (PNODE)malloc(sizeof(NODE));		//Ϊÿ����㶯̬�����ڴ�
	s->Value = value;
	s->Next = p->Next;
	p->Next = s;
	printf("\n�����½��������Ϊ��\n");
	printLinkList(pHead);
}

void deleteNode(PNODE pHead)
{
	int i = 0;
	int pos;
	int len = getLength(pHead);		//��ȡ������
	PNODE p = pHead;

	printf("\n��������Ҫɾ���Ľ���λ�� pos = ");
	scanf_s("%d", &pos);
	while (pos<1 || pos>len)		//ȷ�������ֵ��Ч
	{
		printf("Enter error\n");
		printf("��������Ҫɾ���Ľ���λ�ã�pos = ");
		scanf_s("%d", &pos);
	}

	//�ж�p�Ƿ�Ϊ�ղ���ʹp����ָ��pos���
	while (NULL != p->Next && i<pos - 1)
	{
		p = p->Next;
		i++;
	}

	printf("\nɾ���Ľ���ֵ�ǣ�%d\n", p->Next->Value);

	//ɾ��p����Ľ��
	PNODE q = p->Next;
	p->Next = p->Next->Next;
	free(q);
	q = NULL;
	printf("\nɾ�����������Ϊ��\n");
	printLinkList(pHead);
}

void modifyNode(PNODE pHead)
{
	int i = 0;
	int pos, value;
	int len = getLength(pHead);		//��ȡ������
	PNODE p = pHead;

	printf("\n��������Ҫ�޸ĵĽ���λ�� pos = ");
	scanf_s("%d", &pos);
	while (pos<1 || pos>len)		//ȷ�������ֵ��Ч
	{
		printf("Enter error\n");
		printf("��������Ҫ�޸ĵĽ���λ�ã�pos = ");
		scanf_s("%d", &pos);
	}
	printf("\n��������Ҫ�޸ĵĽ���ֵ value = ");
	scanf_s("%d", &value);

	//�ж�p�Ƿ�Ϊ�ղ���ʹp����ָ��pos���
	while (NULL != p->Next && i<pos - 1)
	{
		p = p->Next;
		i++;
	}

	p->Next->Value = value;

	printf("\n�޸Ľ��������Ϊ��\n");
	printLinkList(pHead);
	printf("\n");
}

void menu(PNODE pHead)
{
	int i;
	printf("\n1.�²���1����㵽ָ����λ�á�\t2.ɾ��1��ָ����λ�ý�㡣\t3.�޸�1��ָ����λ�ý�������ֵ��\t4.�˳�ϵͳ\n");
	printf("\n��������Ӧ�����ѡ���ܣ�");
	scanf_s("%d",&i);
	switch (i)
	{
	case 1:insertNode(pHead); break;
	case 2:deleteNode(pHead); break;
	case 3: modifyNode(pHead); break;
	case 4: printf("�˳�ϵͳ�ɹ�\n\n"); exit(0); break;
	default:printf("Enter error\n");
		break;
	}
}

int getLength(PNODE pHead)
{
	PNODE p = pHead->Next;		//ָ���׽��
	int len = 0;     //��¼�����ȵı���
	while (NULL != p)
	{
		len++;
		p = p->Next;		//pָ����һ���
	}
	return len;
}