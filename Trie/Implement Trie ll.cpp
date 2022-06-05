struct Node
{
   Node* links[26];
   int cntEndWith = 0;
   int cntPrefix = 0;
  bool containkey(char ch)
   {
      return (links[ch-'a']!=NULL);
   }
   void put(char ch,Node* node)
   {
      links[ch-'a']=node;
   }
   Node* get(char ch)
   {
      return links[ch-'a'];
   }
   void increaseEnd()
   {
      cntEndWith++;
   }
   void increasePrefix()
   {
       cntPrefix++;
   }
   void decreasePrefix()
   {
       cntPrefix--;
   }
   void decreaseEnd()
   {
       cntEndWith--;
   }
   int cntGetEnd()
   {
       return cntEndWith;
   }
   int cntGetPrefix()
   {
       return cntPrefix;
   }
   
};
class Trie{
private:
Node* root;
    public:

    Trie()
    {
        root= new Node();
        // Write your code here.
    }

    void insert(string &word){
        
        Node* node=root;
        for(int i=0;i<word.size();i++)
        {
            if(!node->containkey(word[i]))
            {
                node->put(word[i],new Node);
            }
            node=node->get(word[i]);
            node->increasePrefix();
        }
        node->increaseEnd();
        // Write your code here.
    }

    int countWordsEqualTo(string &word){
        
        Node* node=root;
        for(int i=0;i<word.size();i++)
        {
            if(node->containkey(word[i]))
            {
                node=node->get(word[i]);
            }
            else
            {
                return 0;
            }
        }
        return node->cntGetEnd();
        // Write your code here.
    }

    int countWordsStartingWith(string &word){
        
         Node* node=root;
        for(int i=0;i<word.size();i++)
        {
            if(node->containkey(word[i]))
            {
                node=node->get(word[i]);
            }
            else
            {
                return 0;
            }
        }
        return node->cntGetPrefix();
        // Write your code here.
    }

    void erase(string &word){
        
         Node* node=root;
        for(int i=0;i<word.size();i++)
        {
            if(node->containkey(word[i]))
            {
                node=node->get(word[i]);
                node->decreasePrefix();
            }
            else
            {
                return ;
            }
        }
         node->decreaseEnd();
        // Write your code here.
    }
};
