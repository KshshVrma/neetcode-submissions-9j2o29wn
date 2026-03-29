class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i=0;
        int n=matrix.size();
        int m=matrix[0].size();

        int tot=(n*m)-1;
        
        while(i<=tot){
            int mid=(tot+i)/2;

            if(matrix[mid/m][mid%m]==target){
                return true;
            }else if(matrix[mid/m][mid%m]<target){
i=mid+1;
            }else{
                tot=mid-1;
            }
        }


        return false;
    }
};
