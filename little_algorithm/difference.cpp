namespace Link
{
	struct node
	{
		int elem;
		node* next;
		node(const int& d = 0)
			:elem(d)
			, next(NULL)
		{}
	};
	void difference(node** LA, node* LB)
	{
		node *p1 = *LA; 
		node *prev = NULL;
		while (p1)
		{
			node *p2 = LB;
			//在p2中查找到与p1相同的数据
			while (p2 && p2->elem != p1->elem)
			{
				p2 = p2->next;
			}
			if (p2)   //p2不为NULL
			{
				if (!prev)
					*LA = p1->next;
				else
					prev->next = p1->next;
				node *tmp = p1;
				p1 = p1->next;
				delete tmp;   
			}
			else    //p2为空
			{
				prev = p1;
				p1 = p1->next;
			}
		}
	}
	void Display(node *pHead)
	{
		if (pHead == NULL)
			return;
		node *cur = pHead;
		while (cur)
		{
			cout << cur->elem << " ";
			cur = cur->next;
		}
		cout << endl;
	}
	void TestLink()
	{
		node *n1 = new node(5);
		node *n2 = new node(10);
		node *n3 = new node(20);
		node *n4 = new node(15);
		node *n5 = new node(25);
		node *n6 = new node(30);
		n1->next = n2;
		n2->next = n3;
		n3->next = n4;
		n4->next = n5;
		n5->next = n6;
		node *n7 = new node(5);
		node *n8 = new node(15);
		node *n9 = new node(35);
		node *n10 = new node(25);
		n7->next = n8;
		n8->next = n9;
		n9->next = n10;
		Display(n1);
		Display(n7);
		difference(&n1,n7);
		Display(n1);
	}
}