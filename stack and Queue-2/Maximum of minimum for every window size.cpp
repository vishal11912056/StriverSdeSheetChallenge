#include<bits/stdc++.h>
vector<int> prevsmlr(vector<int> a,int n)
{
    vector<int> v(n);
    stack<int> st;
    for(int i=0;i<n;i++)
    {
        while(!st.empty() && a[i]<=a[st.top()])
        {
            st.pop();
        }
        if(st.empty())
        {
            v[i]=-1;
        }
        else
        {
            v[i]=st.top();
        }
        st.push(i);
    }
    return v;
}
vector<int> nxtsmlr(vector<int> a,int n)
{
    vector<int> v(n);
    stack<int> st;
    for(int i=n-1;i>=0;i--)
    {
        while(!st.empty() && a[i]<=a[st.top()])
        {
            st.pop();
        }
        if(st.empty())
        {
            v[i]=n;
        }
        else
        {
            v[i]=st.top();
        }
        st.push(i);
    }
    return v;
}
vector<int> range(vector<int> a, int n)
{
    vector<int> v(n,INT_MIN),nxt,prev;
    prev=prevsmlr(a,n);
    nxt=nxtsmlr(a,n);
    for(int i=0;i<n;i++)
    {
        v[nxt[i]-prev[i]-2] = max(v[nxt[i]-prev[i]-2],a[i]);
    }
    for(int i=n-2;i>=0;i--)
    {
        if(v[i]<v[i+1])
        {
            v[i]=v[i+1];
        }
    }
    return v;
}
vector<int> maxMinWindow(vector<int> a, int n) 
{
    return range(a,n);
    // Write your code here.
}
