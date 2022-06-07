void sortedinsert(stack<int> &stack , int num)
{
    if(stack.empty()||(!stack.empty()&&stack.top()<num))
    {
        stack.push(num);
        return;
    }
    int top1 = stack.top();
    stack.pop();
    
    sortedinsert(stack , num); 
    stack.push(top1);
}
void sortStack(stack<int> &stack)
{    
    
    if(stack.empty())
    {
        return ;
    }
    int num = stack.top();
    stack.pop();
    
    sortStack(stack);
    sortedinsert(stack , num);
}
