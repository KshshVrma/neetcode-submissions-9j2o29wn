class Solution {
public:
bool check(int row, int col, vector<string>&grid){

    //up
    for(int i=row-1;i>=0;i--){
        if(grid[i][col]=='Q')return false;
    }
    //up-left
    for(int i=row-1,  j=col-1;i>=0 && j>=0; i--, j--){
        if(grid[i][j]=='Q')return false;
    }
    //up-right
    for(int i=row-1,  j=col+1;i>=0 && j<grid.size(); i--, j++){
        if(grid[i][j]=='Q')return false;
    }
    return true;
}
void fun(vector<vector<string>>&ans, vector<string>&grid, int row, int n){
    if(row>=n){
        ans.push_back(grid);
        return ;
    }
    for(int col=0;col<n;col++){
        grid[row][col]='Q';
        if(check(row, col, grid))
        fun(ans, grid, row+1, n );
        grid[row][col]='.';
    }
}
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string>grid(n, string(n, '.'));
        fun(ans, grid, 0, n);
        return ans;
    }
};
