int findMinimumCoins(int amount) 
{
	int arr[]={1, 2, 5, 10, 20, 50, 100, 500, 1000};
	int n=sizeof(arr)/sizeof(arr[0]);
	int ans=0;
	for(int i=n-1;i>=0;i--)
	{
		while(amount>=arr[i])
		{
			ans++;
			amount-=arr[i];
		}
		if(amount<=0)
		{
			break;
		}
	}
	return ans;
    // Write your code here
}

