vector<int> nextPermutation(vector<int> &arr, int n)
{
	int i=n-2;
	while(i>=0 && arr[i+1]<=arr[i])
	{
		i--;
	}
	if(i>=0)
	{
		int j=n-1;
		while(j>=0 && arr[j]<=arr[i])
		{
			j--;
		}
		swap(arr[i],arr[j]);
	}
	int l=i+1,h=n-1;
	while(l<h)
	{
		swap(arr[l],arr[h]);
		l++;
		h--;
	}
	return arr;
}
