LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    LinkedListNode<int>* itr=head,*front=head;
	if(head==NULL)
	{
		return head;
	}
	while(itr)
	{
		front=itr->next;
		LinkedListNode<int>* copy = new LinkedListNode<int>(itr->data);
		itr->next=copy;
		copy->next=front;
		itr=front;
	}
	itr=head;
	while(itr)
	{
		itr->next->random=itr->random ? itr->random->next : NULL;
		itr=itr->next->next;
	}
	itr=head;
	LinkedListNode<int>* pseudo = new LinkedListNode<int>(-1);
	LinkedListNode<int>* copy=pseudo;
	while(itr)
	{
		front=itr->next->next;
		copy->next=itr->next;
		itr->next=front;
		copy=copy->next;
		itr=front;
	}
	return pseudo->next;
		
}
