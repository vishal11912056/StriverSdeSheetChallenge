int maximumProduct(vector<int> &arr, int n)
{
    int ans=arr[0];
    int mn=arr[0];
    int mx=arr[0];
    for(int i=1;i<n;i++)
    {
        if(arr[i]<0)
        {
            swap(mn,mx);
        }
        mx=max(arr[i],mx*arr[i]);
        mn=min(arr[i],mn*arr[i]);
        ans=max(ans,mx);
    }
    return ans;
	// Write your code here
}
