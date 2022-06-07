bool canPlaceCow(vector<int>&positions,int n,int c,int mx)
{
    int rooms=1;
    int placed=positions[0];
    for(int i=1;i<n;i++)
    {
        if(positions[i]-placed>=mx)
        {
            rooms++;
            placed=positions[i];
        }
        if(rooms>=c)
            return true;
    }
    return false;
}

int chessTournament(vector<int> v , int n ,  int cows){
    // Write your code here
    sort(v.begin(),v.end());
    int res;
    int l=1,h=v[n-1]-v[0];
    while(l<=h)
    {
        int mid= (l+h)>>1;
        if(canPlaceCow(v,n,cows,mid))
        {
            res=mid;
            l=mid+1;
        }
        else
        {
            h=mid-1;
        }
    }
    return res;
}
