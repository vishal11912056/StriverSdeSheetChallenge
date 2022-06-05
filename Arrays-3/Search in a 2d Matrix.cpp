#include<bits/stdc++.h>
bool findTargetInMatrix(vector < vector < int >> & mat, int m, int n, int target) 
{
	int l=0,h=(m*n)-1;
	while(l<=h)
	{
		int mid=  l + ((h-l)>>1);
		if(mat[mid/n][mid%n]==target)
		{
			return true;
		}
		else if(mat[mid/n][mid%n]<target)
		{
			l= mid+1;
		}
		else
		{
			h = mid-1;
		}
	}
	return false;
    // Write your code here.
}
