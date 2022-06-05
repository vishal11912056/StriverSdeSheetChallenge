int modularExponentiation(int x, int n, int m) 
{
	 int ans=1;
	int nn=n;
// 	if(nn<0)
// 	{
// 		nn= -1*nn;
// 	}
	while(nn)
	{
		if(nn%2 ==0)
		{
			x= (1ll*((x)%m)*((x)%m))%m;
			nn/=2;
		}
		else
		{
			ans= (1ll*ans*((x)%m))%m;
			nn-=1;
		}
	}
	return ans;
	// Write your code here.
}
