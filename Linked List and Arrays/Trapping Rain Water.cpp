long getTrappedWater(long *arr, int n)
{
	long long lmax=0,rmax=0,ans=0,l=0,r=n-1;
	while(l<r)
	{
		if(arr[l]<=arr[r])
		{
			if(arr[l]>lmax)
			{
				lmax=arr[l];
			}
			else
			{
				ans+= lmax-arr[l];
			}
			l++;
		}
		else
		{
			if(arr[r]>rmax)
			{
				rmax=arr[r];
			}
			else
			{
				ans+=rmax-arr[r];
			}
			r--;
		}
	}
	return ans;
    // Write your code here.
}
