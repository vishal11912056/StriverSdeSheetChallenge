#include<bits/stdc++.h>
int maximumProfit(vector<int> &prices)
{
	int min1=prices[0];
	int profit=0;
	for(int i=0;i<prices.size();i++)
	{
	    min1= min(min1,prices[i]);
		profit= max(profit,prices[i]-min1);
	}
	return profit;

}
