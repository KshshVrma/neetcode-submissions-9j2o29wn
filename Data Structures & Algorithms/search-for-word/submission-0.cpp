class Solution {
public:

bool fun(vector<vector<char>>&board, int i, int j, string word, int ind){
    int delr[4]={0, -1, 0, 1};
    int delc[4]={-1, 0, 1, 0};
    if(ind==word.size())return true;

    if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || ind >=word.size())return false;
    if(board[i][j]!=word[ind])return false;
    // cout<<i<<" "<<j<<"|"<<word[ind]<<" | "<<endl;

char c=board[i][j];
    board[i][j]='%';
    for(int k=0;k<4;k++){
        if(fun(board, delr[k]+i, delc[k]+j, word, ind+1))return true;
    }
    board[i][j]=c;

    return false;
    
}
    bool exist(vector<vector<char>>& board, string word) {
    

    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[i].size();j++){
            if(board[i][j]==word[0]){
                if(fun(board, i, j, word, 0)){
                    return true;
                }
            }
        }
    }

    return false;
    }
};
