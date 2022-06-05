#include<bits/stdc++.h>
int findMajorityElement(int arr[], int n) 
{
	int cnt=0,elmnt;
	for(int i=0;i<n;i++)
	{
		int num=arr[i];
		if(cnt==0)
		{
			elmnt=num;
		}
		if(elmnt==num)
		{
			cnt++;
		}
		else
		{
			cnt--;
		}
	}
	cnt=0;
	for(int i=0;i<n;i++)
	{
		if(arr[i]==elmnt)
		{
			cnt++;
		}
	}
	if(cnt>n/2)
	{
		return elmnt;
	}
	return -1;
	// Write your code here.
}
