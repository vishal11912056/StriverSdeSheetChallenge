 Node *reverse (Node *head, int n,int i,int b[])
    { 
	    
        // Complete this method
        Node *curr=head, *nxt=NULL, *prev=NULL ;
	   if(i<n)
	   {
			for(int j=0;j<b[i] && curr;j++)
			{
				nxt= curr->next;
				curr->next=prev;
				prev=curr;
				curr=nxt;
			}
	   }
        if(nxt)
        {
           head->next= reverse(nxt,n,i+1,b);
        }
        
        return prev;
    }
Node *getListAfterReverseOperation(Node *head, int n, int b[]){
    
  return  reverse(head,n,0,b);
}
