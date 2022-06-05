LinkedListNode<int>* reverse(LinkedListNode<int>* curr)
{
	LinkedListNode<int> *nxt=NULL,*prev=NULL;
	while(curr)
	{
		nxt=curr->next;
		curr->next=prev;
		prev=curr;
		curr=nxt;
	}
	return prev;
}
bool isPalindrome(LinkedListNode<int> *head) 
{
	if(head==NULL){
        return true;
    }
	LinkedListNode<int> *slow=head,*fast=head;
	while(fast->next!=NULL && fast->next->next!=NULL)
	{
		slow=slow->next;
		fast=fast->next->next;
	}
	slow->next=reverse(slow->next);
	slow=slow->next;
	while(slow!=NULL)
	{
		if(slow->data!=head->data)
		{
			return false;
		}
		head=head->next;
		slow=slow->next;
	}
	return true;
    // Write your code here.

}
