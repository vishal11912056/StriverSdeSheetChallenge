Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
	Node<int>* a=first,*b=second;
	if(!a)
	{
		return b;
	}
	if(!b)
	{
		return a;
	}
	if(a->data>b->data)
	{
		swap(a,b);
	}
	Node<int>* res=a;
	while(a && b)
	{
		Node<int>* tmp=NULL;
		while(a && a->data<=b->data)
		{
			tmp=a;
			a=a->next;
		}
		tmp->next=b;
		swap(a,b);
	}
	return res;
    // Write your code here.
}
