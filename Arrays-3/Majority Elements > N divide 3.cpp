vector<int> majorityElementII(vector<int> &nums)
{
	vector<int> v;
	int c1=0,c2=0,n1=-1,n2=-1;
	for(int elmnt:nums)
	{
		if(elmnt==n1)
		{
			c1++;
		}
		else if(elmnt==n2)
		{
			c2++;
		}
		else if(c1==0)
		{
			n1=elmnt;
			c1=1;
		}
		else if(c2==0)
		{
			n2=elmnt;
			c2=1;
		}
		else
		{
			c1--;
			c2--;
		}
	}
	int n=nums.size();
	int cnt1=0,cnt2=0;
	for(int i=0;i<n;i++)
	{
		if(nums[i]==n1)
		{
			cnt1++;
		}
		else if(nums[i]==n2)
		{
			cnt2++;
		}
	}
	if(cnt1> n/3)
	{
		v.push_back(n1);
	}
	if(cnt2> n/3)
	{
		v.push_back(n2);
	}
    // Write your code here.
    return v;
}
