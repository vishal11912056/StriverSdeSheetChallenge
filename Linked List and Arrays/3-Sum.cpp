vector<vector<int>> findTriplets(vector<int>arr, int n, int k) 
{
	vector<vector<int>> vp;
	if(n<3)
	{
		return vp;
	}
	sort(arr.begin(),arr.end());
	for(int i=0;i<n-2;i++)
	{
		int sum= k-arr[i];
		int l=i+1;
		int h=n-1;
		while(l<h)
		{
			int tmpsum=arr[l]+arr[h];
			if(tmpsum<sum)
			{
				l++;
			}
			else if(tmpsum>sum)
			{
				h--;
			}
			else
			{
				vector<int> v;
				v.push_back(arr[i]);
				v.push_back(arr[l]);
				v.push_back(arr[h]);
				vp.push_back(v);
				while(l<h && arr[l]==v[1]) l++;
				while(l<h && arr[h]==v[2]) h--;
			}
		}
		while(i< n-2 && arr[i+1]==arr[i]) i++;
	}
	return vp;
	// Write your code here.
}
