LinkedListNode<int>* removeKthNode(LinkedListNode<int> *head, int n)
{
		LinkedListNode<int>* slow=head,*fast=head;
	   if(head==NULL || n==0)
	   {
		   return head;
	   }
        for(int i=0;i<n;i++)
        {
            fast=fast->next;
        }
        if(fast==NULL)
        {
            return head->next;
        }
        while(fast->next!=NULL)
        {
            
            fast=fast->next;
			slow=slow->next;
        }
        slow->next=slow->next->next;
        return head;
    // Write your code here.
}
