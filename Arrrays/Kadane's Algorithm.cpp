#include<bits/stdc++.h>
long long maxSubarraySum(int arr[], int n)
{
	long long int max_so_far= INT_MIN;
     long long   int max_end=0;
        for(int i=0;i<n;i++)
        {
            max_end+=arr[i];
            if(max_end>max_so_far)
            {
                max_so_far=max_end;
            }
            if(max_end<0)
            {
                max_end=0;
            }
        }
	if(max_so_far<0)
        return 0;
	return max_so_far;
  
}
