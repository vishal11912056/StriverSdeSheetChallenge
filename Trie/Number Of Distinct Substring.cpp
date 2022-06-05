struct Node {
    Node *links[26]; 
    bool flag = false; 
    
    bool containsKey(char ch) {
        return (links[ch - 'a'] != NULL); 
    }
    Node* get(char ch) {
        return links[ch-'a']; 
    }
    void put(char ch, Node* node) {
        links[ch-'a'] = node; 
    }
    void setEnd() {
        flag = true; 
    }
    bool isEnd() {
        return flag; 
    }
}; 

int distinctSubstring(string &word) {
    int cnt=0;
    Node* root= new Node();
    int n=word.size();
    for(int i=0;i<n;i++)
    {
        Node* node=root;
        for(int j=i;j<n;j++)
        {
            if(!node->containsKey(word[j]))
            {
                cnt++;
                node->put(word[j],new Node);
                
            }
            node=node->get(word[j]);
        }
    }
    return cnt;
    //  Write your code here.
}
