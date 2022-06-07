#include<bits/stdc++.h>
int atoi(string str) 
    {
         long long ans=0;
    int n=str.length();
    int i=0;
    int pos=1;             // for marking positive or neagtive number
    
      if(str[i]=='-')               // check if neg then make -1;
        {
            
            pos=-1;    
            i++;
        }
    
    for(int i=0;i<n;i++)
    {
       if( str[i]>='0' && str[i]<='9')           // iterate only for numbers
       {
        ans=ans*10;
        ans=ans+(str[i]-'0');
       }
    }
    return ans*pos;
    }
