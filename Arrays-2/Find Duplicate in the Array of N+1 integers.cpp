int findDuplicate(vector<int> &arr, int n)
{
	int slw=arr[0],fst=arr[0];
	do
	{
	    slw=arr[slw];
		fst= arr[arr[fst]];
	}while(slw!=fst);
	fst=arr[0];
	while(slw!=fst)
	{
		slw=arr[slw];
		fst=arr[fst];
	}
	return slw;
	// Write your code here.
}
