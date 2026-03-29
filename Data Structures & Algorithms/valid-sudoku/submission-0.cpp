class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
       for(int i=0;i<9;i++){
        unordered_set<char>st;
        for(int j=0;j<9;j++){
            if(st.find(board[i][j])!=st.end()){
                return false;
            }else{
                if(board[i][j]!='.'){
                    st.insert(board[i][j]);
                }
            }
        }
       } 

       for(int i=0;i<9;i++){
        unordered_set<char>st;
        for(int j=0;j<9;j++){
            if(st.find(board[j][i])!=st.end()){
                return false;
            }else{
                if(board[j][i]!='.'){
                    st.insert(board[j][i]);
                }
            }
        }
       } 

       for(int i=0;i<9;i+=3){
  
        for(int j=0;j<9;j+=3){
                  unordered_set<char>st;

            for(int x=0;x<3;x++){
                for(int y=0;y<3;y++){
                    int row=i+x;
                    int col=j+y;
                        if(st.find(board[row][col])!=st.end()){
                            return false;
                        }else{
                         if(board[row][col]!='.'){
                            st.insert(board[row][col]);
                        }
            }
                }
            }
           
        }
       } 

       return true;
    }
};
