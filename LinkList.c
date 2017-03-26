#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef struct LinkNode
{
	int _data;
	struct LinkNode *_next;
}LinkNode;

LinkNode *CreateNode(int data)
{
	LinkNode * NewNode=(LinkNode *)malloc(sizeof(LinkNode));
	if(NewNode == NULL)
	{
		perror("malloc");
		exit(1);
	}
	NewNode->_data=data;
	NewNode->_next=NULL;
	return NewNode;
}

void CreateLink(LinkNode * head,int data)
{
	LinkNode *cur=head->_next;
	LinkNode *NewNode=NULL;
	assert(head);
	NewNode=CreateNode(data);
	if(head->_next == NULL)    //空链表
	{
		head->_next=NewNode;
	}
	else
	{
		while(cur->_next)
		{
			cur=cur->_next;
		}
		cur->_next=NewNode;
	}
}

void InitLink(LinkNode *head)
{
	assert(head);
	head->_next=NULL;
}

//删除无头单链表的非尾结点
void Del_NotTail(LinkNode *pos)
{
	LinkNode *del=pos->_next;
	assert(pos && pos->_next);
	pos->_data=del->_data;
	pos->_next=del->_next;
	free(del);
	del=NULL;
}

//删除倒数第k个结点
void Del_KNode(LinkNode *head,int k)
{
	LinkNode *prev=head->_next;
	LinkNode *last=head->_next;
	LinkNode *del=NULL;
	assert(head);
	if(head->_next == NULL)   //空链表
		return ;
	else
	{
		while (prev)
		{
			k--;
			if(k < 0)
			{
				last=last->_next;
			}
			prev=prev->_next;
		}
	}
	if (last)
	{
		//del=last->_next;
		//last->_data=del->_data;
		//last->_next=del->_next;
		//free(del);
		//del=NULL;
		Del_NotTail(last);
	}
}

void DisplayLink(LinkNode *head)
{
	LinkNode *cur=head->_next;
	assert(head);
	while (cur)
	{
		printf("%d ",cur->_data);
		cur=cur->_next;
	}
	printf("\n");
}

LinkNode *FindNode(LinkNode *head,int data)
{
	LinkNode *cur=head->_next;
	assert(head);
	while (cur)
	{
		if(cur->_data == data)
			return cur;
		cur=cur->_next;
	}
	return NULL;
}

void DestroyLink(LinkNode *head)
{
	LinkNode *cur=head->_next;
	LinkNode *del=NULL;
	assert(head);
	while (cur)
	{
		del=cur;
		cur=cur->_next;
		free(del);
		del=NULL;
	}
}

int main()
{
	LinkNode head;
	InitLink(&head);
	CreateLink(&head,1);
	CreateLink(&head,2);
	CreateLink(&head,3);
	CreateLink(&head,4);
	CreateLink(&head,5);
	DisplayLink(&head);
	//Del_NotTail(FindNode(&head,4));
	//DisplayLink(&head);
	Del_KNode(&head,2);
	DisplayLink(&head);
	DestroyLink(&head);
	system("pause");
	return 0;
}