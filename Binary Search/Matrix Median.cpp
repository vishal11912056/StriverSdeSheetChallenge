#include<bits/stdc++.h>
int binsrch(vector<int> &v,int x)
{
    int left= 0;
    int right= v.size()-1;
    while(left<=right)
    {
        int mid = (right+left)>>1;
        if(v[mid]<=x)
        {
            left=mid+1;
        }
        else
        {
            right=mid-1;
        }
    }
    return left;
}
int getMedian(vector<vector<int>> &A)
{
	 int low=0;
    int high= INT_MAX;
    int n=A.size();
    int m=A[0].size();
    while(low<=high)
    {
        int mid = (low+high)>>1;
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            cnt+= binsrch(A[i],mid);
        }
        if(cnt <= (n*m)/2)
        {
            low= mid+1;
        }
        else
        {
            high= mid-1;
        }
        
    }
    return low;
    // Write your code here.
}
