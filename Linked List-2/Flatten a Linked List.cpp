Node* merge(Node* a,Node* b)
{
	Node* tmp=new Node(-1);
	Node* res=tmp;
	while(a && b)
	{
		if(a->data<b->data)
		{
			tmp->child=a;
			tmp=tmp->child;
			a=a->child;
		}
		else
		{
			tmp->child=b;
			tmp=tmp->child;
			b=b->child;
		}
	}
	if(a)
	{
		tmp->child=a;
	}
	else
	{
		tmp->child=b;
	}
	return res->child;
}
Node* flattenLinkedList(Node* head) 
{
	if(!head || !head->next)
	{
		return head;
	}
	head->next = flattenLinkedList(head->next);
	
	return merge(head,head->next);
}
