vector<int> Solution::dNums(vector<int> &A, int B) 
{
    vector<int> v;
    unordered_map<int,int> mp;
    int i;
    for(i=0;i<(B);i++)
    {
        mp[A[i]]++;
    }
    v.push_back(mp.size());
    for(i=B;i<A.size();i++)
    {
         mp[A[i-B]]--;
         if(mp[A[i-B]]==0)
         {
             mp.erase(A[i-B]);
         }
         mp[A[i]]++;
        v.push_back(mp.size());
        
    }
    return v;
}
