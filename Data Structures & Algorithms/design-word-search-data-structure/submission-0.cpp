class TrieNode{
    public:
bool isend;
TrieNode *chars[26];
};

class WordDictionary {
public:
TrieNode *root;
TrieNode * getNode(){
    TrieNode *ptr=new TrieNode;
    ptr->isend=false;
    for(int i=0;i<26;i++){
        ptr->chars[i]=NULL;
    }
    return ptr;
}
    WordDictionary() {
        root=getNode();
    }
    
    void addWord(string word) {
        TrieNode *p=root;
        for(int i=0;i<word.size();i++){
            int ch=word[i]-'a';
            if(p->chars[ch]==NULL){
                p->chars[ch]=getNode();
            }
            p=p->chars[ch];
        }
        p->isend=true;
    }

    bool searchUtil(string word, TrieNode* rooted){
  TrieNode *p=rooted;
        for(int i=0;i<word.size();i++){
            int ch=word[i]-'a';
            char c=word[i];
            if(c=='.'){

                for(int j=0;j<26;j++){
                    if(p->chars[j]!= NULL)
                    if(searchUtil(word.substr(i+1), p->chars[j]))return true;
                }
                return false;

            }
            else if(p->chars[ch]==NULL){
                return false;
            }
            p=p->chars[ch];
        }
        return (p!=NULL && p->isend==true);
    }
    
    bool search(string word) {
                 TrieNode *p=root;
       return searchUtil(word, p);
    }
};
