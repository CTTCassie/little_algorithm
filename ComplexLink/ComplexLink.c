#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int DataType;

typedef struct ComplexLinkNode
{
	DataType _data;
	struct ComplexLinkNode *_next;
	struct ComplexLinkNode *_randow;
}ComplexLinkNode,*pComplexLinkNode;

pComplexLinkNode CreatComplexNode(DataType data)
{
	pComplexLinkNode NewNode=(pComplexLinkNode)malloc(sizeof(ComplexLinkNode));
	if(NULL == NewNode)
	{
		perror("malloc");
		exit(EXIT_FAILURE); 
	}
	NewNode->_data=data;
	NewNode->_next=NULL;
	NewNode->_randow=NULL;
	return NewNode;
}

void CreatComplexLink(pComplexLinkNode *head)
{
	pComplexLinkNode n1=CreatComplexNode(1);
	pComplexLinkNode n2=CreatComplexNode(2);
	pComplexLinkNode n3=CreatComplexNode(3);
	pComplexLinkNode n4=CreatComplexNode(4);
	pComplexLinkNode n5=CreatComplexNode(5);
	n1->_next=n2;
	n2->_next=n3;
	n3->_next=n4;
	n4->_next=n5;

	n1->_randow=n3;
	n2->_randow=n5;
	n3->_randow=n2;
	n4->_randow=n2;
	n5->_randow=n4;
	*head=n1;
}

pComplexLinkNode CloneComplexLink(pComplexLinkNode head)
{
	//复制原始结点的任意结点并连接到该结点后面
	pComplexLinkNode cur=head;
	pComplexLinkNode tmp=NULL;
	pComplexLinkNode newhead=NULL;
	while(cur)
	{
		tmp=CreatComplexNode(cur->_data);
		tmp->_next=cur->_next;
		cur->_next=tmp;
		cur=tmp->_next;
	}
	//复制原始复杂链表的随机指针域
	cur=head;
	while(cur)
	{
		tmp=cur->_next;
		if(cur->_randow)
		{
			tmp->_randow=cur->_randow->_next;
		}
		cur=tmp->_next;
	}
	//分离
	cur=head;
	if(cur)
	{
		tmp=newhead=cur->_next;
		cur->_next=tmp->_next;
		cur=cur->_next;
	}
	while(cur)
	{
		tmp->_next=cur->_next;
		tmp=cur->_next;
		cur->_next=tmp->_next;
		cur=cur->_next;
	}
	return newhead;
}

void DisplayLink(pComplexLinkNode head)
{
	pComplexLinkNode cur=head;
	while(cur)
	{
		printf("%d->%d \n",cur->_data,cur->_randow->_data);
		cur=cur->_next;
	}
	printf("\n");
}

void DestroyLink(pComplexLinkNode head)
{
	pComplexLinkNode cur=head;
	pComplexLinkNode del=NULL;
	assert(head);
	while(cur)
	{
		del=cur;
		cur=cur->_next;
		free(del);
		del=NULL;
	}
}

void testComplexLink()
{
	pComplexLinkNode head;
	pComplexLinkNode newhead;
	CreatComplexLink(&head);
	DisplayLink(head);
	newhead=CloneComplexLink(head);
	DisplayLink(newhead);
}

int main()
{
	testComplexLink();
	system("pause");
	return 0;
}