
struct TrieNode{
    char data;
    TrieNode *child[26];
    int we;
    int wc;
    TrieNode(char ch)
    {
        data=ch;
        we=0;
        wc=0;
        for(int i=0;i<26;i++)
        {
            child[i]=NULL;
        }
    }

};
class PrefixTree {
public:
    
    TrieNode *root;
    PrefixTree() {
        root=new TrieNode('#');
        
        
    }
    
    
    void insert(string word) {
        TrieNode *curr=root;
        for(char ch:word)
        {
            int idx=ch-'a';
            if(curr->child[idx]==NULL)
            {
                curr->child[idx]=new TrieNode(ch);
            }
            curr=curr->child[idx];
            curr->wc++;
        }
        curr->we++;
        
    }
    
    bool search(string word) {
        TrieNode *curr=root;
        for(char ch:word)
        {
            int idx=ch-'a';
            if(curr->child[idx]==NULL)
                return false;
            curr=curr->child[idx];
        }
        return curr->we>0;
        
    }
    
    bool startsWith(string prefix) {
        TrieNode *curr=root;
        for(char ch:prefix)
        {
            int idx=ch-'a';
            if(curr->child[idx]==NULL)
                return false;
            curr=curr->child[idx];
        }
        return true;
        
    }
};
