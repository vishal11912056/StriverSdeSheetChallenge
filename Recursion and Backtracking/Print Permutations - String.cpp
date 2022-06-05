void permu(int idx,string &nums,vector<string> &ans )
    {
        if(idx==nums.size())
        {
            ans.push_back(nums);
            return;
        }
        for(int i=idx;i<nums.size();i++)
        {
               swap(nums[idx],nums[i]);
                permu(idx+1,nums,ans);
                swap(nums[idx],nums[i]);
            
        }
    }
vector<string> findPermutations(string &s) 
{
	 
        vector<string> ans;
        permu(0,s,ans);
        return  ans;
    // Write your code here.
}
