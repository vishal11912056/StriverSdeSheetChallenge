 void f(int idx,vector<int> &arr,int n, vector<int> &v, int sum)
    {
        if(idx==n)
        {
            v.push_back(sum);
            return;
        }
        f(idx+1,arr,n,v,sum);
        f(idx+1,arr,n,v,sum+arr[idx]);
    }
vector<int> subsetSum(vector<int> &arr)
{
    int n=arr.size();
     vector<int> v;
        f(0,arr,n,v,0);
        sort(v.begin(),v.end());
        return v;
}
