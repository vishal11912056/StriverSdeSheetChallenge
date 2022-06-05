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
    int maximumXor(vector<int>& arr) 
    {
        int n=arr.size();
         Trie trie;
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            trie.insert(arr[i]);
        }
        for(int i=0;i<n;i++)
        {
            maxi = max(maxi,trie.getMax(arr[i]));
        }
        return maxi;
        
        
    }
