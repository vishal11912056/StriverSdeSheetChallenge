Node *addTwoNumbers(Node *l1, Node *l2)
{
	if(!l1)
	{
		return l2;
	}
	if(!l2)
	{
		return l1;
	}
	Node* dummy=new Node(-1);
	Node* tmp=dummy;
	int carry=0;
	while(l1!=NULL || l2!=NULL)
	{
		int sum=0;
		if(l1)
		{
			sum+=l1->data;
			l1=l1->next;
		}
		if(l2)
		{
			sum+=l2->data;
			l2=l2->next;
		}
		sum+=carry;
		carry=sum/10;
		Node* node= new Node(sum%10);
		tmp->next=node;
		tmp=tmp->next;
	}
	if(carry)
	{
		Node* node= new Node(carry);
		tmp->next=node;
	}
	return dummy->next;
    // Write your code here.
}
