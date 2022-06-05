long long int merge(long long int arr[],long long int tmp[],long long int l,long long int mid,long long int h)
{
   long long int inv_cnt=0;
   long long int i=l;
   long long int j=mid;
   long long int k=l;
    while((i<=mid-1)&& (j<=h) )
    {
        if(arr[i]<=arr[j])
        {
            tmp[k++]=arr[i++];
        }
        else
        {
            tmp[k++]=arr[j++];
                inv_cnt+=(mid-i);
        }
    }
    while(i<=(mid-1))
    {
        tmp[k++]=arr[i++];
    }
    while(j<=h)
    {
        tmp[k++]=arr[j++];
    }
    for(int x=l;x<=h;x++)
    {
        arr[x]=tmp[x];
    }
    return inv_cnt;
}
long long int mergesort(long long int arr[],long long int tmp[],long long int l,long long int h)
{
    long long int mid;
   long long int inv_cnt=0;
    if(h>l)
    {
       mid= (h+l)/2;
        inv_cnt+=mergesort(arr,tmp,l,mid);
        inv_cnt+=mergesort(arr,tmp,mid+1,h);
        inv_cnt+=merge(arr,tmp,l,mid+1,h);
    }
    return inv_cnt;
}
long long getInversions(long long *arr, int n)
{
    long long int tmp[n];
    return mergesort(arr,tmp,0,n-1);
 
}
