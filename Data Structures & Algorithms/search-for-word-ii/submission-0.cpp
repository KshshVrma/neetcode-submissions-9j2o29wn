class TrieNode{
public:
bool isend;
string word;
TrieNode *child[26];
};


class Solution {
public:

TrieNode* getNode(){
    TrieNode * ptr=new TrieNode();
    ptr->isend=false;
    ptr->word="";
    for(int i=0;i<26;i++){
        ptr->child[i]=NULL;
    }
    return ptr;
}

void insert(TrieNode*root, string &word){
    TrieNode* ptr=root;
    for(int i=0;i<word.size();i++){
        int c=word[i]-'a';
        if(ptr->child[c]==NULL){
            ptr->child[c]=getNode();
        }
        ptr=ptr->child[c];

    }
    ptr->isend=true;
    ptr->word=word;
}

vector<string>ans;

void fun(TrieNode* root, int i, int j, vector<vector<char>>&word){
if(i<0|| j<0 || i>=word.size() || j>=word[0].size()){
return ;
}
if(word[i][j]=='%' || root->child[word[i][j]-'a']==NULL)return;

root=root->child[word[i][j]-'a'];
if(root->isend){
    ans.push_back(root->word);
    root->isend=false;
}

int delr[4]={0,-1,0,1};
int delc[4]={-1,0,1,0};
char c=word[i][j];
word[i][j]='%';
for(int it=0;it<4;it++){
int newr=i+delr[it];
int newc=j+delc[it];
fun(root, newr, newc, word);
}
word[i][j]=c;

}

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
TrieNode* root=getNode();
for(int i=0;i<words.size();i++){
    insert(root, words[i]);
}

for(int i=0;i<board.size();i++){
    for(int j=0;j<board[i].size();j++){
        if(root->child[board[i][j]-'a']  !=NULL){
            fun(root, i, j, board);
        }
    }
}
        return ans;
    }
};
