#include<bits/stdc++.h>
int calculateMinPatforms(int at[], int dt[], int n) 
{
    // Write your code here.
	sort(at,at+n);
	sort(dt,dt+n);
	int plat_need=1,res=1;
	int i=1,j=0;
	while(i<n && j<n)
	{
		if(at[i]<=dt[j])
		{
			plat_need++;
			i++;
		}
		else
		{
			plat_need--;
			j++;
		}
		res=max(res,plat_need);
	}
	return res;
}
