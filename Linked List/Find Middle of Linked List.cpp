Node *findMiddle(Node *head) 
{
	if(head==NULL || head->next==NULL)
	{
		return head;
	}
	if(head->next->next==NULL)
	{
		return head->next;
	}
	Node* slw=head,*fst=head;
	while(fst!=NULL && fst->next!=NULL)
	{
		slw=slw->next;
		fst=fst->next->next;
	}
	return slw;
    // Write your code here
}
