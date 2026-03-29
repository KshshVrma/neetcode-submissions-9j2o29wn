class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int ans=heights[0];

        int i=0;
        while(i<heights.size()){
            
            int j=i-1;
            int k=i+1;
             int left=i,right=i;
            int curr=heights[i];
            while(j>=0 && heights[j]>=curr){
                j--;
            }
           
            if(j==-1){
left=0;
            }else{
                left=j+1;
            }

            while(k<heights.size() && heights[k]>=curr){
                k++;
            }
           
            if(k==heights.size()){
right=heights.size()-1;
            }else{
                right=k-1;
            }
            ans=max(ans,max(curr, (right-left+1)*curr));
            i++;
        }
        return ans;
    }
};
