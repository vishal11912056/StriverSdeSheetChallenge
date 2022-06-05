void deleteNode(LinkedListNode<int> * node) 
{
	node->data= node->next->data;
	node->next= node->next->next;
    // Write your code here.
}
