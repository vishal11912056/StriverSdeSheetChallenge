#include<bits/stdc++.h>
class LRUCache
{
public:
     class node
    {
        public:
        int key;
        int val;
        node *next;
        node *prev;
        node(int _key,int _val)
        {
            key= _key;
            val= _val;
        }
    };
    node *head = new node(-1,-1);
    node *tail = new node(-1,-1);
    int cap;
    unordered_map<int,node*> mp;
    LRUCache(int capacity) 
    {
        cap=capacity;
        head->next = tail;
        tail->prev = head;
        
    }
    void addnode(node *newnode)
    {
        node *tmp= head->next;
        newnode->next=tmp;
        newnode->prev= head;
        head->next = newnode;
        tmp->prev= newnode; 
    }
    void deletenode(node *delnode)
    {
        // if(delnode!=NULL)
        // {.
            node *delprev= delnode->prev;
            node *delnext= delnode->next;
            delprev->next= delnext;
            delnext->prev = delprev;
        // }
    }

    int get(int _key)
    {
       if(mp.find(_key)!=mp.end())
        {
             node *tmp = mp[_key];
            int valu = tmp->val;
             mp.erase(_key);
            deletenode(tmp);
            addnode(tmp);
           
            mp[_key]=head->next;
            return valu;     
        }
        
            return -1;
    }

    void put(int _key, int value)
    {
        if(mp.find(_key)!=mp.end())
        {
             node *tmp = mp[_key];
            
            // addnode(mp[key]);
            mp.erase(_key);
            deletenode(tmp);
        }
        if(cap==mp.size())
        {
             mp.erase(tail->prev->key);
            deletenode(tail->prev);
            // addnode(mp[key]);
           
        }
        addnode(new node(_key,value));
        mp[_key]=head->next;
        
    }
};
