class Trie{
public:
bool isend;
Trie *chars[26];
Trie(){
    isend=false;
    for(int i=0;i<26;i++){
        chars[i]=NULL;
    }
}
};

class PrefixTree {
public:
Trie *root;
    PrefixTree() {
       root=getTrie();
    }
Trie* getTrie(){
 Trie * ptr=new Trie();
 ptr->isend=false;
 for(int i=0;i<26;i++){
ptr->chars[i]=NULL;
 }
 return ptr;
    }
    
    void insert(string word) {
        Trie* p=root;
        for(int i=0;i<word.size();i++){
            int ch = word[i]-'a';
            if(p->chars[ch]==NULL){
                p->chars[ch]=getTrie();     
            }
            p=p->chars[ch];
        }
        p->isend=true;
    }
    
    bool search(string word) {
         Trie* p=root;
        for(int i=0;i<word.size();i++){
            int ch = word[i]-'a';
            if(p->chars[ch]==NULL){
              return false; 
            }
            p=p->chars[ch];
        }
        return (p!=NULL && p->isend==true);
    }
    
    bool startsWith(string prefix) {
          Trie* p=root;
          int i;
        for( i=0;i<prefix.size();i++){
            int ch = prefix[i]-'a';
            if(p->chars[ch]==NULL){
                return false;    
            }
            p=p->chars[ch];
        }
    if(i==prefix.size())return true;
    return false;
    }
};
