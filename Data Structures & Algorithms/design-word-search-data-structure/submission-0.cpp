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

class WordDictionary {
public:
    TrieNode *root;
    WordDictionary() {
        root=new TrieNode('#');
        
    }
    
    void addWord(string word) {
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
    bool searchHelper(TrieNode* curr, string& word, int pos)
{
    if(pos == word.size())
        return curr->we > 0;

    char ch = word[pos];

    if(ch == '.')
    {
        for(int i = 0; i < 26; i++)
        {
            if(curr->child[i] != NULL)
            {
                if(searchHelper(curr->child[i], word, pos + 1))
                    return true;
            }
        }

        return false;
    }

    int idx = ch - 'a';

    if(curr->child[idx] == NULL)
        return false;

    return searchHelper(curr->child[idx], word, pos + 1);
}
    
    bool search(string word) {
        
        return searchHelper(root,word,0);
        
    }
};
