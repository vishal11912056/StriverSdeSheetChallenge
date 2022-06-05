#include<bits/stdc++.h>
struct Node{
  
  Node* links[2];
  
  bool containsKey(int bit)
  {
      return (links[bit]!=NULL);
  }
  void put(int bit,Node* node)
  {
      links[bit]=node;
  }
  Node* getKey(int bit)
  {
      return links[bit];
  }
};
class Trie
    {
        private:
        Node* root;
        public:
        Trie()
        {
            root=new Node();
        }
        void insert(int num)
        {
            Node* node=root;
            for(int i=31;i>=0;i--)
            {
                int bit= (num>>i)&1;
                if(!node->containsKey(bit))
                {
                    node->put(bit,new Node());
                }
                node=node->getKey(bit);
            }
        }
        int getMax(int num)
        {
            Node* node=root;
            int maxi=0;
            for(int i=31;i>=0;i--)
            {
                int bit= (num>>i)&1;
                if(node->containsKey(1-bit))
                {
                    maxi = maxi | (1<<i);
                    node=node->getKey(1-bit);
                }
                else
                {
                    node=node->getKey(bit);
                }
            }
            return maxi;
             
        }
    };
vector<int> maxXorQueries(vector<int> &nums, vector<vector<int>> &queries)
{
       sort(nums.begin(),nums.end());
        vector<pair<int,pair<int,int>>> oq;
        int q=queries.size();
        for(int i=0;i<q;i++)
        {
            oq.push_back({queries[i][1],{queries[i][0],i}});
        }
        sort(oq.begin(),oq.end());
        
        vector<int> ans(q,0);
        int ind=0;
        int n=nums.size();
        Trie trie;
        for(int i=0;i<q;i++)
        {
            int ai=oq[i].first;
            int xi=oq[i].second.first;
            int qid=oq[i].second.second;
            while(ind< n && nums[ind]<=ai)
            {
                trie.insert(nums[ind]);
                ind++;
            }
            if(ind!=0)
            {
                ans[qid]=trie.getMax(xi);
                
            }
            else
            {
                ans[qid]=-1;
            }
        }
        return ans;
	//	Write your coode here.
}
