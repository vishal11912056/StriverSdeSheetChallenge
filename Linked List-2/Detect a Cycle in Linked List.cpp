Node *firstNode(Node *head)
{
	bool flg=false; 
	Node* slow=head,*fast=head;
	while(fast && fast->next)
	{
		slow=slow->next;
		fast=fast->next->next;
		if(slow==fast)
		{
			flg=true;
			break;
		}
	}
	if(flg)
	{
		fast=head;
		while(slow!=NULL)
		{
			if(slow==fast)
			{
				return slow;
			}
			slow=slow->next;
			fast=fast->next;
		}
	}
	return NULL;
	
}
