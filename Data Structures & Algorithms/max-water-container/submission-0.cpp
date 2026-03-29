class Solution {
public:
    int maxArea(vector<int>& heights) {
        
        int maxi=0;
        for(int i=0;i<heights.size();i++){
            for(int j=i+1;j<heights.size();j++){
                int curr=min(heights[i], heights[j])*(j-i);
                if(maxi<curr)maxi=curr;
            }
        }
        return maxi;
    }
};
