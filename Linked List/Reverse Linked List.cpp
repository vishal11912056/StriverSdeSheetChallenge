LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
	LinkedListNode<int> *curr=head,*prev=NULL,*nxt=NULL;
	while(curr)
	{
		nxt=curr->next;
	    curr->next=prev;
		prev=curr;
		curr=nxt;
	}
	head=prev;
	return head;
    // Write your code here
}
