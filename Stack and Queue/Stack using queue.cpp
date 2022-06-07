#include<bits/stdc++.h>
class Stack {
	// Define the data members.
    queue<int> q;
    int siz;
   public:
    Stack() {
        siz=-1;
        // Implement the Constructor.
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        return q.size();
        // Implement the getSize() function.
    }

    bool isEmpty() {
       return (q.empty());
        // Implement the isEmpty() function.
    }

    void push(int element) {
          siz++;
       q.push(element);
       for(int i=0;i<siz;i++)
       {
           q.push(q.front());
           q.pop();
       }
        // Implement the push() function.
    }

    int pop() {
        if(!q.empty())
       {
           int popped = q.front();
           q.pop();
           siz--;
           return popped;
       }
       return -1; // Implement the pop() function.
    }

    int top() {
          if(!q.empty())
           return q.front();
       return -1;
        // Implement the top() function.
    }
};
