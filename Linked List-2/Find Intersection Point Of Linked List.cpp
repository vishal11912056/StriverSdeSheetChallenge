int findIntersection(Node *headA, Node *headB)
{
// 	Node* d1=head1;
// 	Node* d2=head2;
// 	while(d1!=d2)
// 	{
// 		d1= d1==NULL?head2:d1->next;
// 		d2= d2==NULL?head1:d2->next;
// 	}
// 	return d1->data;
    //Write your code here
	int diff=Getdiff(headA,headB);
        if(diff<0)
        {
            while(diff!=0)
            {
                diff++;
               headB=headB->next;
            }
        }
        else
        {
             while(diff!=0)
            {
                 diff--;
                headA=headA->next;
            }
        }
        while(headA!=NULL)
        {
            if(headA==headB)
            {
                return headA->data;
            }
            headA=headA->next;
            headB=headB->next;
        }
        return -1;
}
