double multiply(int n,double mid)
{
	double x=1.0;
	for(int i=1;i<=n;i++)
	{
		x*=mid;
	}
	return x;
}
double findNthRootOfM(int n, long long m) 
{
	if(n==0)
	{
		return 1.0;
	}
	if(n==1 || m==1)
	{
		return (double)m;
	}
	
	double l=1,h=m+1,eps=1e-9;
	while((h-l)>=eps)
	{
		double mid= (h+l)/2.0;
		if(multiply(n,mid)<m)
		{
			l=mid;
		}
		else
		{
			h=mid;
		}
	}
	return l;
		
	// Write your code here.
}
