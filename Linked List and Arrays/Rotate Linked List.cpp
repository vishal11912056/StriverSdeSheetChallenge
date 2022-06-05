Node *rotate(Node *head, int k) 
{
	if(!head)
	{
		return head;
	}
	Node* tmp=head;
	int cnt=1;
	while(tmp->next)
	{
		cnt++;
		tmp=tmp->next;
	}
	tmp->next=head;
	if(cnt<k)
	{
		k%=cnt;
	}
	for(int i=0;i<(cnt-k);i++)
	{
		tmp=tmp->next;
	}
	head=tmp->next;
	tmp->next=NULL;
	return head;
     // Write your code here.
}
